#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>
#pragma warning(disable:4996)

void main()
{
	/*
	PIMAGE_DOS_HEADER DosHeader;
	long StartMS_Dos;
	*/
	char buf[10];
	int a = 0;
	FILE* f = fopen("C:\\Windows\\System32\\cacls.exe", "rb");//open calc.exe to binary reading
	if (f == NULL)//chek to open the file
	{
		printf("Failed opening the file. Exiting!\n");
		return;
	}
	//where the PE header starts
	fseek(f, 78, SEEK_SET);
	fread(buf,sizeof(char), 9, f);
	//fread(buf, sizeof(buf), 9, f);
	printf("Example %0x\r\n", buf[0]);
	printf("Example %0x\r\n", buf[1]);

	fclose(f);
	/*
	DosHeader = f;//exept the start address
	printf("Example %c\r\n", DosHeader);

	StartMS_Dos = DosHeader + 78;

	//fread(buf, sizeof(buf), 10, f);
	*/
}