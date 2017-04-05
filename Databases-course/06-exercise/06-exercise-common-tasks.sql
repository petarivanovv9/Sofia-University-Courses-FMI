-- common tasks

use movies;
-- 1. Без повторение заглавията и годините на всички филми, заснети преди 1982, в които е играл
-- поне един актьор (актриса), чието име не съдържа нито буквата 'k', нито 'b'. 
-- Първо да се изведат най-старите филми
select distinct movietitle, movieyear
from starsin
where movieyear < 1982 
	and starname not like '%k%' 
	and starname not like '%b%'
group by movietitle, movieyear
having count(starname) >= 1
order by movieyear ASC;

-- 2. Заглавията и дължините в часове (length е в минути) на всички филми, които са от същата
-- година, от която е и филмът Terms of Endearment, но дължината им е по-малка или неизвестна
select title, length / 60 as hours
from movie
where year = (select distinct year from movie where title = 'Terms of Endearment')
	and length < (select distinct length from movie where title = 'Terms of Endearment');

-- 3. Имената на всички продуценти, които са и филмови звезди и са играли 
-- в поне един филм преди 1980 г. и поне един след 1985 г
select name
from movieexec
join movie on cert# = producerc#
join starsin on title = movietitle and year = movieyear
where name in (select starname from starsin)
	and name in (select distinct starname 
					from starsin
					where movieyear < 1980)
	and name in (select distinct starname 
					from starsin
					where movieyear > 1985);

select name
from movieexec
join movie on cert# = producerc#
join starsin on title = movietitle and year = movieyear
where name in (select distinct s1.starname
				from starsin s1
				join starsin s2 on s1.movieyear < 1980
					and s2.movieyear > 1985
				where s1.starname = s2.starname);

-- 4.  Всички черно-бели филми, записани преди най-стария цветен филм 
-- (InColor='y'/'n') на същото студио
select title
from movie
where incolor = 'N' 
		and year < (select min(year)
					from movie
					where incolor = 'Y')
		and studioname = (select studioname
							from movie
							where year = (select min(year)
											from movie
											where incolor = 'Y'));

select m1.title
from movie m1
join movie m2 on m1.studioname = m2.studioname
where m1.incolor = 'N' and m2.incolor = 'Y'
group by m1.title, m1.year
having m1.year < (select min(year)
					from movie
					where incolor = 'Y');

-- 5. Имената и адресите на студиата, които са работили с по-малко от 5 различни филмови звезди. 
-- Студиа, за които няма посочени филми или има, но не се знае кои актьори са играли в тях,  също да бъдат изведени. 
-- Първо да се изведат студиата, работили с най-много звезди.
select name, address, count(starname)
from studio
left join movie on name = studioname
left join starsin on year = movieyear and title = movietitle
group by name, address
having count(starname) < 5
order by count(starname) DESC;

use ships;
-- 6. За всеки кораб, който е от клас с име, несъдържащо буквите i и k, да се изведе името
-- на кораба и през коя година е пуснат на вода (launched). Резултатът да бъде сортиран
-- така, че първо да се извеждат най-скоро пуснатите кораби.
select name, launched
from ships
where name not like '%i%' and name not like '%k%'
order by launched DESC;

-- 7. Да се изведат имената на всички битки, в които е повреден (damaged) 
-- поне един японски кораб
select battle, country, result
from outcomes
join ships s on ship = name
join classes c on s.class = c.class
where country = 'Japan' and result = 'damaged';

-- 8. Да се изведат имената и класовете на всички кораби, пуснати на вода 
-- една година след кораба 'Rodney' и броят на оръдията им е по-голям от 
-- средния брой оръдия на класовете, произвеждани от тяхната страна
select name, s.class
from ships s
join classes c on s.class = c.class 
where launched > 1 + (select distinct launched 
						from ships where name = 'Rodney')
	and numguns > (select avg(numguns) from classes);

-- 9. Да се изведат американските класове, за които всички техни кораби са пуснати на вода
-- в рамките на поне 10 години (например кораби от клас North Carolina са пускани в
-- периода от 1911 до 1941, което е повече от 10 години, докато кораби от клас Tennessee
-- са пуснати само през 1920 и 1921 г.)
select c.class
from classes c
join ships s on c.class = s.class
where country = 'USA';

select class, period
from (select s1.class, max(s2.launched) - min(s1.launched) as period
		from ships s1
		join ships s2 on s1.class = s2.class and s1.launched < s2.launched
		join classes c on s1.class = c.class
		where country = 'USA'
		group by s1.class) new
where period > 10;

select s1.class, max(s2.launched) - min(s1.launched) as period
from ships s1
join ships s2 on s1.class = s2.class and s1.launched < s2.launched
join classes c on s1.class = c.class
where country = 'USA'
group by s1.class

-- 10.  За всяка битка да се изведе средният брой кораби от една и съща държава (например в
-- битката при Guadalcanal са участвали 3 американски и един японски кораб, т.е.
-- средният брой е 2)
select battle, count(distinct country) as numCountries
from outcomes
join ships s on ship = s.name
join classes c on s.class = c.class
group by battle;

select battle, country, count(ship) as numShips
from outcomes
join ships s on ship = s.name
join classes c on s.class = c.class
group by battle, country;

select battle, cast(sum(numShips) as float) / cast(count(country) as float)
from (select battle, country, count(ship) as numShips
		from outcomes
		join ships s on ship = s.name
		join classes c on s.class = c.class
		group by battle, country) new
group by battle;

-- 19.(*) За всеки кораб намерете броя на битките, в които е бил увреден. Ако корабът не е
-- участвал в битки или пък никога не е бил увреждан, в резултата да се вписва 0
select name, count(battle) as numBattles
from ships
left join outcomes on name = ship
where result = 'damaged'
group by name;

select name, count(o1.battle) numBattles, count(o2.battle) damagedNumBattles
from ships
left join outcomes o1 on name = o1.ship
left join outcomes o2 on o1.ship = o2.ship 
	and o1.battle = o2.battle and o2.result = 'damaged'
group by name;

-- 20.(*) Намерете за всеки клас с поне 3 кораба броя на корабите от този клас, 
-- които са победили в битка
select distinct class, name
from outcomes
join ships on ship = name
where result = 'ok' 
	and class in (select class
					from ships
					group by class
					having count(name) >= 3);

select s.name, t.class
from (select class
					from ships
					group by class
					having count(name) >= 3) t
join ships s on s.class = t.class
join outcomes o on s.name = o.ship and o.result = 'ok';

-- 18. Имената на класовете, за които няма кораб, пуснат на вода след 1921 г., 
-- но имат пуснат поне един кораб






select * from ships;
select * from outcomes;
select * from classes;

