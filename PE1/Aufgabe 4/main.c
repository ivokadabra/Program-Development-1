
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//DEKLARATION DER FUNKTIONEN
double cross_produkt(double *x ,double  *y ,int anzahlPunkte);
double schwerpunkt_x(double *a,double *b ,double A,int n);
double schwerpunkt_y(double *a ,double *b,double B,int n);
void ausgabe_Koordinaten(double *x, double *y);
void Eingabe(double testx,double testy);
//*************MAIN*************
int main()
{

	// variables for reading the measurements from file
	FILE * fp;
	size_t len = 0;
    char resp;

    double x, y;
  double *y_Koordinate=(double*)malloc(1000*sizeof(double));
  double *x_Koordinate=(double*)malloc(1000*sizeof(double));
  double *vertx=(double*)malloc(1000*sizeof(double));
  double *verty=(double*)malloc(1000*sizeof(double));
double testx;
double testy;

  int count;
  int c;
  int n;

	// open the input file "messwerte.txt" for reading
	fp = fopen("polygon.txt", "r");
	if (fp == NULL)
	{
		// if file could not be opened (wrong path, not readable, ...)
		// output a short message and immediately exit
		printf("Eingabedatei kann nicht geoeffnet werden.\n");
		scanf("%c", &resp);
		exit(EXIT_FAILURE);
	}



	// print program header
	printf("\n\nProgramm zur Berechnung eines Polygons\n");
	printf("--------------------------------------------------------\n");

    int i=0;
	while (1)
	{
    	len = fscanf(fp, "%lf %lf", &x, &y);

    	x_Koordinate[i]=x;
    	y_Koordinate[i]=y;

    	i++;


        if (len == EOF)
            break;
        else if (len == 0) {
            printf("Unerwartetes Zeichen in der Eingabedatei.");
    		scanf("%c", &resp);
    		exit(EXIT_FAILURE);
        }


	}
ausgabe_Koordinaten(x_Koordinate,y_Koordinate);

    	 for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;




	// output results

	printf("\nErgebnisse:\n");
	printf("-----------\n\n");
	printf("Oberflaeche der Figur =  %.2lf",cross_produkt( x_Koordinate, y_Koordinate, count));
	double area=cross_produkt(x_Koordinate, y_Koordinate, count);
	printf ("Der Schwerpunkt des x_KOOrdinate ist:%.2lf\n",schwerpunkt_x(x_Koordinate,y_Koordinate,area,count));
	printf ("Der Schwerpunkt des y_KOOrdinate ist:%.2lf\n",schwerpunkt_y(x_Koordinate,y_Koordinate,area,count));




Eingabe(testx,testy);
test(count ,x_Koordinate,y_Koordinate, testx,testy);

free(x_Koordinate);
free(y_Koordinate);
	// finally close the input file and clean up memory
	fclose(fp);

	// wait for user input before closing terminal
	scanf("%c", &resp);
}
//*********END MAIN**************

//BERECHNUNG DER FLÄCHE
double cross_produkt(double *x ,double  *y ,int anzahlPunkte){

  double sum =0;
  double gum =0;
  double obshto=0;

  for(int i = 0; i < anzahlPunkte; i++){
    if (i+1==anzahlPunkte){
      sum =x[anzahlPunkte-1]-x[0];
      gum =(y[anzahlPunkte-1]+y[0])/(double)2;
    }

    sum =x[i]-x[i+1];
    gum =(y[i]+y[i+1])/(double)2;

    obshto+=gum *sum;
    printf("\n");
 }
 // obshto=fabs(obshto);
 if(obshto<0) obshto=-obshto;
 return obshto;
}
//X-KOORDINATE SCHWERPUNKT
double schwerpunkt_x(double *a,double *b,double A,int n){
double cx=0;
double t;

for (int i=0; i<n; i++) {
  t = a[i]*b[i+1] - a[i+1]*b[i];
  cx += (a[i]+a[i+1]) * t;

}
cx = cx / (6.0 * A);

return cx;
}
//Y-KOORDINATE SCHWERPUNKT
double schwerpunkt_y(double *a ,double *b,double B,int n){
double cy=0;
double t;

for (int i=0; i<n; i++) {
  t = a[i]*b[i+1] - a[i+1]*b[i];
  cy += (b[i]+b[i+1]) * t;

}

cy = cy / (6.0 * B);

return cy;
}
//EINGABE FÜR TESTPUNKTE
void Eingabe(double testx,double testy){

printf ("Geben sie testpoint X:");
scanf("%f",&testx);
printf ("Geben sie testpoint Y:");
scanf("%f",&testy);


}
//BERECHNUNG DER TESPUNKTEN
void test(int nvert ,int *vertx,int *verty,float testx,float testy){



int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
	 (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;

  }

  printf ("Punkt im Polygon(1=liegt,0 nicht): %d",c);

}


//ZÄHLER FÜR DIE GELESENEN ZAHLEN
void ausgabe_Koordinaten(double *x, double *y){
    int counter=0;
    while(x[counter]){
        counter++;
    }
    for(int i=0; i<counter; i++){
        printf("Punkt %d ( %.2lf ; %.2lf )\n",i+1 , x[i], y[i] );
    }
}



