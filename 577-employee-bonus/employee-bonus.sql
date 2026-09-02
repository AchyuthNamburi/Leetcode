-- Write your PostgreSQL query statement below
select name,bonus 
from Employee E
left join Bonus B on E.empId=B.empId
where E.empId=B.empId
and B.bonus<1000 or B.bonus is NULL;