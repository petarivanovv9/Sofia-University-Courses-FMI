-- task 2
use pc;

select model, speed as MHz, hd as GB
from pc
where price < 1200;

select model, price * 1.1 as PriceEuro
from laptop
order by price ASC;

select model, ram, screen
from laptop
where price > 1000;

select *
from printer
where color='Y';

select model, speed, hd
from pc
where (cd='16x' or cd='12x') and price < 1200;

select code, model, speed + ram + 10*screen as rating
from laptop
order by rating DESC, code;