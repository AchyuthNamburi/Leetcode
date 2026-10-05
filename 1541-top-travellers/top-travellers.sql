-- Write your PostgreSQL query statement below

with cte as(
    select U.id,U.name,
    coalesce(sum(R.distance) over(partition by U.id ),0) as travelled_distance
    from users U left join Rides R
    ON U.id = R.user_id
)

select distinct name,travelled_distance
from cte C
order by travelled_distance desc , name ;