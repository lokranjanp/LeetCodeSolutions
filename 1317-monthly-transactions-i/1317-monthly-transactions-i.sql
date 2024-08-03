# Write your MySQL query statement below
select 
    DATE_FORMAT(trans_date, '%Y-%m') as month, 
    country, COUNT(*) as trans_count, 
    SUM(IF(state = 'approved', 1, 0)) as approved_Count,   
    SUM(amount) as trans_total_amount, 
    SUM(IF(state = 'approved', amount, 0)) as approved_total_amount 
    
from transactions 
group by month, country;