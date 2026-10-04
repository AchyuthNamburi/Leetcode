
with cte1 as (
    select distinct activity_date as day,
    user_id from Activity
    where activity_date<='2019-07-27' and 
    activity_date >= '2019-06-28'   
),

cte2 as (
    select day,
    count(user_id) over (partition by day) as active_users
    from cte1
)

select distinct day,
        active_users from cte2;