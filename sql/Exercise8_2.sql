--2016.04.06 Payne.Sun
--Exercise 8.2
SELECT torokubi, shohin_mei, hanbai_tanka,
       SUM (hanbai_tanka) OVER (ORDER BY torokubi NULLS FIRST) AS current_sum_tanka
FROM Shohin;