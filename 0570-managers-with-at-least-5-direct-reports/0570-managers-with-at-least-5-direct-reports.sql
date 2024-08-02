# Write your MySQL query statement below
select e1.name from Employee e1 left join Employee e2 
on e2.managerId = e1.id 
group by e1.id having COUNT(*)>=5;