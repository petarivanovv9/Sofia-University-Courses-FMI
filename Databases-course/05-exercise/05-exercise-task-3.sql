-- tasks

use movies;
-- 1. За всеки актьор/актриса изведете броя на различните студиа, с които са записвали филми.
select starname, count(distinct studioname)
from starsin
join movie on movietitle = title and movieyear = year
group by starname;

-- 2. За всеки актьор/актриса изведете броя на 
-- различните студиа, с които са записвали филми, 
-- включително и за тези, за които нямаме информация в 
-- кои филми са играли.
select name, count(distinct studioname)
from movie
join starsin on title = movietitle and year = movieyear
right join moviestar on starname = name
group by name;

-- OR:
select name, count(distinct studioname)
from moviestar
left join starsin on name=starname
left join movie on movietitle=title and movieyear=year
group by name;

-- 3. Изведете имената на актьорите, участвали в поне 
-- три филма след 1990 г.
select starname
from starsin
where movieyear > 1990
group by starname
having count(*) >= 3;

use pc;
-- 4. Да се изведат различните модели компютри, 
-- подредени по цена на най-скъпия конкретен компютър 
-- от даден модел.
select model
from pc
group by model
order by max(price) DESC;