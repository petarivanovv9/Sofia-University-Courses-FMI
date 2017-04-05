-- task 1

select address
from studio
where studio.name='MGM';

select birthdate
from moviestar
where moviestar.name='Sandra Bullock';

select starname
from starsin
where movieyear=1980 and movietitle like '%Empire%';

select name
from movieexec
where networth > 10000000;

select name
from moviestar
where gender='M' or address like '%Malibu%';


