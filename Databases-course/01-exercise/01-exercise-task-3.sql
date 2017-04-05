-- task 3
use ships;

select class, country
from classes
where numguns < 10;

select name as shipName
from ships
where launched < 19181;

select ship, name
from outcomes, battles
where result='sunk';

select name
from ships
where name=class;

select name
from ships
where name like 'R%';

select name
from ships
where name like '% %' and name not like '% % %';