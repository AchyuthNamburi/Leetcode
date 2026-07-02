-- Write your PostgreSQL query statement below
with CTE as (
    select *,
    dense_rank() over( partition by departmentId
                        order by Salary desc) as rnk 
        from Employee
)

select d.name as Department,
    e.name as Employee,
    e.salary as salary
    from Department d
    join CTE e on d.id=e.departmentId
    where rnk<=1;