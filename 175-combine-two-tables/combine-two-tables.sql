# Write your MySQL query statement below
SELECT firstName, lastName, city, state FROM Person LEFT JOIN Address ON Person.personId=Address.personId;
/* if we did just JOIN (inner join), it only returns rows where there's a match in both Person and Address
LEFT JOIN returns all rows from Person and the matching rows from Address if available. If there is no match, the city and state columns will contain NULL*/