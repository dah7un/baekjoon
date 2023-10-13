-- 코드를 입력하세요
SELECT A.CAR_ID, A.CAR_TYPE, ROUND(daily_fee*30*(100-DISCOUNT_RATE)/100) AS FEE
FROM CAR_RENTAL_COMPANY_CAR AS A
    JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY AS B
    JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS C
    ON A.CAR_ID=B.CAR_ID and A.CAR_TYPE=C.CAR_TYPE
        and duration_type='30일 이상'
-- WHERE END_DATE < '2022-11-1' or  START_DATE > '2022-11-30'
--    and (A.car_type='세단' or A.car_type='SUV')

 WHERE  1=1 
        AND A.CAR_TYPE IN ('세단', 'SUV')
        AND A.CAR_ID NOT IN (
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE START_DATE <= '2022-11-30' AND END_DATE >= '2022-11-01'
        )

GROUP BY A.CAR_ID
HAVING 500000<=FEE and FEE<2000000
ORDER BY FEE DESC, A.CAR_TYPE, A.CAR_ID DESC