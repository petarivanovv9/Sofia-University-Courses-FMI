-- task 2
use ships;

-- 2.1 извежда броя на класовете кораби
select count(*)
from classes;

-- 2.2 извежда средния брой на оръжия за всички кораби, пуснати на вода
select avg(numguns)
from classes c
join ships s on c.class = s.class;

-- 2.3 извежда за всеки клас първата и последната година, в
-- която кораб от съответния клас е пуснат на вода
select c.class, min(launched), max(launched)
from classes c
join ships s on c.class = s.class
group by c.class;

select class, min(launched) as FirstYear, 
			max(launched) as LastYear
from ships
group by class;

-- 2.4 извежда броя на корабите потънали в битка според класа
select class, count(*)
from outcomes o
join ships on ship = name
where result = 'sunk'
group by class;

-- 2.5 извежда броя на корабите потънали в битка според
-- класа, за тези класове с повече от 4 пуснати на вода кораба
select class, count(name)
from outcomes o
join ships s on o.ship = s.name
where o.result = 'sunk' and class in (select class
										from ships
										group by class
										having count(*) > 4)
group by class;

select class, count(*)
from ships
group by class
having count(*) > 4;

-- 2.6 извежда средното тегло на корабите, за всяка страна


