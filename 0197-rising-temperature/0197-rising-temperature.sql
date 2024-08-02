# Write your MySQL query statement below
select today.id from Weather today, Weather yest 
where DATEDIFF(today.recordDate, yest.recordDate) = 1
AND today.temperature > yest.temperature;