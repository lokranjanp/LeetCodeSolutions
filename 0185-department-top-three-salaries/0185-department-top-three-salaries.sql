# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary 
from Employee e join Department d on e.departmentId = d.id
where (
    select COUNT(DISTINCT(salary))
    from Employee e2
    where e2.departmentId = e.departmentId and e.salary <= e2.salary
) <= 3
order by d.id, e.salary desc;