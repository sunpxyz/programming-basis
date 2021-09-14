-- 2016-03-07 SUN
-- Exercise03_02

SELECT shohin_bunrui, SUM(hanbai_tanka), SUM(shiire_tanka)
FROM shohin
GROUP BY shohin_bunrui
HAVING SUM(hanbai_tanka) > SUM(shiire_tanka) * 1.5;