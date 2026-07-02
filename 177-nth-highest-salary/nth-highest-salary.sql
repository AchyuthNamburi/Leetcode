CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
        with cte as (
            select E.salary,
            dense_rank() over(order by E.salary desc) as rnk
            from Employee E
        )

        select MAX(e.salary) from cte e where rnk=N
      
  );
END;
$$ LANGUAGE plpgsql;