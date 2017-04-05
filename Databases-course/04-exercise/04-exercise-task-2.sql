-- task 2
use pc;

-- 2.1 извежда производител, модел и тип на продукт за тези
-- производители, за които съответния продукт не се продава (няма го в таблиците
-- PC, лаптоп или принтер)
select distinct p.maker, p.model, p.type
from product p
where p.model not in (select model from laptop)
	and p.model not in (select model from pc)
	and p.model not in (select model from printer);
-- OR:
select p.maker, p.model, p.type, t.model
from product p
left join (select model from pc
			union all
			select model from laptop
			union all
			select model from printer) t
		on p.model = t.model
where t.model is null;