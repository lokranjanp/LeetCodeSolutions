select s.user_id, ROUND(AVG(if(c.action="confirmed", 1, 0)), 2) as confirmation_rate 
from Signups as s left join Confirmations as c
on s.user_id = c.user_id 
group by user_id;