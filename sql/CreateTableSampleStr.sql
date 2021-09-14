-- DDL: Create table SampleStr.
CREATE TABLE SampleStr
(str1	VARCHAR(40),
 str2	VARCHAR(40),
 str3	VARCHAR(40));
 
-- DML: Insert values.
BEGIN TRANSACTION;

INSERT INTO SampleStr (str1, str2, str3) VALUES ('opx', 'rt', NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('abs', 'def', NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('opx', 'rt', NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('É½Ìï', 'Ì«ÀÉ', 'ÊÇÎÒ');
INSERT INTO SampleStr (str1, str2, str3) VALUES ('aaa', NULL, NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES (NULL, 'xyz', NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('@!#$%', NULL, NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('ABC', NULL, NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('aBC', 'rt', NULL);
INSERT INTO SampleStr (str1, str2, str3) VALUES ('abcÌ«ÀÉ', 'abc', 'ABC');
INSERT INTO SampleStr (str1, str2, str3) VALUES ('abcdefabc', 'abc', 'ABC');
INSERT INTO SampleStr (str1, str2, str3) VALUES ('micmic', 'i', 'I');

COMMIT;