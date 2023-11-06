# Write your MySQL query statement below
Select
  product_id, year as first_year, quantity, price
from
  Sales as s
  where
    (s.product_id, s.year) in (select s1.product_id, min(s1.year) from sales as s1
    group by
      s1.product_id)
  
  
  