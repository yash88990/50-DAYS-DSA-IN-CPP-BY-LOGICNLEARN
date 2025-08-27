SELECT
product_id,
year AS first_year,
quantity,
price
FROM (
    SELECT *,
    MIN(year) OVER (PARTITION BY product_id) AS minyear
    FROM Sales
) AS a
WHERE a.year=a.minyear