SELECT q.person_name from
    (
        select person_id, person_name, weight, turn, SUM(weight)
        over (order by turn) as capacity from Queue
    ) as q
WHERE capacity <= 1000
order by turn desc
LIMIT 1;