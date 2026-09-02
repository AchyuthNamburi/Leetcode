select project_id,
    round( sum(E.experience_years) * 1.0 / count(E.employee_id),2) as average_years 
from Project P 
join Employee E on P.employee_id=E.employee_id
group by P.project_id;