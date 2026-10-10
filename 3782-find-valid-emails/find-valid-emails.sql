-- Write your PostgreSQL query statement below

select * from
Users
where email ~'^[A-Za-z0-9_]*@[A-Za-z][A-Za-z]*\.com$'
order by user_id;