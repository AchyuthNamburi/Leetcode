select product_name ,
    sum(unit) as unit
    from Products P,Orders O where P.product_id=O.product_id
    and O.order_date between '2020-02-01' and '2020-02-29'
    group by product_name
    having sum(unit)>=100;