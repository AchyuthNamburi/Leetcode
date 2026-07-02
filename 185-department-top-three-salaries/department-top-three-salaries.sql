-- Write your PostgreSQL query statement below
    
select Department,Employee,Salary 
from (    
    select D.name as Department,
        E.name as Employee,
        E.salary as Salary,
    DENSE_RANK() over(partition by D.name
                        order by Salary desc
                        ) as rank 
    from Employee E JOIN Department D on E.departmentId=D.id)
    where rank<=3;

