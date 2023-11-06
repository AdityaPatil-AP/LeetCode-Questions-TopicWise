# Write your MySQL query statement below
Select
    round(sum(tiv_2016),2) as tiv_2016
from
    Insurance as i1
where
    i1.tiv_2015 in (Select tiv_2015 from insurance where
        pid != i1.pid)
    and
    (i1.lat, i1.lon) not in
        (Select lat, lon from 
        Insurance where pid != i1.pid)
            

