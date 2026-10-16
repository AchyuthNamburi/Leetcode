-- Write your PostgreSQL query statement below
    select 
    to_char(trans_date,'YYYY-MM') as month,
    country,
    count(*) as trans_count,
    SUM(CASE
    when state='approved' then 1
    else 0
    END) as approved_count,
    SUM(amount) as trans_total_amount,
    SUM(CASE
        when state='approved' then amount
        else 0
        END) as approved_total_amount
    from transactions 
    group by to_char(trans_date,'YYYY-MM'),country;
