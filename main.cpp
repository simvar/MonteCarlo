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
srand ( unsigned ( time (NULL) ) );
  vector<int> myvector;
  vector<int>::iterator it;
  int a;
  cout << "Iveskite vektorio ligy: ";
  cin>>a; cout<<endl;

  // set some values:
  for (int i=0; i<a; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  random_shuffle ( myvector.begin(), myvector.end(), p_myrandom);

  // print out content:
  cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    cout << " " << *it;

  cout << endl;
//-------------------------------


}
