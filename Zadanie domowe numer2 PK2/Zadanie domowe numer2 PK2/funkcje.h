#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Struktury.h"

void create_student_database(student** pHead, char* FILENAME);
void wczytaj(student** pHead);
void wczytaj_istniejaca_baze(student** pHead, char tmp1[20], char tmp2[20], float tmp3);
void wczytaj_istniejaca_baze2(student** pHead, char* filename);
void wyswietlanie_listy(student* pHead);
void modyfikacja(student** pHead, char i[20], char n[20], float srednia);
student* szukanie_studenta(student** pHead, char i[20], char n[20]);
int menu(student** pHead);