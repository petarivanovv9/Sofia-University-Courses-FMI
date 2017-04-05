-- task 2
use pc;

-- 2.1 извежда производителите на персонални компютри с честота поне 500
select distinct maker
from product
where model in (select model from pc where speed >= 500);

-- 2.2 извежда принтерите с най-висока цена
select *
from printer
where price >= all (select price from printer);

-- точно един принтер с най-висока цена
select top 1 *
from printer
order by price DESC;

-- понеже сортирането е бавно, вторият пример може да се запише така:
select top 1 *
from printer
where price >= all (select price from printer);

-- 2.3 извежда лаптопите, чиято честота е по-ниска от
-- честотата на който и да е персонален компютър
select *
from laptop
where speed < all (select speed from pc); -- all - по-бавни от всички компютри
-- any - по-бавни от поне един комп.

-- 2.4 извежда модела на продукта (PC, лап топ или принтер) с най-висока цена
select distinct model
from (select model, price from pc
		union all
		select model, price from laptop
		union all
		select model, price from printer) as AllProducts
where price >= all (select price from pc
					union all
					select price from laptop
					union all
					select price from printer);

-- 2.5 извежда производителя на цветния принтер с най-ниска цена
select distinct maker
from product
where model in (select model from printer 
				where color='y' and price <= all (select price from printer where color='y'));

-- 2.6 извежда производителите на тези персонални компютри
-- с най-малко RAM памет, които имат най-бързи процесори
select maker
from product
where model in (select model 
				from pc
				where ram <= all (select ram from pc) 
					and speed >= all (select speed 
										from pc 
										where ram <= all (select ram from pc)));
