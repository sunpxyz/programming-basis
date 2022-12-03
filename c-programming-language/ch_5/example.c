/*
 * src/ch_5/example.c
 *
 * 2019/2/21
 */

#include <stdio.h>
#include <ctype.h>


int getch(void);
void ungetch(int);


void swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}


/*
 * �������е���һ����������ֵ��*pn
 */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}


/*
 * �����ַ���s�ĳ���
 */
int strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++) {
		++n;
	}

	return n;
}


/*
 * ����ָ��tָ����ַ�����ָ��sָ���λ��
 */
void strcpy_a(char *s, char *t)
{
	int i = 0;

	while ((s[i] = t[i]) != '\0') {
		s++;
		t++;
	}
}


/*
 * ����ָ��tָ����ַ�����ָ��sָ���λ��
 */
void strcpy_p(char *s, char *t)
{
	while (*s++ = *t++) {
		;
	}
}


/*
 * ���ֵ�˳��Ƚ�ָ��s��ָ��tָ����ַ�����С 
 */
int strcmp_a(char *s, char *t)
{
	int i = 0;
	for (; s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}


/*
 * ���ֵ�˳��Ƚ�ָ��s��ָ��tָ����ַ�����С
 */
int strcmp_p(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}


/*
 * ���ص�n���·ݵ�����
 */
char *month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March", "April", "May", "Jane",
		"July", "August", "September", "October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}
