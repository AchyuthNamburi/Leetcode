-- Write your PostgreSQL query statement below
with cte as (
    select score,
    dense_rank() over (order by score desc) as rank
    from Scores
)

select * from cte;