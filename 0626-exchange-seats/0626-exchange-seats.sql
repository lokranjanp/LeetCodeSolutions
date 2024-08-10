SELECT id, CASE
                when id%2 = 0 then LAG(student) over(order by id)
                else coalesce (lead(student) over(order by id), student)
            END as student
        from seat;