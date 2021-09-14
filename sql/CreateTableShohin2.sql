CREATE TABLE Shohin2
(shohin_id      CHAR(4)       NOT NULL,
 shohin_mei     VARCHAR(100)  NOT NULL,
 shohin_bunrui  VARCHAR(32)   NOT NULL,
 hanbai_tanka   INTEGER       ,
 shiire_tanka   INTEGER       ,
 torokubi       DATE          ,
 PRIMARY KEY (shohin_id));
 
BEGIN TRANSACTION;
INSERT INTO Shohin2 VALUES ('0001', 'T恤衫', '衣服', 1000, 500, '2008-09-20');
INSERT INTO Shohin2 VALUES ('0002', '打孔器', '办公用品', 500, 320, '2009-09-11');
INSERT INTO Shohin2 VALUES ('0003', '运动T恤', '衣服', 4000, 2800, NULL);
INSERT INTO Shohin2 VALUES ('0009', '手套', '衣服', 800, 500, NULL);
INSERT INTO Shohin2 VALUES ('0010', '水壶', '厨房用具', 1000, 1700, '2009-09-20');
COMMIT;