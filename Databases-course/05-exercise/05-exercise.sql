-- intro
use movies;

select avg(networth)
from movieexec;

select count(*)
from starsin;

select count(distinct starname)
from starsin;

select count(*), count(distinct starname)
from starsin;

select studioname, sum(length)
from movie
group by studioname;

-- ако нямаше GROUP BY, можеше така:
select distinct studioname, (select sum(length)
								from movie
								where studioname = m.studioname)
from movie m;

-- най-дългият филм (ако са повече от един, да се изведат всички):
select *
from movie
where length = (select max(length) from movie);

-- Групиране по израз:
-- За всяка година да се изведе колко филмови звезди са родени
select year(birthdate), count(*)
from moviestar
group by year(birthdate)

-- за всяка филмова звезда - броят на филмите, в които се е снимала
-- ако за дадена звезда не знаем какви филми има, за нея да се изведе 0
select name, count(starname) as moviesCount
from moviestar
left join starsin on name = starname
group by name

-- да се изведе средният брой филми, в
-- които са се снимали актьорите
select avg(moviesCount)
from (select count(movietitle) as moviesCount
		from moviestar
		left join starsin on name = starname
		group by name) stat;

select max(length) from movie;
select length from movie;