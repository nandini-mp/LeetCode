# Write your MySQL query statement below
SELECT w1.id FROM Weather w1 JOIN Weather w2 ON DATEDIFF(w1.recordDate,w2.recordDate)=1 WHERE w1.temperature>w2.temperature;

/*
SELECT w1.id
FROM Weather w1
JOIN Weather w2
  ON w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature;

SELECT w1.id
FROM Weather w1
JOIN Weather w2
  ON w1.recordDate = w2.recordDate + INTERVAL 1 DAY
WHERE w1.temperature > w2.temperature;
*/