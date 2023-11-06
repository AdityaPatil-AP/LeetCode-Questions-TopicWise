# Write your MySQL query statement below

# Group the Product tuples with product_id with tuples date less than equal to '2019-08-16'.
# From them find the product_id with the maximum change_date for them.
# When you get them join them with original table to get new table.
# Now get the distinct ids from the original table. 
# Do left join with new table.
# Replace those which contain null values with 10.

Select
    UniqueProductIds.product_id,
    ifnull (LastChangedPrice.new_price, 10) as price
from
    (Select 
        distinct product_id
    from
        Products
    ) as UniqueProductIds
    Left join
    (
        Select
            Products.product_id,
            new_price
        from    
            Products
        join
            (
                Select
                    product_id,
                    max(change_date) as change_date
                from
                    Products
                where 
                    change_date <= '2019-08-16'
                group by
                    product_id
            ) as LastChangedDate using (product_id, change_date)
        group by
            product_id
    ) as LastChangedPrice using (product_id)

# We will find the last price of those products whose price have been
# changed before '2019-08-16'.

# All the other product_ids don't have a change_date less than or equal to '2019-08-16'
# therefore we have to set their price as 10.

# Select 
#     product_id, new_price as price 
# from
#     Products 
# where 
#     (product_id, change_date) 
# in 
#     (Select 
#         product_id, max(change_date) as date
#     from    
#         Products
#     where 
#         change_date <= '2019-08-16' 
#     group by
#         product_id
#     )
# union all
# Select 
#     product_id, 10 as price
# from
#     Products 
# where 
#     (product_id, change_date) 
# in
#     (Select
#         product_id, min(change_date) as date
#     from
#         Products
#     group by 
#         product_id
#     having 
#         date >= '2019-08-17')