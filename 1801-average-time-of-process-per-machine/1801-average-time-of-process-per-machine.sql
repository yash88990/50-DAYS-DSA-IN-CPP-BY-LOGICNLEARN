
SELECT machine_id, ROUND(AVG(time_taken), 3) AS processing_time
FROM ( SELECT
        machine_id,
        process_id,
        MAX(CASE WHEN activity_type = 'end' THEN timestamp END) -
        MIN(CASE WHEN activity_type = 'start' THEN timestamp END) AS time_taken
    FROM
        Activity
    GROUP BY
        machine_id,
        process_id
) AS ProcessTimes
GROUP BY
    machine_id;