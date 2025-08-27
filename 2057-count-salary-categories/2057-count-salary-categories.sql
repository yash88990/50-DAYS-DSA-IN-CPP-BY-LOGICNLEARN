SELECT
    category,
    IFNULL(accounts_count, 0) AS accounts_count
FROM(
    SELECT
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
            WHEN income > 50000 THEN 'High Salary'
        END AS category,
        COUNT(1) AS accounts_count
    FROM
        Accounts
    GROUP BY
        category
    ) AS a
    RIGHT JOIN (
        SELECT 'Low Salary' AS category
        UNION
        SELECT 'Average Salary' AS category
        UNION
        SELECT 'High Salary' AS category
    ) AS b
    USING(category)