-- task 3
use ships;

-- 3.1


-- 3.2


-- 3.3


-- 3.4



-- За всеки клас британски кораби да се изведат 
-- имената им (на класовете) и имената на всички битки,
-- в които са участвали кораби от този клас.
-- Ако даден клас няма кораби или има, но те не са 
-- участвали в битка, също да се изведат (със стойност
-- NULL за име на битката).

-- почти е вярно
select c.class, battle
from classes c
join ships s on c.class = s.class
join outcomes o on o.ship = s.name
where c.country = 'Gt.Britain';

-- вярно
select c.class, battle
from classes c
left join (select * from ships
			join outcomes on name = ship) t
		on c.class = t.class
where c.country = 'Gt.Britain';

-- вярно
select c.class, battle
from outcomes o
join ships s on o.ship = s.name
right join classes c on s.class = c.class 
where c.country = 'Gt.Britain';


-- За всеки клас да се изведат името му, държавата 
-- и имената на всички негови кораби, пуснати през 1916 г.



-- Да допълним горната задача, като добавим и класовете,
-- които нямат нито един кораб от 1916 - с/у тях да 
-- пише NULL.