-- Write your PostgreSQL query statement below

select P.product_id,P.product_name 
from Product P 
right join Sales S 
on P.product_id=S.product_id
group by P.product_id, P.product_name
HAVING MIN(S.sale_date) >= '2019-01-01'
   and MAX(S.sale_date) <= '2019-03-31';
