# Write your MySQL query statement below
SELECT * FROM Patients WHERE conditions REGEXP '\\bDIAB1' AND conditions NOT LIKE '%+DIAB1%';
#\\bDIAB1 matches whole word boundaries — so DIAB1 at the start of any word is matched: