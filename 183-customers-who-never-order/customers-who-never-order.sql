# Write your MySQL query statement below
SELECT C.name as Customers FROM Customers C LEFT JOIN Orders O ON C.id = O.customerId WHERE O.id IS NULL;
/* O.id is NULL gives those customers who didn't place an order yet, as we're using LEFT JOIN*/