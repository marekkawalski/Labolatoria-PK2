#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"
#include "Struktury.h"
void wczytaj(student** pHead)
{
		if (*pHead == NULL)
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
void wczytaj_istniejaca_baze(student** pHead, char tmp1[20], char tmp2[20], float tmp3)
{
			if (*pHead == NULL)
			{
				*pHead = (student*)malloc(sizeof(student));
				strcpy((*pHead)->imie, tmp1);
				strcpy((*pHead)->nazwisko, tmp2);
				(*pHead)->srednia = tmp3;
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
				strcpy(p->pNext->imie, tmp1);
				strcpy(p->pNext->nazwisko, tmp2);
				p->pNext->srednia = tmp3;
				p->pNext->pNext = NULL;		
			}
}
/*void wczytaj_istniejaca_baze2(student** pHead, char* filename)
{
	FILE* file;
	file = fopen(filename, "rb");
	if (file)
	{
		char tmp[20];
		char tmp2[20];
		float tmp3=0;
		while((fscanf(file, "%s %s %f", tmp, tmp2, &tmp3))!=EOF)
		{
			wczytaj_istniejaca_baze(&pHead, tmp, tmp2, tmp3);
		}
		fclose(file);
	}
	else
		printf("Blad pliku lub bledna nazwa pliku.\n");
}
*/
void create_student_database (student**pHead,  char *FILENAME)
{
	FILE* file;
	file = fopen(FILENAME, "wb");
	if (file)
	{
		student* p = *pHead;
		while (p)
		{
			fwrite(p->imie, 1, 20, file);
			fwrite(p->nazwisko, 1, 20, file);
			fwrite(&p->srednia, sizeof(float), 1, file);
			p = p->pNext;
		}
		fclose(file);
	}
	else
		printf("Blad pliku\n");
}
void wyswietlanie_listy(student* pHead)
{
	if (pHead)
	{
		student* p = pHead;
		while (p)
		{
			printf("%s %s %f\n", p->imie, p->nazwisko, &p->srednia);
			p = p->pNext;
		}
	}
}
void modyfikacja(student** pHead, char i[20], char n[20], float srednia)
{
	if (pHead)
	{
		student* p = *pHead;
		while ((strcmp(i,p->imie))&&(strcmp(n, p->nazwisko))!=0)
		{
			p = p->pNext;
		}
		printf("Modyfikujesz studenta: ");
		printf("%s %s\n", p->imie, p->nazwisko);
		p->srednia = srednia;
	}
}
student* szukanie_studenta(student** pHead, char i[20], char n[20])
{
	if ((*pHead) && ((strcmp(i, (*pHead)->imie)) && (strcmp(n, (*pHead)->nazwisko)) != 0))
		return szukanie_studenta((*pHead)->pNext, i, n);
	else return (*pHead);
}
/*void usuwanie_studenta_z_bazy(student**pHead, char i[20], char n[20])
{
	student* p = *pHead;
	p= szukanie_studenta(&pHead, i, n);
	student* tmp;
	tmp = p->pNext;
	p->pNext = tmp->pNext;
	free(tmp);
}
/*
void pop_by_index(ListElement_type * *head, int position)
{
	if (position == 0) pop_front(head);
	else
	{
		ListElement_type* current = *head;
		ListElement_type* tmp;

		int i = 0;
		while (current->next != NULL && i < position - 1) {
			current = current->next;
			i++;
		}

		tmp = current->next;
		current->next = tmp->next;
		free(tmp);
*/
int menu(student** pHead)
{
	int k,r;
	char* s= "Czy wywolac ponownie menu?";
	char t[] ="tak";
	char y[40];
	char majorka[20];
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
		printf("Ilu studentow chcesz dodac?\n");
		scanf("%d", &r);
		printf("Wpisz prosze:\nimie\nnazwisko\nsrednia\n");
		for (int i = 0; i < r; i++)
		{
			wczytaj(&pHead);
		}
		create_student_database(&pHead, "nazwa.bin");
		printf("Twoj plik dostepny jest pod nazwa: nazwa.bin\n");
		printf("%s\t", s);
		scanf("%s",y);
		if ((strcmp(y, t))==0) menu(&pHead);
		else return 0;
		break;
	case 2:
		printf("Podaj nazwe pliku, gdzie znajduje sie baza: _._._.bin\t");
		scanf("%s", majorka);
		printf("%s\n", majorka);
		FILE * file;
		file = fopen(majorka, "rb");
		if (file)
		{
			char tmp[20];
			char tmp2[20];
			float tmp3 = 0;
 			while ((fscanf(file, "%s %s %f", tmp, tmp2, &tmp3)) != EOF)
			{
				wczytaj_istniejaca_baze(&pHead, tmp, tmp2, tmp3);
			}
			fclose(file);
		}
		else
			printf("Blad pliku lub bledna nazwa pliku.\n");
		
		//wczytaj_istniejaca_baze2(&pHead, majorka);        
		printf("%s\t", s);
		scanf("%s", y);
		if ((strcmp(y, t)) == 0) menu(&pHead);
		else return 0;
		break;
	case 3:
		if (*pHead == NULL)
		{
			printf("Musisz najpierw utworzyc baze. Wybierz opcje 1 lub 2\n");
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		else
		{
			wyswietlanie_listy(pHead);
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		break;
	case 4:
		if (*pHead == NULL)
		{
			printf("Musisz najpierw utworzyc baze. Wybierz opcje 1 lub 2\n");
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		else
		{
			wczytaj(&pHead);
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		break;
	case 5:
		if (*pHead == NULL)
		{
			printf("Musisz najpierw utworzyc baze. Wybierz opcje 1 lub 2\n");
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		else
		{
			printf("Podaj imie nazwisko i nowa srednia studenta");
			char i[20];
			char n[20];
			float srednia;
			scanf("%s %s %f", i, n, &srednia);
			modyfikacja(&pHead, i, n, srednia);
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		break;
	case 6:
		if (*pHead == NULL)
		{
			printf("Musisz najpierw utworzyc baze. Wybierz opcje 1 lub 2\n");
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		else
		{
			printf("Podaj imie nazwisko studenta");
			char i[20];
			char n[20];
			scanf("%s %s ", i, n);
			szukanie_studenta(&pHead, i, n);
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		break;
	case 7:
		if (*pHead == NULL)
		{
			printf("Musisz najpierw utworzyc baze. Wybierz opcje 1 lub 2\n");
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		else
		{
			printf("%s\t", s);
			scanf("%s", y);
			if ((strcmp(y, t)) == 0) menu(pHead);
			else return 0;
		}
		break;
	case 8:
		return 0;
		break;
	default: printf("Wybrales opcje, ktora nie jest mozliwa.\n");
		break;
	}
}