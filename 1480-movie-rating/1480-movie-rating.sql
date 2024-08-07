(select name as results from MovieRating join Users using(user_id)
group by name
order by COUNT(*) desc,name
limit 1)

union all

(select title as results
from MovieRating join Movies using(movie_id)
where EXTRACT(YEAR_MONTH from created_at) = 202002
group by title
order by AVG(rating) desc, title
limit 1);