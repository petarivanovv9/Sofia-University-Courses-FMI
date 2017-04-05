-- пример за full join
-- за всеки актьор и/или продуцент да се изведе 
-- името му, рождената му дата и networth

-- неудобен начин:
select ms.name, me.name, ms.birthdate, me.networth
from moviestar ms
full join movieexec me on ms.name = me.name;
-- хубав начин:
select coalesce(ms.name, me.name) as name, ms.birthdate, me.networth
from moviestar ms
full join movieexec me on ms.name = me.name;

-- task 1
use movies;

-- 1.1 за всеки филм, по-дълъг от 120 минути, извежда
-- заглавие, година, име и адрес на студио
select title, year, name, address
from movie
join studio on studioname = name
where length > 120;

-- 1.2 извежда името на студиото и имената на актьорите,
-- участвали във филми, произведени от това студио, подредени по име на студио
select distinct studioname, starname
from movie
join starsin on title = movietitle and year = movieyear
order by studioname ASC;

select distinct name, starname
from studio
join movie on name = studioname
join starsin on title = movietitle
order by name ASC;

-- 1.3


-- 1.4


-- 1.5


-- 1.6 извежда имената на актьорите не участвали в нито един филм
select name
from moviestar
where name not in (select distinct starname from starsin);
-- OR:
select name
from moviestar
left join starsin on name = starname
where starname is null;
