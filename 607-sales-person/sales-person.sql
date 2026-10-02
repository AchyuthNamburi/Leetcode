-- select C.com_id,C.name,O.sales_id,S.sales_id,S.name
-- from orders O
-- right join salesperson S on S.sales_id=O.sales_id
-- left join company C on C.com_id=O.com_id
-- where C.name NOT in (
--     select name from company C 
--      right join Orders O on C.com_id=O.com_id
--     where C.name='RED' or C.name is NULL
-- );
-- -- != 'RED' or C.name is NULL;

select name 
from Salesperson 
where  sales_id NOT IN (
    select sales_id
        from
        company C join Orders O
        on C.com_id=O.com_id
        where C.name='RED'
    );
