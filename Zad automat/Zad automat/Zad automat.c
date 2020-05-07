#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stan_automatu
{
    double ilosc_wody;
    double ilosc_kawy;
    double ilosc_mleka;
}stan_automatu, kawa_czarna, kawa_z_mlekiem, gorace_mleko;

void uzupelnianie_automatu()
{
    printf("Prosze uzupelnic skladniki w maszynie.\n");
}
void zrob_kawe_czarna(kawa_czarna*pHead, stan_automatu*kontrola)
{
    if ((pHead->ilosc_kawy <= kontrola->ilosc_kawy) && (pHead->ilosc_mleka <= kontrola->ilosc_mleka) && (pHead->ilosc_wody <= pHead->ilosc_wody))
    {
        printf("Oto twoja kawka.\n");
        kontrola->ilosc_kawy -= pHead->ilosc_kawy;
        kontrola->ilosc_mleka -= pHead->ilosc_mleka;
        kontrola->ilosc_wody -= pHead->ilosc_wody;
    }
    else
    {
        uzupelnianie_automatu();
    }
}
void zrob_kawe_z_mlekiem(kawa_z_mlekiem*pHead, stan_automatu* kontrola)
{
    if ((pHead->ilosc_kawy <= kontrola->ilosc_kawy) && (pHead->ilosc_mleka <= kontrola->ilosc_mleka) && (pHead->ilosc_wody <= pHead->ilosc_wody))
    {
        printf("Oto twoja kawusia.\n");
        kontrola->ilosc_kawy -= pHead->ilosc_kawy;
        kontrola->ilosc_mleka -= pHead->ilosc_mleka;
        kontrola->ilosc_wody -= pHead->ilosc_wody;
    }
    else
    {
        uzupelnianie_automatu();
    }
}
void przygotuj_gorace_mleko(gorace_mleko*pHead, stan_automatu* kontrola)
{
 
   if ((pHead->ilosc_kawy <= kontrola->ilosc_kawy) && (pHead->ilosc_mleka <= kontrola->ilosc_mleka) && (pHead->ilosc_wody <= pHead->ilosc_wody))
   { 
       printf("Oto twoje mleczko.\n");
       printf("Oto twoja kawusia.\n");
       kontrola->ilosc_kawy -= pHead->ilosc_kawy;
       kontrola->ilosc_mleka -= pHead->ilosc_mleka;
       kontrola->ilosc_wody -= pHead->ilosc_wody;
   }
   else
   {
       uzupelnianie_automatu();
   }
}
int menu(kawa_czarna* pHead1, kawa_z_mlekiem* pHead2, gorace_mleko* pHead3, stan_automatu*kontrola)
{
    char tak[5];
    char nie[5];
    char czy[5];
    printf("Drogi milosniku cieplych napojow, wybierz prosze jedna z opcji.\n");
    printf("#0 zrob_kawe_czarna\n#1 zrob_kawe_z_mlekiem\n#2 przygotuj_gorace_mleko\n#3 anuluj\n ");
    int k = 0;
    scanf("%d",&k);
    switch (k)
    {
    case 0:printf("Wybrano: zrob_kawe_czarna.\n");
        zrob_kawe_czarna(pHead1, kontrola);
        printf("Zyczy sobie jasnie Pan/ jasnie Pani czegos jeszcze?\t (tak/nie)\n");
        scanf("%s", czy);
        if (strcmp(czy, tak))
        {
            menu(pHead1, pHead2, pHead3, kontrola);
        }
        else
        {
            printf("Dziekujemy za korzystanie z naszych uslug.");
                return 0;
        }
        break;
    case 1: printf("Wybrano: zrob_kawe_z_mlekiem.\n");
        zrob_kawe_z_mlekiem(pHead2, kontrola);
        printf("Zyczy sobie jasnie Pan/ jasnie Pani czegos jeszcze?\t (tak/nie)\n");
        scanf("%s", czy);
        if (strcmp(czy, tak))
        {
            menu(pHead1, pHead2, pHead3, kontrola);
        }
        else
        {
            printf("Dziekujemy za korzystanie z naszych uslug.");
            return 0;
        }
        break;
    case 2: printf("Wybrano: przygotuj_gorace_mleko.\n");
        przygotuj_gorace_mleko(pHead3, kontrola);
        printf("Zyczy sobie jasnie Pan/ jasnie Pani czegos jeszcze?\t (tak/nie)\n");
        scanf("%s", czy);
        if (strcmp(czy, tak))
        {
            menu(pHead1, pHead2, pHead3, kontrola);
        }
        else
        {
            printf("Dziekujemy za korzystanie z naszych uslug.");
            return 0;
        }
        break;
    case 3: return 0;
        break;
    default: printf("cos poszlo nie tak.\n");
        break;
        
    }
}
void wczytaj_dane_na_temat_zasobow(const char* Filename, stan_automatu*stan, kawa_czarna*kawa_czarna1, kawa_z_mlekiem*kawa_z_mlekiem1, gorace_mleko*gorace_mleko1)
{
    FILE* plik = fopen(Filename, "r");
    if (plik)
    {
        fscanf(plik, "%lf %lf %lf", &stan->ilosc_wody, &stan->ilosc_kawy, &stan->ilosc_mleka);
        fscanf(plik, "%lf %lf %lf", &kawa_czarna1->ilosc_wody, &kawa_czarna1->ilosc_kawy, &kawa_czarna1->ilosc_mleka);
        fscanf(plik, "%lf %lf %lf", &kawa_z_mlekiem1->ilosc_wody, &kawa_z_mlekiem1->ilosc_kawy, &kawa_z_mlekiem1->ilosc_mleka);
        fscanf(plik, "%lf %lf %lf", &gorace_mleko1->ilosc_wody, &gorace_mleko1->ilosc_kawy, &gorace_mleko1->ilosc_mleka);
        fclose(plik);
    }
    else 
    {
           printf("Blad przy wczytywaniu pliku.\n");
           printf("Brak mozliwosci wydania napoju.\n");
           stan->ilosc_wody = 0;
           stan->ilosc_kawy=0;
           stan->ilosc_mleka = 0;
    }
}
void wczytaj_dane_na_temat_zasobow2(const char* Filename, stan_automatu* stan, kawa_czarna* kawa_czarna1, kawa_z_mlekiem* kawa_z_mlekiem1, gorace_mleko* gorace_mleko1)
{
    FILE* plik = fopen(Filename, "w+");
    if (plik)
    {
        fprintf(plik, "%lf %lf %lf", stan->ilosc_wody, stan->ilosc_kawy, stan->ilosc_mleka);
        fprintf(plik, "%lf %lf %lf",kawa_czarna1->ilosc_wody, kawa_czarna1->ilosc_kawy, kawa_czarna1->ilosc_mleka);
        fprintf(plik, "%lf %lf %lf", kawa_z_mlekiem1->ilosc_wody, kawa_z_mlekiem1->ilosc_kawy, kawa_z_mlekiem1->ilosc_mleka);
        fprintf(plik, "%lf %lf %lf", gorace_mleko1->ilosc_wody, gorace_mleko1->ilosc_kawy, gorace_mleko1->ilosc_mleka);
        fclose(plik);
    }
    else
    {
        printf("Blad przy wczytywaniu pliku.\n");
        printf("Brak mozliwosci wydania napoju.\n");
        stan->ilosc_wody = 0;
        stan->ilosc_kawy = 0;
        stan->ilosc_mleka = 0;
    }
}
int main()
{
    stan_automatu* stan = NULL;
    kawa_czarna* kawka = NULL;
    kawa_z_mlekiem* biala = NULL;
    gorace_mleko * mleczko = NULL;
    stan = (stan_automatu*)malloc(sizeof(stan_automatu));
    kawka = (kawa_czarna*)malloc(sizeof(kawa_czarna));
    biala = (kawa_z_mlekiem*)malloc(sizeof(kawa_z_mlekiem));
    mleczko = (gorace_mleko*)malloc(sizeof(gorace_mleko));
    wczytaj_dane_na_temat_zasobow("Text1.txt", stan, kawka, biala, mleczko);
    menu(kawka, biala, mleczko, stan);
    wczytaj_dane_na_temat_zasobow2("Text1.txt", stan, kawka, biala, mleczko);
    return 0;
}

