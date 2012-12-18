#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include "SixHumpCamel.h"



//------------------------------------
#define N 2
using namespace std;
//------------------------------------
//------------------------------------
struct point {
double x[2];
double f;
};


//------------------------------------
// Vektoriaus begalines (max) normos funkcijos deklaracija
double Vector_Max_Norm(double v[], int n);

// Greiciausio nusileidimo (angl. Steepest Descent) metodo deklaracija
int  Steepest_Descent(double (*f)(double *), void (*df)(double *, double *),
     int (*stopping_rule)(double*, double, double*, double, double*, int, int),
                          double a[], double *fa, double *dfa, double cutoff,
						double cutoff_scale_factor, double tolerance, int n);



						int Newton_Raphson_ndim( void (*f)(double*, double*),
                            void (*df)(double*, double*, double*),
                            int (*Stopping_Rule)(double*, double*, int, int),
                                                 double *a, double *fa, int n);

// Generuoja atsitiktini realu skaiciu tarp dLow and dHigh
double GetRandomNumber(double dLow, double dHigh){
    return static_cast<double>(rand())/RAND_MAX*(dHigh-dLow) + dLow;
}

// Apskaiciuoja Six-hump Camel Back funkcijos reiksme taske x
//double SixHumpCamelBack(double *x);
/*
double SixHumpCamelBack(double *x){
    return (4-2.1*x[0]*x[0]+x[0]*x[0]*x[0]*x[0]/3)*x[0]*x[0] + x[0]*x[1] +
    (-4+4*x[1]*x[1])*x[1]*x[1];
}
*/
// Apskaiciuoja Six-hump Camel Back gradiento reiksme taske x

void SixHumpCamelBackGradient(double *x, double *fGrad){
    fGrad[0] = 8*x[0]-8.4*x[0]*x[0]*x[0]+2*x[0]*x[0]*x[0]*x[0]*x[0]+x[1];
    fGrad[1] = x[0]-8*x[1]+16*x[1]*x[1]*x[1];
}


// Algoritmo sustojimo salyga kontroliuojanti funkcija
int StoppingRule(double* a, double fa, double* x, double fx, double* dfa, int
iteration, int n){
	double fEps = abs(fx - fa); // Funkcijos reiksmiu skirtumas
	double xa[n];
	for(int i = 0; i < n; ++i) xa[i] = x[i]-a[i];
	double xEps = Vector_Max_Norm(xa, 2); // Argumento skirtumo norma
	double dfaEps = Vector_Max_Norm(dfa, 2); // Gradiento norma
	if(iteration > 3)
		return -6;
	else
		return 0;
}
//--------------------------
//--------------------------
/*
 void SixHumpCamelBackk(double *x, double *y)
 {

 }
 void SixHumpCamelBackGradientt(double*, double*, double*)
 {

 }
 int StoppingRulee(double*, double*, int, int)
 {

 }
 */
//------------------------------------
//------------------------------------
//------------------------------------
//Six hump camel back funkcijos realizacija
double sixhump(double * x)
{
    double f = (4-2.1*x[0]*x[0]+pow(x[0],4.0)/3)*x[0]*x[0] + x[0]*x[1] + (-4 + 4*x[1]*x[1])*x[1]*x[1];
    return f;
}

double f_prime(double x_old,double x_new){
        double f = (4-2.1*x_old*x_old+pow(x_old,4.0)/3)*x_old*x_old + x_old*x_new + (-4 + 4*x_new*x_new)*x_new*x_new;
        f=-f;
        return f;
}


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

    double virsutinis_rezis1, apatinis_rezis1,virsutinis_rezis2, apatinis_rezis2; // apsirasome intervalo rezius
    apatinis_rezis1=-1.9;
    virsutinis_rezis1=1.9;
    apatinis_rezis2=-1.1;
    virsutinis_rezis2=1.1;
    vector<double> skaiciai(100);
    vector<point> xx(100);



    for(int j=0;j<100;j++)
    {
        n=2;
        vector<double> vektorius(n);
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
        xx[j].x[0] = vektorius[0];
        xx[j].x[1] = vektorius[1];
    }
//-------------------------------------------
// Paieðka
    double max = skaiciai[0]; // prielaida didþiausiam elementui
    double imax = 0; // jei pirmasis elementas toks ir bus – jo vieta yra 0
    double ma1= xx[0].x[0];
    double ma2= xx[0].x[1];
    double min = skaiciai[0]; // prielaidos maþiausiam elementui ...
    double imin = 0; // ir jo vietai masyve
    double mi1= xx[0].x[0];
    double mi2= xx[0].x[1];
    double precision = 0.0001;
    for( int i = 0; i < 100; i++ )
    { // ciklà dabar galima pradëti nuo antrojo elemento
        if( skaiciai[i] > max )
        {
            max = skaiciai[i];
            imax = i;
            ma1= xx[i].x[0];
            ma2= xx[i].x[1];
        }
        if( skaiciai[i] < min )
        {
            min = skaiciai[i];
            imin = i;
            mi1= xx[i].x[0];
            mi2= xx[i].x[1];
        }
    }
//--------------
    double vid, sum=0;
    for( int i = 0; i < 100; i++ )
        {
        sum=sum+skaiciai[i];
        }
    vid=sum/100;
//----------------
// Rezultatø spausdinimas
    cout<<"\nRezultatai\n";
    cout<<"Didziausias elementas yra "<<max<<", jo vieta yra "<<imax+1<<" x["<<imax+1<<"][0]="<<ma1<<" x["<<imax+1<<"][1]="<<ma2<<endl;
    cout<<"Maziausias elementas yra "<<min<<", jo vieta yra "<<imin+1<<" x["<<imin+1<<"][0]="<<mi1<<" x["<<imin+1<<"][1]="<<mi2<<endl;
//
    cout<<"100-to Six hump funkcijos reiksmiu vidurkis : "<<vid<<endl;
    system("pause");
//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
//----Pajieska su salyga
  //  double *skaiciai2,*temp, *elm, *temp2;
   // skaiciai2=(double*)malloc(sizeof(double));
   // elm=(double*)malloc(sizeof(double));
   vector<double> skaiciai2(0);
   vector<double> elm(0);

    int ii=0, iii=0;


    while (abs(-1.031628453-min)>precision)
        {
            n=2;
            vector<double> vektorius(n);
            vektorius[0] = rand() * (virsutinis_rezis1 - apatinis_rezis1) / RAND_MAX + apatinis_rezis1;
            vektorius[1] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
        //    skaiciai2[ii]=sixhump(&vektorius[0]);
     /*      temp=(double*)realloc(skaiciai2,(ii+2)*sizeof(double));
          if ( temp != NULL )
            {
                 skaiciai2=temp;
            }
                else {
                   free(skaiciai2);
                   printf("Error allocating memory!\n");
                    return 0;
            }
            */
            skaiciai2.push_back(sixhump(&vektorius[0]));
            if( skaiciai2[ii] < min )
            {
                min = skaiciai2[ii];
//-------------------------
                elm.push_back(min);
               // elm[iii]=min;
      /*          temp2=(double*)realloc(elm,(iii+2)*sizeof(double));
                if ( temp2 != NULL )
                {
                    elm=temp2;
                }
                else
                {
                    free(elm);
                    printf("Error allocating memory!\n");
                    return 0;
                }
                */
                iii++;
//-------------------------
                imin = ii;
                mi1=  vektorius[0];
                mi2= vektorius[1];
            }
//else{double minn=min;}
            ii++;
        }

    cout<<"Maziausias elementas yra "<<min<<", jo vieta yra "<<imin+1<<" x["<<imin+1<<"][0]="<<mi1<<" x["<<imin+1<<"][1]="<<mi2<<endl;

    int j=1;

    if(iii<6)
        for(int i=0;i<iii;i++)
            {
                cout<<j<<"-as maziausias elementas :"<< elm[i]<<endl;
                j++;
            }
            else for(int i=iii-1;i>iii-6;i--)
                {
                    cout<<j<<"-as maziausias elementas :"<< elm[i]<<endl;
                    j++;
                }
                /*
    cout<<"\n"<< "Lokalusis minimumas yra: "<< elm[0] <<endl;
    cout<<endl;
    cout << "xMin = (" << mi1<< ", " << mi2<< ")" << endl;
    cout << "f(xMin) = " << elm[0] << endl;
    cout<<endl;
    */
   //-----------------------------------
    double x_old = elm[0];
    double x_new = elm[1]; // The algorithm starts at x=6
    double eps = 0.01; // step size
    precision = precision/100;
    while (abs(x_new - x_old) > precision)
    {
        x_old = x_new;
        x_new = x_old - eps * f_prime(x_old,x_new);
    }

    cout<<"\n"<< "Lokalusis minimumas yra: "<< x_new<<endl;

    cout<<endl;
    cout << "xMin = (" << mi1<< ", " << mi2<< ")" << endl;
    cout << "f(xMin) = " << x_new << endl;
    cout<<endl;
//------------------------------------
//------------------------------------
//------------------------------------
    double region[] = {-1.9, 1.9, -1.1, 1.1};
	double a[N] = {0.0, 1.0}; // N-matis Vektorius
	/*srand(time(0)); // Naudoja vis kita seed'a
	double a[N]; // N-matis Vektorius
	for(int i = 0; i < N; ++i){
        a[i] = GetRandomNumber(region[2*i], region[2*i+1]);
    }*/
	double fa = SixHumpCamel(a); // Funkcijos reiksme pradiniame taske a
	double dfa[N];
	SixHumpCamelBackGradient(a, dfa); // Funkcijos gradiento reiksme taske a
	double cutoff = 1.0, cutoff_scale_factor = 1.0; // Pap. parametrai
	double tolerance = 0.01;
	int err = Steepest_Descent( SixHumpCamel, SixHumpCamelBackGradient, StoppingRule,
    a, &fa, dfa, cutoff, cutoff_scale_factor, tolerance, N);
	switch (err)
	{
		case 0:
			cout << "Success" << endl;
			break;
		case -1:
			cout << "In the line search three points are collinear." << endl;
			break;
		case -2:
			cout << "In the line search the extremum of the parabola through the three points is a maximum." << endl;
			break;
		case -3:
			cout << "Int the line search the initial points failed to satisfy the condition that x1 < x2 < x3 and fx1 > fx2 < fx3." << endl;
			break;
		case -4:
			cout << "Not enough HEAP memory." << endl;
			break;
		case -5:
			cout << "The gradient evaluated at the initial point vanishes." << endl;
		case -6:
			cout << "Exceed maximal number of iterations." << endl;
		break;
	}

	cout << "Greiciausio nusileidimo (angl. Steepest Descent) metodu" << endl;
	cout<<endl;
	cout << "surastas sprendinys yra:" << endl;
	cout << "xMin = (" << a[0] << ", " << a[1] << ")" << endl;
	cout << "f(xMin) = " << fa << endl;





//------------------------------------
//------------------------------------
//------------------------------------
//------------------------------------
//------------------------------------
//------------------------------------
/*
	 err = Newton_Raphson_ndim( SixHumpCamelBackk, SixHumpCamelBackGradientt, StoppingRulee, a, &fa, N);
	switch (err)
	{
		case 0:
			cout << "Success" << endl;
			break;
		case -1:
			cout << "In the line search three points are collinear." << endl;
			break;
		case -2:
			cout << "In the line search the extremum of the parabola through the three points is a maximum." << endl;
			break;
		case -3:
			cout << "Int the line search the initial points failed to satisfy the condition that x1 < x2 < x3 and fx1 > fx2 < fx3." << endl;
			break;
		case -4:
			cout << "Not enough HEAP memory." << endl;
			break;
		case -5:
			cout << "The gradient evaluated at the initial point vanishes." << endl;
		case -6:
			cout << "Exceed maximal number of iterations." << endl;
		break;
	}
	cout << "Greiciausio nusileidimo (angl. Steepest Descent) metodu" << endl;
	cout<<endl;
	cout << "surastas sprendinys yra:" << endl;
	cout << "xMin = (" << a[0] << ", " << a[1] << ")" << endl;
	cout << "f(xMin) = " << fa << endl;

*/



//------------------------------------
//------------------------------------
//------------------------------------

    system("pause");
    return 0;
}
