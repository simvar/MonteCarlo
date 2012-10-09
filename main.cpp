#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// random generator function:
ptrdiff_t myrandom (ptrdiff_t i) { return rand()%i;}

// pointer object to it:
ptrdiff_t (*p_myrandom)(ptrdiff_t) = myrandom;


int main()
{

//---genereavimas
srand((unsigned)time(0));
int rint1, rint2, rint3;
rint1 = (rand()%10)+1;
rint2 = (rand()%10)+1;
rint3 = (rand()%10)+1;
cout <<"x= "<< rint1 << endl;
cout <<"y= "<< rint2 << endl;
cout <<"z= "<< rint3 << endl;

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
    cout << "Iveskite vektoriaus ilgy:";
    cin >> n; cout<< endl;

    double vektorius[n];

    for(int i=0; i<n; i++)
    {
        vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
        cout << i+1 << ". " << vektorius[i] << endl; // Vektoriaus isvedimas i ekrana
    }

    return 0;
//-------------------------------


}
