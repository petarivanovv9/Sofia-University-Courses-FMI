-- task 1
use pc;

-- 1.1 извежда средната честота на компютрите
select avg(speed)
from pc;

-- 1.2 извежда средния размер на екраните на лаптопите за всеки производител
select maker, avg(screen)
from product p
join laptop l on p.model = l.model
group by maker;

-- 1.3 извежда средната честота на лаптопите с цена над 1000
select avg(price)
from laptop
where price > 1000;

-- 1.4 извежда средната цена на компютрите произведени от производител ‘A’
select avg(price)
from product p
join pc on p.model = pc.model
where p.maker = 'A'; 

-- 1.5 извежда средната цена на компютрите и лаптопите за производител ‘B’
select avg(price)
from (select price
		from product p
		join pc on p.model = pc.model
		where p.maker = 'B'
		union all
		select price
		from product p
		join laptop l on p.model = l.model
		where p.maker = 'B') AllPrices;

-- 1.6 извежда средната цена на компютрите според различните им честоти
select speed, avg(price)
from pc
group by speed;

-- 1.7 извежда производителите, които са произвели поне по 3
-- различни модела компютъра
select maker
from product
where type='PC'
group by maker
having count(*) >= 3;

-- 1.8 извежда производителите на компютрите с най-висока цена
select maker
from product p
join pc on p.model = pc.model
where pc.price = (select max(price) from pc);

-- 1.9 извежда средната цена на компютрите за всяка честота
-- по-голяма от 800
select speed, avg(price)
from pc
where speed > 800
group by speed;

-- 1.10 извежда средния размер на диска на тези компютри
-- произведени от производители, които произвеждат и принтери
select avg(hd)
from product p
join pc on p.model = pc.model
where p.maker in (select maker from product where type = 'Printer'); 

-- 1.11 за всеки размер на лаптоп намира разликата в цената на
-- най-скъпия и най-евтиния лаптоп със същия размер
select l.screen, max(l.price) - min(l2.price)
from laptop l
join laptop l2 on l.screen = l2.screen
group by l.screen;

select screen, max(price) - min(price)
from laptop
group by screen;

