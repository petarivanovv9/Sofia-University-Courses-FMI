use movies;

-- всички филми, които са по-дълги от Star Wars
select title
from movie
where length > (select length 
				from movie 
				where title = 'Star Wars');

-- оператор IN:
-- всички филми, които са снимани през 1980, 1985 и 1990 г.:
select *
from movie
where year in (1980, 1985, 1990);

-- участията на всички актьори мъже във филми:
select *
from starsin
where starname in (select name from moviestar where gender = 'M');
-- еквивалентно на
select starsin.*
from starsin
join moviestar on starsin.starname = moviestar.name
where moviestar.gender = 'M';


-- task 1

-- 1.1 извежда имената на актрисите, които са също и
-- продуценти с нетна стойност по-голяма от 10 милиона
select name
from moviestar
where gender='F' and name in (select name from movieexec where networth > 10000000);

-- 1.2 извежда имената на тези актьори (мъже и жени), които не са продуценти
select name
from moviestar
where name not in (select name from movieexec);

-- 1.3 извежда имената на всички филми с дължина по-голяма
-- от дължината на филма ‘Gone With the Wind’
select title
from movie
where length > (select length from movie where title = 'Gone With the Wind');

-- 1.4 извежда имената на продуцентите и имената на
-- продукциите за които стойността им е по-голяма от продукциите на продуценти ‘Mery Griffin’
select me.name, m.title
from movie m
join movieexec me on m.producerc# = me.cert#
where me.networth > (select networth from movieexec where name = 'Merv Griffin');


-- Да се изведат имената на всички актьори, които са играли във филм след 
-- навършване на 40-годишна възраст. Решете задачата по два начина - с JOIN 
-- и с подзаявка.
select name
from moviestar
where name in (select starname from starsin 
				where moviestar.name = starname
					and movieyear >= year(moviestar.birthdate) + 40);

select name from moviestar
where exists (select 1 
		from starsin 
		where moviestar.name=starname and movieyear >= year(moviestar.birthdate) + 40);

select m.name
from moviestar m
join starsin s on m.name = s.starname
where movieyear >= year(m.birthdate) + 40;
