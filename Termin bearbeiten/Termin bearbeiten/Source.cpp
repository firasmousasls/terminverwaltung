#include<iostream>
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;

char altDatum[10 + 1];
char altUhrzeit[5 + 1];
char altart[1500 + 1];


char neuDatum[10 + 1];
char neuUhrzeit[5 + 1];
char neuart[1500 + 1];

int main()
{
	cout << "Content-Type: text/html\r\n\r\n";
	char Data[1000];
	char* Token;

	//cin >> Data;

	//if (Data != NULL)
	//{
	//	printf("%s",Data);
	//}
	//else
	//	printf("<p> null </p>");
	
	printf("<p> ich bin da </p>");

	
	
	
	/*FILE* f = fopen("C:\\temp\\Termine.txt","r");
	
	if (f == NULL)
	{
		cout << "Die Datei ksnn nicht gefönnet wrden!";
		return 0;
	}

	char editline[200];
	char buffer[4000]="";

	fread(buffer, sizeof(editline), 20, f);
	



	fclose(f);
	system("pause");*/
	return 0;
}
