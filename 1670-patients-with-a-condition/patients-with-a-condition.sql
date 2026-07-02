-- Write your PostgreSQL query statement below
select * from Patients 
where conditions LIKE ('DIAB1%') or 
conditions ~'\sDIAB1';