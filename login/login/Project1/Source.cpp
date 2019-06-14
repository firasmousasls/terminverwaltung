#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	FILE *f = fopen("C:\temp\Termine.txt", "rw");
	char art[100];
	char datum[10];
	char Uhrzeit[10];
	char Termin[150];

	if (f == NULL)
	{
		cout << "Fehler beim einlesen der Datei";
		return 0;
	}
	
	cout << "Geben sie das Datum an:";
	cin >> datum;

	cout << "Geben Sie die Uhr Zeit an:";
	cin >> Uhrzeit;

	cout << "Geben Sie den art an:";
	cin >> art;

	strcat(Termin, datum);
	strcat(Termin, "|");
	strcat(Termin, Uhrzeit);
	strcat(Termin, "|");
	strcat(Termin, art);

	fwrite(Termin, sizeof(Termin), 1, f);

	
	system("pause");
	return 0;
}