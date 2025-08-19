SELECT
    E1.name
FROM
    Employee AS E1
JOIN
    (SELECT managerId
     FROM Employee
     GROUP BY managerId
     HAVING COUNT(id) >= 5) AS T
ON
    E1.id = T.managerId;