select r.contest_id, 
ROUND(COUNT(r.user_id) * 100 /(select COUNT(user_id) from Users), 2) as percentage
from Register as r
group by r.contest_id
order by percentage desc, r.contest_id;