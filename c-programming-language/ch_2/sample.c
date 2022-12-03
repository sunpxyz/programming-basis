/*
 * src/ch_2/sample.c
 *
 * 2019/2/10
 */


/*
 * �����ַ���s�ĳ���
 */
int strlen(char s[])
{
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}


/*
 * ���ַ���sת��Ϊ��Ӧ��������
 */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}


/*
 * ���ַ�cת��ΪСд��ʽ
 */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}


/*
 * ɾ���ַ���s�е��ַ�c
 */
void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; ++i)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}


/*
 * ���ַ���t���ӵ��ַ���s��β����s�������㹻��Ŀռ�
 */
void strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		++i;
	while ((s[i++] = t[j++]) != '\0')
		;
}


/*
 * ����x�дӵ�pλ��ʼ��nλ
 */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}



/*
 * ͳ��x��ֵΪ1�Ķ�����λ��
 */
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
