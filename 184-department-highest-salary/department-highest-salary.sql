# Write your MySQL query statement below
SELECT D.name AS Department,E.name as Employee,E.salary as Salary
FROM Employee E JOIN DEPARTMENT D ON E.departmentID = D.id JOIN
(
    SELECT departmentId, MAX(salary) as maxSalary
    FROM Employee
    GROUP BY departmentId 
) AS DeptMaxSalary ON E.departmentID = DeptMaxSalary.departmentId
AND E.salary = DeptMaxSalary.maxSalary;