select p.product_name, sum(o.unit) as unit from Orders as o left join Products as p
on o.product_id = p.product_id
where DATE_FORMAT(o.order_date, '%Y-%m') = '2020-02'
group by o.product_id
having unit >= 100;