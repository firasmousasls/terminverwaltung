#include<iostream>
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;


char username[20];
char password[20];


bool valid_login()
{
	FILE *f = fopen("C:\\temp\\test.txt","r");
	char buffer[100] = " ";
	char line[100] = "";
	char pointer;
	if (f == NULL)
	{
		cout << "Fehler beim einlesen der Datei";
		return NULL;
	}
	
	while (!feof(f))
	{
		fread(buffer, sizeof(line),20, f);
	}

	char Data[20 + 1];

	//cout << "username:";
	//cin.getline(username, 20);
	//cout << "password:";
	//cin.getline(password, 20);

	strcat(line, username);
	strcat(line, " ");
	strcat(line, password);
	strcat(line, "\n");

	if (strstr(buffer, line)==NULL)
		return false;
	else
		return true;
}

/*-------------------------------------------------------------------------*/

void main()
{
		cout << "Content-Type: text/html\r\n\r\n";
		char Data[1000];
		char *Token;

		cin >> Data;

		if (Data != NULL)
		{
			printf("<P> ich bin da <br> <\br>");

			cout << Data;
			/*Token = strtok(Data, "&");
			sscanf(Token, "username=%s", username);
			printf("<P> the first name is:%s", username);

			Token = strtok(NULL, "&");
			sscanf(Token, "password=%s", password);
			printf("<P> the password is:%s", password);*/
		}
		else
		{
			printf("<P> ohhh Fehler");
		}

	if (valid_login())
		cout << "<P> gültige Daten";
	else
		cout << "<P> ungültige Daten";

	system("pause");
}