/*
 * src/ch_7/example.c
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*
 * ���пɱ������ļ򻯵�printf����
 */
void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++) {
				putchar(*sval);
			}
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}


/*
 * ��iopָ����ļ�������ȡn-1���ַ����ټ���һ��NULL
 */
char *fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF) {
		if ((*cs++ = c) == '\n') {
			break;
		}
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}


/*
 * ���ַ���s�����iopָ����ļ���
 */
int fputs(char *s, FILE *iop)
{
	int c;

	while (c = *s++) {
		putc(c, iop);
	}

	return ferror(iop) ? EOF : 1;
}


/*
 * ����һ�������У��������䳤��
 */
int getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL) {
		return 0;
	} else {
		return strlen(line);
	}
}
