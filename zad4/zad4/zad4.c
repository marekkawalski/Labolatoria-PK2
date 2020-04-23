#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void wczytaj_plik(const char*filename, char*phrase)
{
    FILE* plik = fopen(filename,"r");
    if (plik)
    {
        char buf[100] = { 0 };
        int lineCount = 0;
        while (!feof(plik))
        {
            if (buf[strlen(buf) - 1] == '\n')
            {
                lineCount++;
            }
            char* s = fgets(buf, 100, plik);
            char tmp[50];
            char tmp2[50];
            int i = 0;
            for (int w = 0; w < 100; w++)
            {
                if (buf[w]==phrase[i])
                {
                    tmp[i]=buf[w];
                    i++;
                    if (strncmp(tmp, phrase,sizeof(phrase)+1) == 0)
                    {
                        strcpy(tmp2,tmp);
                    }
                }
                else 
                {
                    for (int t = 0; t <50; t++)
                    {
                        tmp[t] = 0;
                    }
                    i = 0;
                }
            }
            if (strncmp(tmp2, phrase, sizeof(phrase)+1) == 0)
            {
                printf("\"%s\"     znajduje sie w linii numer: %d\n",phrase, lineCount+1 );
            }
            else
            {
                printf("\"%s\" Nie znajduje sie w linii numer: %d\n", phrase, lineCount + 1);
            }
         for(int t=0; t<50;t++)
         {
             tmp[t] = 0;
             tmp2[t] = 0;
         } 
        }
      fclose(plik);
    }
    else printf("Blad przy otwieraniu pliku.\n");
}
bool check_call(int argc, char* argv[], const char*nazwa_pliku, char*slowo)
{
    int good = 0;
    for (int i = 0; i < argc; i++)
    {
        char*a = argv[i];
        char* b = "-d";
        if (strcmp(a, b)==0)
        {
            strcpy(nazwa_pliku,argv[i + 1]);
            i++;
            good++;
        }
        char* c = "-t";
        if (strcmp(a,c)==0)
        {
            strcpy(slowo,argv[i + 1]);
            i++;
            good++;
        }
    }
    if (good == 2)
        return true;
    else return false;
}
int main(int argc, char* argv[])
{        
    char szukany[20], nazwa_pliku[20];
    bool k = check_call(argc,argv,nazwa_pliku, szukany);
    if (k == true)
    {
        wczytaj_plik(nazwa_pliku, szukany);
    }
    else printf("Cos poszlo nie tak.\n");
    return 0;
}

