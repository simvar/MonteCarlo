#include <iostream>
#include <cstdlib>
#include <cmath>
//Six hump camel back funkcijos realizacija
double sixhump(double * x)
{
    double f = (4-2.1*x[0]*x[0]+pow(x[0],4.0)/3)*x[0]*x[0] + x[0]*x[1] + (-4 + 4*x[1]*x[1])*x[1]*x[1];
    return f;
}

using namespace std;
int main()
{
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
// Paieðka
double max = skaiciai[0]; // prielaida didþiausiam elementui
double imax = 0; // jei pirmasis elementas toks ir bus – jo vieta yra 0
 double ma1= xx[0][0];
 double ma2= xx[0][1];
double min = skaiciai[0]; // prielaidos maþiausiam elementui ...
double imin = 0; // ir jo vietai masyve
 double mi1= xx[0][0];
 double mi2= xx[0][1];
for( int i = 1; i < 100; i++ ){ // ciklà dabar galima pradëti nuo antrojo elemento
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
// Rezultatø spausdinimas
cout<<"\nRezultatai\n";
cout<<"Didziausias elementas yra "<<max<<", jo vieta yra "<<imax+1<<" x["<<imax+1<<"][0]="<<ma1<<" x["<<imax+1<<"][1]="<<ma2<<endl;
cout<<"Maziausias elementas yra "<<min<<", jo vieta yra "<<imin+1<<" x["<<imin+1<<"][0]="<<mi1<<" x["<<imin+1<<"][1]="<<mi2<<endl;
//
//-----------------------------------------------
    //vektorius[0] = 0.089842; vektorius[1] = -0.7126546;
   // cout << "Six hump funkcijos reiksme minimumo taske: " << sixhump(&vektorius[0]) << endl;
    return 0;
}
