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

	cout << "username:";
	cin.getline(username, 20);
	cout << "password:";
	cin.getline(password, 20);

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

int main()
{
		cout << "Content-Type: text/html\r\n\r\n";
		char Data[1000];
		char *Token;

		cin >> Data;

		if (Data != NULL)
		{
			printf("<html>");
			printf("<head>");
			printf("<p> ich bin da </p> <br> <\br>");
			printf("</head>");
			printf("<body>");

			cout << Data;
			Token = strtok(Data, "&");
			sscanf(Token, "username=%s", username);
			printf("<p> the first name is:%s", username,"</p>");

			Token = strtok(NULL, "&");
			sscanf(Token, "password=%s", password);
			printf("<P> the password is:%s", password, "</p>");
		}
		else
		{
			printf("<p> ohhh Fehler </p>");
		}

	if (valid_login())
		cout << "<p> gültige Daten </p>";
	else
		cout << "<p> ungültige Daten </p>";
	printf("</body>");
	printf("</html>");

	system("pause");
	return 0;
}