-- Write your PostgreSQL query statement below

with cte as (
    select customer_number,
    count(customer_number) over(partition by customer_number) as no_of_times
    from Orders
)

select  customer_number 
from cte
order by no_of_times desc
limit 1;