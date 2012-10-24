#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <ctime>

//Six hump camel back funkcijos realizacija
double sixhump(double * x)
{
    double f = (4-2.1*x[0]*x[0]+pow(x[0],4.0)/3)*x[0]*x[0] + x[0]*x[1] + (-4 + 4*x[1]*x[1])*x[1]*x[1];
    return f;
}

using namespace std;
int main()
{
     srand(time(0));
    cout << "Monte Carlo realizacijos pradzia" << endl;
    cout << "(RANDOM SEARCH METHOD)" << endl;
    // Kintamuju apsirasymas
    double f, x; // Funkcijos reiksmes ir argumentas x
    int n; // Uzedavinio dimensija
    double xSprendinys; // Argumento reiksme
    int fSprendinys; // Uzdavinio sprendinys

    // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

    double virsutinis_rezis1, apatinis_rezis1,virsutinis_rezis2, apatinis_rezis2; // apsirasome intervalo rezius

/*
    cout << "Iveskite inervalo apatiny ir virsutiny rezius: ";
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout << "Iveskite vektoriaus dimensija (n): ";
    cin >> n;
 */




    apatinis_rezis1=-1.9;
    virsutinis_rezis1=1.9;
    apatinis_rezis2=-1.1;
    virsutinis_rezis2=1.1;
   double skaiciai[100];
    double xx[100][2];



for(int j=0;j<100;j++)
{
    n=2;
    double vektorius[n];

    cout << "x["<<j+1<<"] = ( ";
    //for(int i=0; i<n; i++)
    //{
        vektorius[0] = rand() * (virsutinis_rezis1 - apatinis_rezis1) / RAND_MAX + apatinis_rezis1;
        vektorius[1] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
   // }
    for(int i=0; i<n; i++)
    {
        cout << vektorius[i] << " "; // Vektoriaus isvedimas i ekrana
    }
    cout << ") --> "<<sixhump(&vektorius[0])<< endl;
    skaiciai[j]=sixhump(&vektorius[0]);
    xx[j][0] = vektorius[0];
    xx[j][1] = vektorius[1];
    //cout << "Six hump funkcijos reiksme siame taske: " << sixhump(&vektorius[0]) << endl;
   // system("pause>nul");
}
//-------------------------------------------
// Paie�ka
double max = skaiciai[0]; // prielaida did�iausiam elementui
double imax = 0; // jei pirmasis elementas toks ir bus � jo vieta yra 0
 double ma1= xx[0][0];
 double ma2= xx[0][1];
double min = skaiciai[0]; // prielaidos ma�iausiam elementui ...
double imin = 0; // ir jo vietai masyve
 double mi1= xx[0][0];
 double mi2= xx[0][1];
for( int i = 0; i < 100; i++ ){ // cikl� dabar galima prad�ti nuo antrojo elemento
if( skaiciai[i] > max ) {
max = skaiciai[i];
imax = i;
  ma1= xx[i][0];
  ma2= xx[i][1];
}
if( skaiciai[i] < min ) {
min = skaiciai[i];
imin = i;
  mi1= xx[i][0];
  mi2= xx[i][1];
}
}
//--------------
double vid, sum=0;
for( int i = 0; i < 100; i++ ){
    sum=sum+skaiciai[i];
}
vid=sum/100;
//----------------
// Rezultat� spausdinimas
cout<<"\nRezultatai\n";
cout<<"Didziausias elementas yra "<<max<<", jo vieta yra "<<imax+1<<" x["<<imax+1<<"][0]="<<ma1<<" x["<<imax+1<<"][1]="<<ma2<<endl;
cout<<"Maziausias elementas yra "<<min<<", jo vieta yra "<<imin+1<<" x["<<imin+1<<"][0]="<<mi1<<" x["<<imin+1<<"][1]="<<mi2<<endl;
//
cout<<"100-to Six hump funkcijos reiksmiu vidurkis : "<<vid<<endl;
//-----------------------------------------------
//----Pajieska su salyga
    double *skaiciai2,*temp, *elm, *temp2;
    skaiciai2=(double*)malloc(sizeof(double));
    elm=(double*)malloc(sizeof(double));
 /*
  max = skaiciai[0]; // prielaida did�iausiam elementui
 imax = 0; // jei pirmasis elementas toks ir bus � jo vieta yra 0
  ma1= xx[0][0];
  ma2= xx[0][1];
 min = skaiciai[0]; // prielaidos ma�iausiam elementui ...
 imin = 0; // ir jo vietai masyve
  mi1= xx[0][0];
  mi2= xx[0][1];
  */
int ii=0, iii=0;


while (abs(-1.031628453-min)>0.0001)
{
                    n=2;
    double vektorius[n];
        vektorius[0] = rand() * (virsutinis_rezis1 - apatinis_rezis1) / RAND_MAX + apatinis_rezis1;
        vektorius[1] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
    skaiciai2[ii]=sixhump(&vektorius[0]);
cout<<"Minimumas "<<min<<endl;
//system("pause");
  //skaiciai2[ii]=skaiciai[ii]; /* put the character into the skaiciai array */
                temp=(double*)realloc(skaiciai2,(ii+2)*sizeof(double)); /* give the pointer some memory */
                if ( temp != NULL ) {
                        skaiciai2=temp;
                } else {
                        free(skaiciai2);
                        printf("Error allocating memory!\n");
                        return 0;
                }

if( skaiciai2[ii] < min ) {
min = skaiciai2[ii];
//-------------------------
elm[iii]=min;
temp2=(double*)realloc(elm,(iii+2)*sizeof(double)); /* give the pointer some memory */
                if ( temp2 != NULL ) {
                        elm=temp2;
                } else {
                        free(elm);
                        printf("Error allocating memory!\n");
                        return 0;
                }
  iii++;
//-------------------------
imin = ii;
  mi1=  vektorius[0];
  mi2= vektorius[1];
}
//else{double minn=min;}
ii++;
}
//----------------------------
/*elm[iii]=skaiciai2[ii];

temp2=(double*)realloc(elm,(iii+2)*sizeof(double));
                if ( temp2 != NULL ) {
                        elm=temp2;
                } else {
                        free(elm);
                        printf("Error allocating memory!\n");
                        return 0;
                }
*/
//-----------------------------
cout<<"Maziausias elementas yra "<<min<<", jo vieta yra "<<imin+1<<" x["<<imin+1<<"][0]="<<mi1<<" x["<<imin+1<<"][1]="<<mi2<<endl;
for(int i=0;i<iii;i++)
{
    cout<<i<<"-as maziausias elementas :"<< elm[i]<<endl;
}
    //vektorius[0] = 0.089842; vektorius[1] = -0.7126546;
   // cout << "Six hump funkcijos reiksme minimumo taske: " << sixhump(&vektorius[0]) << endl;
   system("pause");
    return 0;
}
