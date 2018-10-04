#include <stdio.h>
#include <stdlib.h>
#include <winnt.h>
#pragma warning(disable:4996)

void main()
{
	FILE* f = fopen("C:\\Windows\\System32\\cacls.exe", "rb");//לקריאה בינארית calc.exe פתחתי את
	PIMAGE_DOS_HEADER dosHeader;
	int pNTHeader;
	char buf[10];

	if (f == NULL)//בדיקה לאישור פתיחה
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}

	fread(buf, sizeof(buf), 2, f);// קוראת מהקובץ
	printf("Example %c\r\n", buf[0]);
	printf("Example %c\r\n", buf[1]);
	//where the PE header starts
	dosHeader = f;
	pNTHeader = dosHeader + dosHeader->e_lfanew;

	fclose(f);
}