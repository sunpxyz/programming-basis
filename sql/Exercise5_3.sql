--2016.03.16 Payne.Sun
--Exercise 5.3
SELECT shohin_id, 
       shohin_mei, 
	   shohin_bunrui, 
	   hanbai_tanka, 
	   (SELECT AVG(hanbai_tanka) FROM Shohin) AS hanbai_tanka_all
FROM Shohin;
