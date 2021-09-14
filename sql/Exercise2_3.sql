-- 2016-02-28 SUN
-- Exercise02_03

-- Solution 1:
/*
SELECT shohin_mei, hanbai_tanka, shiire_tanka
FROM Shohin
WHERE NOT hanbai_tanka - shiire_tanka < 500;
*/

-- Solution 2:
SELECT shohin_mei, hanbai_tanka, shiire_tanka
FROM Shohin
WHERE hanbai_tanka >= shiire_tanka + 500;