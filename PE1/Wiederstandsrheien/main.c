#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int read_e_series()
{
    while (1)
    {
        int n;
        printf("\n\tBitte geben Sie die Nr. der E-Reihe an: ");
        scanf("%i", &n);
        while (getchar() != '\n')
            ;

        if (n == 6 || n == 12 || n == 24 || n == 48 || n == 96 || n == 192)
            return n;

        printf("\n\nungueltige Eingabe (%i)!\n\n", n);
        printf("gueltige Werte: 6, 12, 24, 48, 96, 192!\n\n");
    }
}

int read_decade()
{

    float n;
    printf("\n\tBitte geben Sie den Dekadenfaktor an: ");
    scanf("%f", &n);

    if (n >= 1 && n <= 10)
    {
        n = 0;
    }
    else if (n >= 10 && n <= 100)
    {
        n = 1;
    }
    else if (n >= 100 && n <= 1000)
    {
        n = 2;
    }
    else if (n == 0 || n > 1000)
    {
        read_decade();
    }

    //while (getchar() != '\n');
    return n;
}
int c(int colorr){
return colorr;
}

float toleranz(int e_series,int color )
{
    int e = e_series;
    float tol = 0;

    switch (e)
    {
    case 6:
        tol = (float)20 / (float)100;
        color = 0;
        break;
    case 12:
        tol = (float)10 / (float)100;
        color = 1;
        break;
    case 24:
        tol = (float)5 / (float)100;
        color = 2;
        break;
    case 48:
        tol = (float)2 / (float)100;
        color = 3;
        break;
    case 96:
        tol = (float)1 / (float)100;
        color = 4;
        break;
    case 192:
        tol = (float)0, 5 / (float)100;
        color = 5;
        break;
    }
    printf("%d",color);
    return tol;
}
/*int prozent_color(int prozent){
char toleran_color[]={""}
}*/




int counter(int zahl)
{
    int T = zahl;
    int counter = 0;

    for (int i = 0; T != 0; i++)
    {
        T /= 10;
        counter++;
    }
    return counter;
}

int farbcode(int zahl, float prozent)
{
    int T = zahl;
    int T1;
    int digitCount = counter(zahl);
    int *d = malloc(digitCount * sizeof(int));
    char *farbe[10] = {"schwartz", "braun", "rot", "orange", "gelb", "grün", "blau", "Lila", "grau", "weiß"};
    char *farbe2[8] = {"gold", "schwartz", "braun", "rot", "orange", "gelb", "grün", "blau"};

    for (int i = 0; T != 0; i++)
    {
        T1 = T % 10;
        T /= 10;
        d[i] = T1;
        //printf ("%d",d[i]);
    }

    printf("Colors: ");
    for (int j = digitCount - 1; j >= 0; j--)
    {
        printf("%s ", farbe[d[j]]);
    }
    if (digitCount > 7)
    {
        printf("\nMultiplier: blau ");
    }
    else
    {
        printf("\nMultiplier: %s ", farbe2[digitCount]);
    }
    printf("\nPercentage: %s ", &farbe[(int)prozent]);
    free(d);
}

#define LOWER_BOUND 0
#define SET_VALUE 1
#define UPPER_BOUND 2

int main()
{
    printf("\n\nProgramm zur Berechnung von Widerstandsreihen\n");
    printf("--------------------------------------------------------\n");

    int spalte = 0;
    int e_series = read_e_series();
    int decade = read_decade();
    int colorr;
    int color=c(colorr);
    float prozent = toleranz(e_series,color);
    float R;
    int zahl;
int c;
    //char *farbe[10]={"schwartz","braun","rot","orange","gelb","grün","blau","Lila","grau","weiß"};
    for (int i = 0; i < e_series; i++)
    {
        R = (float)pow((float)10, (float)1 / e_series);
        R = pow(R, i);
        R *= pow(10, decade);
        for (spalte = 0; spalte < 3; spalte++)
        {
            float R1 = R;

            if (spalte == 0)
            {
                R1 = R1 - R1 * prozent;
            }
            else if (spalte == 1)
            {
                R1 = R1;
            }
            else if (spalte == 2)
            {
                R1 = R1 + R1 * prozent;
            }

            printf("%f|", R1);
        }
        printf("\n");
    }
    printf("Wählen sie bitte einen Wert:");
    scanf("%i", &zahl);
    //printf ("%i",farbcode(zahl));
    farbcode(zahl, prozent);
}
