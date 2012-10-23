#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

double sixhump (double * x)
{
    double f=(4-2.1*x[0]*x[0]+pow(x[0],4.0)/3)*x[0]*x[0]+x[0]*x[1]+(-4+4*x[1])*x[1];
    return f;
}

using namespace std;

// random generator function:
ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}

// pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;


int main()
{


//-----vektorius 1-----
    cout << "Monte Carlo realizacijos pradzia" << endl;
    cout << "(RANDOM SEARCH METHOD)" << endl;
    // Kintamuju apsirasymas
    double f, x; // Funkcijos reiksmes ir argumentas x
    int n; // Uzedavinio dimensija
    double xSprendinys; // Argumento reiksme
    int fSprendinys; // Uzdavinio sprendinys

    // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

    double virsutinis_rezis, apatinis_rezis; // apsirasome intervalo rezius

    cout << "Iveskite inervalo rerzius: ";
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout <<endl;
    cout << "Iveskite vektoriaus ilgy: ";
    cin >> n; cout<< endl;

    double vektorius[n];
cout<<"x= { ";


    for(int i=0; i<n; i++)
    {
        vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
    }
     for(int i=0; i<n; i++)
    {
cout  << vektorius[i] <<" "; // Vektoriaus isvedimas i ekrana
    }
    cout<<"}"<<endl;
    cout<<"Six hump funkcios reiksme siame taske "<<sixhump (&vektorius[0])<<endl;
    vektorius[0]=0.089842;
    vektorius[1]=-0.712656;
    cout<<"Six hump funkcios reiksme siame taske "<<sixhump (&vektorius[0])<<endl;
    return 0;
//-------------------------------


}
