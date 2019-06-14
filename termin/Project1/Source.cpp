#include<iostream>
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;

char art[100];
char datum[10];
char Uhrzeit[7];

int neuerTermin()
{
	FILE *f = fopen("C:\\temp\\termin.txt", "a+");
	
	int pos = 0;
	char TerminLine[150] = "";

	if (f == NULL)
	{
		cout << "<p> Fehler beim einlesen der Datei </p>";
		return 0;
	}

	cout << "Geben sie das Datum an:";
	cin.getline(datum, 10);

	cout << "Geben Sie die Uhr Zeit an:";
	cin.getline(Uhrzeit, 10);

	cout << "Geben Sie den art an:";
	cin.getline(art, 100);

	strcat(TerminLine, datum);
	strcat(TerminLine, "|");
	strcat(TerminLine, Uhrzeit);
	strcat(TerminLine, "|");
	strcat(TerminLine, art);
	strcat(TerminLine, "\n");

	fseek(f, 0, SEEK_CUR);

	fputs(TerminLine, f);

	fclose(f);
}

/*--------------------------------------------------------------------*/

int main()
{
	cout << "Content-Type: text/html\r\n\r\n";
	char Data[1000];
	char *Token;

	printf("<html>");
	printf("<head>");
	printf("<meta charset='utf-8'>");
	printf("</head>");
	printf("<body>");

	printf("<p>ich bin da !</p> ");

	cout << "<br/>";
	cout << endl;
	cin >> Data;

	if (Data != NULL)
	{
		printf("<p> ich bin da !\n</p>");
		printf("%s", Data);

		Token = strtok(Data, "&");
		sscanf(Token, "bday=%s", datum);
		printf("<p> the datum is:%s", datum ,"</p>");

		Token = strtok(NULL, "&");
		char *needly = strstr(Uhrzeit, "%3A");
		sscanf(Token, "zeit=%s", Uhrzeit);
		
		// %3A
		char temp[6];
		temp[5] = '\0';

		for (int i = 0, b = 0; i < sizeof(Uhrzeit); i++, b++)
		{
			if (Uhrzeit[i] == '%')
			{
				temp[b] = ':';
				i += 2;
				continue;
			}

			temp[b] = Uhrzeit[i];
		}
		strcpy(Uhrzeit, temp);


		printf("<p> the time is:%s", Uhrzeit, "</p>");

		Token = strtok(NULL, "&");
		sscanf(Token, "aufgabe=%s", art);

		for (int i = 0; i < sizeof(art); i++)
		{
			if (art[i] == '+')
				art[i] = ' ';
		}

		printf("<p> the art is:%s", art,"</p>");
	}
	else
	{
		printf("<p>Fehler</p>");
	}

	printf("</body>");
	printf("</html>");
	
	neuerTermin();

	/*system("pause");*/
	return 0;
}