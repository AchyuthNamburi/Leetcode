select E1.name
from Employee E1
join Employee E2 on E1.id=E2.managerId
group by E2.managerId,E1.name
having count(*)>=5;