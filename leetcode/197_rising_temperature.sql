-- 完蛋不知道日期加減的 Function 怎麼寫
SELECT
    id
FROM
    Weather W1
WHERE
    temperature > (
        SELECT
            temperature
        FROM
            Weather W2
        WHERE
            DATEDIFF (W1.recordDate, W2.recordDate) = 1
    );