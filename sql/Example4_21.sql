BEGIN TRANSACTION;
	UPDATE Shohin
		SET hanbai_tanka = hanbai_tanka - 1000
	WHERE shohin_mei = '‘À∂ØT–Ù';
	
	UPDATE Shohin
		SET hanbai_tanka = hanbai_tanka + 1000
	WHERE shohin_mei = 'T–Ù…¿';
COMMIT;