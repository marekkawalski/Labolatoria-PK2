#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"
#include "Struktury.h"

/*void read_from_file()
{

}
*/

void wczytaj(student** pHead)
{
	char imie [20];
	char nazwisko[20];
	float srednia;
	if (*pHead==NULL)
	{
		*pHead = (student*)malloc(sizeof(student));
		scanf("%s", (*pHead)->imie);  
		scanf("%s", (*pHead)->nazwisko);  
		scanf("%f", &(*pHead)->srednia);
		(*pHead)->pNext = NULL;
	}
	else
	{
		student* p = *pHead;
		while (p->pNext)
		{
			p = p->pNext;
		}
		p->pNext = (student*)malloc(sizeof(student));
		scanf("%s", p->pNext->imie);  
		scanf("%s", p->pNext->nazwisko); 
		scanf("%f", &p->pNext->srednia);
		p->pNext->pNext = NULL;
		
	}
}
/*void create_student_database (struct student*pHead,  char *FILENAME)
{
	//struct student* p = pHead;
	/*while (!scanf("end"))
	{
		printf("Podaj: imie nazwisko oraz srednia");
		scanf("%s", p->imie);
		scanf("%s", p->nazwisko);
		scanf("%lf", p->srednia);
		p = p->pNext;
	}
	/*
	if (*head == NULL)
	{
		*head = (ListElement_type*)malloc(sizeof(ListElement_type));
		(*head)->data = number;
		(*head)->next = NULL;
	}
	else
	{
		ListElement_type* current = *head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (ListElement_type*)malloc(sizeof(ListElement_type));
		current->next->data = number;
		current->next->next = NULL;
	}
	

	FILE* file;
	file = fopen(FILENAME, "wb");
	if (file)
	{
			struct student*p=pHead;
			if (!pHead)
			{
				&pHead->imie = scanf("%s", imie);

			}

			else
			{
				while (!scanf("end"))
				{
					fwrite(scanf("%s ", pHead->imie), 1, 20, file);
					fwrite(scanf("%s ", pHead->nazwisko), 1, 20, file);
					fwrite(scanf("%s", &pHead->imie), sizeof(float), 1, file);
					pHead = pHead->pNext;
				}

			}
			fclose(file);
	}

	

}*/

int menu()
{
	int k;
	char* s= "Czy wywolac ponownie menu?";
	char t[] ="tak";
	char y[40];
	printf("Wpisz numer jednej z podanych opcji:\n");
	printf("1: utworzenie bazy studentow i jej zapis do pliku binarnego\n");
	printf("2: wczytanie istniejacej bazy (plik binarny) do tablicy struktur lub listy liniowej,\n");
	printf("3: wyswietlanie zawartosci bazy\n");
	printf("4: dodanie studenta do bazy\n");
	printf("5: modyfikacje pojedynczej struktury w bazie (np. sredniej studenta)\n");
	printf("6: wyszukanie danego studenta w bazie\n");
	printf("7: usuniecie studenta z bazy\n");
	printf("8: wyjscie z programu\n");
	scanf("%d", &k);
	switch (k)
	{
	case 1: 
		printf("%s\t", s);
		scanf("%s",y);
		if ((strcmp(y, t))==0) menu();
		else return 0;
		break;
	case 2:
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu();
		else return 0;
		break;
	case 3:
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu();
		else return 0;
		break;
	case 4:
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu();
		else return 0;
		break;
	case 5:
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu();
		else return 0;
	case 6:
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu();
		else return 0;
		break;
	case 7:
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu();
		else return 0;
		break;
	case 8:
		return 0;
		break;
	default: printf("Wybrales opcje, ktora nie jest mozliwa.\n");
		break;
	}
}