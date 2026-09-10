-- Write your PostgreSQL query statement below
select employee_id,
    (CASE
        When E.employee_id%2=1 and E.name NOT LIKE 'M%' then E.salary
        else 0
    END
    ) as bonus
from Employees E
order by E.employee_id;