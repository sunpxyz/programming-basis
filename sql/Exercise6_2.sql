--2016.03.24 Payne.Sun
--Exercise 6.2
SELECT SUM(CASE WHEN hanbai_tanka <= 1000
                THEN 1 END) AS low_price, 
       SUM(CASE WHEN hanbai_tanka > 1000 AND hanbai_tanka <= 3000
	            THEN 1 END) AS mid_price,
	   SUM(CASE WHEN hanbai_tanka > 3000
	            THEN 1 END) AS high_price
FROM Shohin;