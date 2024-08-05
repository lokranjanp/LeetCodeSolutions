select ROUND(COUNT(a1.player_id)/(select COUNT(DISTINCT player_id) from Activity),2) as fraction
from activity a1 join activity a2
where a1.player_id = a2.player_id
AND (a1.player_id, a1.event_date) in 
    (select player_id, min(event_date) 
        from Activity group by player_id)
AND DATEDIFF(a2.event_date, a1.event_date) = 1