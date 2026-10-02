-- Write your PostgreSQL query statement below

with cte as (
    select pid,
        tiv_2016,lat,lon,
        count(*) over (partition by tiv_2015) as cnt_2015,
        count(*) over (partition by lat,lon) as loc 
        from Insurance
)


select round(Sum(tiv_2016)::numeric,2) as tiv_2016 
from cte
where cnt_2015 > 1
and loc = 1;
