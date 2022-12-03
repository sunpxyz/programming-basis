/*
 * src/ch_5/multi_array.c
 *
 * 2019/2/21
 */


static char daytab[2][13] = {
	{ 0, 13, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 13, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


/*
 * ��ĳ��ĳ�յ����ڱ�ʾ��ʽת��Ϊĳ���еڼ���ı�ʾ��ʽ
 */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}


/*
 * ��ĳ���еڼ�������ڱ�ʾ��ʽת��Ϊĳ��ĳ�յı�ʾ��ʽ
 */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
