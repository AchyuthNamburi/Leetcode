-- Write your PostgreSQL query statement below

With CTE as(
        select *,
        DENSE_RANK() over( partition by departmentId
                            order by Salary desc) as rnk 
        from Employee
)

select d.name as Department,
        e.name as Employee,
        e.salary as Salary
        from Department d 
        join CTE e on e.departmentId=d.id
        where rnk<=3;


