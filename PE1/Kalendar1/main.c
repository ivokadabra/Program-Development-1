#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned jahr,tag,monat;

    int sum=0;
    int Days_in_Months[]={31,28,31,30,30,31,30,31,30,31,30,31};
    char* day_in_week[]={"Sonntag","Montag","Diesnstag","Mittwoch","Donnerstag","Fritag","Samstag"};
    int days;

    printf("Geben sie Datum ein: [TT.MM.JJ] ");
    scanf("%d.%d.%d",&tag,&monat,&jahr);
    if ((tag<1||tag>Days_in_Months[monat])||(monat<1||monat>12)||(jahr<1901||jahr>2100)){
        printf("Neuer Wahl: ");
            scanf("%d.%d.%d",&tag,&monat,&jahr);
    }
    if((jahr%100 != 0 && jahr%4 == 0) || jahr%400 == 0){
    printf("Jahr ist ein Schaltjahr! ");
    Days_in_Months[1]=29;}
    else
    printf("Jahr ist kein Schaltjahr! ");


    int monat1=monat-1;
    for(int months=0;months<monat1;months++){
        sum=sum+Days_in_Months[months];

    }

int rest(int jahr){
    int jahr1=0;
    jahr1=jahr%100;


return jahr1;
}
int century(int jahr){
    int jahr2 = 0;
            while(jahr>=10){
                jahr2=jahr/10;
                jahr/=10;}
return jahr2;
}

int basic(int monat, int jahr,int monat1){
    int date = 0;
    int jahra = rest(jahr);
    int j=century(jahr);
    int century_code[]={1,0,6};
    int monat_code[]={0,3,3,6,1,4,6,2,5,0,3,5};
    date=monat+monat_code[monat1]+jahra+(jahra/4)+ century_code[j];
return date;
}

int finale(){
    int kamp;
    int a = basic(monat, jahr,monat1);
    kamp=a%7;
return kamp;
}



int Kalendar_woche(){
   int Alle_woche=52;
   int diese_woche;
   int tage=365;
   if (Days_in_Months[1]=29){
    tage=366;
   }

   if (days=4){
    Alle_woche=53;
   }
    diese_woche=(Alle_woche*(sum+tag))/365;
    return diese_woche;
}


printf("\nDer  wievielte Tag des Jahres ist: %d \n",sum+tag);
days = (((jahr - 1)*365) + ((jahr - 1) / 4) - ((jahr - 1) / 100) + ((jahr) / 400) + 1) % 7;
printf("Erste Januar ist: %s \n",day_in_week[days]);
printf("Der Wochentag ist: %s ",day_in_week[finale()]);
printf("\nNummer der Kalendarwoche:%d",Kalendar_woche()+1);

return 0;

}
