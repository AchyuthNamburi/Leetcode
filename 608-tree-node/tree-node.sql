-- Write your PostgreSQL query statement below
select distinct t.id,
(CASE
    when t.p_id is null then 'Root'
    when child.id is null then 'Leaf' 
    else 'Inner'
END) as type 
from Tree t 
left join Tree child 
on t.id=child.p_id;