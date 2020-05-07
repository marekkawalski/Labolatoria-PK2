#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void suma(double**tab2d,int liczba, int k)
{
    int i,j;
    double sumka = 0, sumka2 = 0, tmp = 0, tmp2 = 0, maksymalna = 0, tmp3 = 0, tmp6 = 0, minimalna = 0, minimalna2 = 0, maksymalna2 = 0, najcieplejszy = 0, najchlodniejszy = 0;
    int tmp4 = 0, tmp5 = 0;
    for (i = 0; i < liczba; i++)
    {
        double zsumuj = 0;
        for (j = 0; j < k; j++)
        {
            zsumuj+=tab2d[i][j];
            tmp3 = (tab2d[i][6] + tab2d[i][7]) / 2;
            if (tmp3 > maksymalna)
            {
                maksymalna = tmp3;
                tmp4 = i;
            }
            tmp6 = (tab2d[i][0] + tab2d[i][1]) / 2;
            if (tmp6 < minimalna)
            {
                minimalna = tmp6;
                tmp5 = i;
            }
            najcieplejszy =tab2d[i][0];
            if (najcieplejszy > maksymalna2)
            {
                maksymalna2 = najcieplejszy;
            }
            najchlodniejszy = tab2d[i][0];
            if (najchlodniejszy < minimalna2)
            {
                minimalna2 = najchlodniejszy;
            }
        }
        printf("rok %d  %2.3lf\n", 2000 + i, zsumuj / k);
        if (i == 0) 
        { 
            sumka=zsumuj/k;
        }
        else if (i == liczba - 1)
        {
            sumka2 = zsumuj/k;
        }
        if (i <= 9)
        {
            tmp += zsumuj/k;
        }
        else if ((i > 9) && (i <= liczba - 1))
        {
            tmp2 += zsumuj / k;
        }
    }
    printf("Roznica miedzy 2019 a 2000:\n%2.3lf\n", sumka2-sumka);
    printf("Srednie temperatury dziesiecioleci:\n%lf pierwsza dekada\n%lf druga dekada", tmp/10, tmp2/10 );
    if ((tmp4 <= 99) &&(tmp4 >= 10))
    {
        printf("\nRok, kiedy lato bylo najcieplejsze to: 20%d rok", tmp4);
    }
    else if ((tmp4 <= 9) && (tmp4 >= 0))
    {
        printf("\nRok, kiedy lato bylo najcieplejsze to: 200%d rok", tmp4);
    }
    if ((tmp5 <= 99) && (tmp5 >= 10))
    {
        printf("\nRok, kiedy zima byla najchlodniejsza to: 20%d rok", tmp5);
    }
    else if ((tmp5 <= 9) && (tmp5 >= 0))
    {
        printf("\nRok, kiedy lato bylo najcieplejsze to: 200%d rok", tmp5);
    }
    printf("\nRoznica miedzy najcieplejszym a najchlodniejszym styczniem: %2.3lf", maksymalna2 - minimalna2);
}
int main()
{
    FILE*plik = NULL;
    plik=fopen("temp2000.txt", "r");
    if (plik)
    {
        int liczba;
        fscanf(plik, "%d", &liczba);
        printf("%d", liczba);
        printf("\n");
        int w = liczba;
        int k = 12;
        double** tab2d;
        tab2d = malloc(w * sizeof(double));
        int r;
        int i;
        int j; 
        for (r = 0; r < w; r++)
        {
            tab2d[r] = malloc(k * sizeof(double));
        }
            for (i=0 ; i < liczba; i++)
            {
                for (j=0 ; j < k; j++)
                {
                    fscanf(plik, "%lf", &tab2d[i][j]);
                    printf("%3.2lf\t", tab2d[i][j]);                  
                }
                printf("\n");  
            }
            printf("\nSrednie roczne temperatury(w stopniach celsjusza):\n");
            suma(tab2d, liczba, k);

        for (i = 0; i < w; i++)
        {
            free(tab2d[i]);
        }
        free(tab2d);
        tab2d = NULL;
        fclose(plik);
    }
    else
        printf("Blad pliku\n");
    return 0;
}
