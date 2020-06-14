#include <iostream>
#include <cmath>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/MacierzObr.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Macierz.hh"
using namespace std;

#define PI 3.14

MacierzObr::MacierzObr()
{
  (*this).jednostkowa();
}

MacierzObr::MacierzObr(double stopnie, char os)
{
  (*this).jednostkowa();
  switch(os)
  {
    case 'z' : 
    {
      tabM[0][0] = cos(stopnie * PI/180);
      tabM[0][1] = -sin(stopnie * PI/180);
      tabM[1][0] = sin(stopnie * PI/180);
      tabM[1][1] = cos(stopnie * PI/180);
      break;
    }
    case 'x' : 
    {
      tabM[1][1] = cos(stopnie * PI/180);
      tabM[1][2] = -sin(stopnie * PI/180);
      tabM[2][1] = sin(stopnie * PI/180);
      tabM[2][2] = cos(stopnie * PI/180);
      break;
    }
    case 'y' : 
    {
      tabM[0][0] = cos(stopnie * PI/180);
      tabM[0][2] = sin(stopnie * PI/180);
      tabM[2][0] = -sin(stopnie * PI/180); 
      tabM[2][2] = cos(stopnie * PI/180);
      break;
    }
    default: 
    {
      cout << "Wprowadziles zla os" << endl;
      exit(1);
      break;
    }
  }
}

/* W sumie to tego jednak nie uzylem
MacierzObr::MacierzObr(const Macierz<double,3> &M) : Macierz<double,3>(M) 
{
  double epsilon = 0.000000001;
  if(abs(tabM[0] * tabM[1]) > epsilon)
  {
    cout << "Macierz nie jest ortonormalna 1" << endl;
    exit(1);
  }
  if(abs(tabM[1] *tabM[2]) > epsilon)
  {
    cout << "Macierz nie jest ortonormalna 2" << endl;
    exit(1);
  }
  if(abs(tabM[0] *tabM[2]) > epsilon)
  {
    cout << "Macierz nie jest ortonormalna 3" << endl;
    exit(1);
  }
  if(abs((*this).wyznacznik_gauss() - 1) > epsilon)
  {
    cout << "Macierz nie jest ortonormalna 4" << endl;
    exit(1);
  }
}*/

