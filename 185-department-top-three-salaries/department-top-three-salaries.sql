-- Write your PostgreSQL query statement below

-- cte ---- write once use many times 
-- easier to understand then nested sub queries

with CTE as (
    select *,
    DENSE_RANK() over (partition by departmentId
                        order by salary desc) as rnk
                        from Employee 
)

select D.name as department , E.name as Employee , E.salary as Salary 
from cte E join Department D on E.departmentId=D.id 
where rnk<=3;