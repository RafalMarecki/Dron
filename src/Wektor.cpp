#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wektor.hh"
#include <iostream>
#include <cmath>
using namespace std;

template <class TYP, int ROZM>
Wektor<TYP, ROZM>::Wektor(TYP x, TYP y, TYP z)
{
    tabW[0]=x;
    tabW[1]=y;
    tabW[2]=z;
}

template <class TYP, int ROZM>
Wektor<TYP, ROZM>::Wektor()
{
    for (int i=0; i<ROZM; i++)
    {
        tabW[i]=0;
    }
}

template <class TYP, int ROZM>
TYP & Wektor<TYP, ROZM>::operator[](int i) 
{
    if(i<0 || i>=ROZM)
    {
        cerr<<"Blad-jestes poza tablica!";
        exit(1);
    }
    return tabW[i];
}

template <class TYP, int ROZM>
const TYP & Wektor<TYP, ROZM>::operator[](int i) const
{
    if(i<0 || i>=ROZM)
    {
        cerr<<"Blad-jestes poza tablica!";
        exit(1);
    }
    return tabW[i];
}

template <class TYP, int ROZM>
void Wektor<TYP, ROZM>::wpisz()
{
    for (int i=0; i<ROZM; i++)
    {
        cout<<"Wpisz wartosc:";
        cin>>tabW[i];
    }
}

template <class TYP, int ROZM>
void Wektor<TYP, ROZM>::wypisz ()
{
    for (int i=0; i<ROZM; i++)
    {
        cout<<i+1<<" wartosc:"<<tabW[i]<<endl;
    }
}

template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZM> &Wek)
{
    for (int i=0; i<ROZM; i++)
    {
        Strm>>Wek[i];
    }
    return Strm;
}

template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZM> &Wek)
{
    cout<<"[";
    for (int i=0; i<ROZM-1; i++)
    {
        Strm<<Wek[i];
        cout<<" ";
    }
    Strm<<Wek[ROZM-1];
    cout<<"]";
    return Strm;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator + (const Wektor<TYP, ROZM> & W2) const
{
    Wektor <TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[i]=tabW[i]+W2[i];   
    }
    return wynik;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator - (const Wektor<TYP, ROZM> & W2) const
{
    Wektor <TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[i]=tabW[i]-W2[i];   
    }
    return wynik;
}

template <class TYP, int ROZM>
const TYP Wektor<TYP, ROZM>::operator * (const Wektor<TYP, ROZM> & W2) const /* Iloczyn skalarny */
{
    TYP wynik, iloczyn;
    for (int i=0; i<ROZM; i++)
    {
        iloczyn=tabW[i]*W2[i];
        wynik= wynik+iloczyn;
    }
    return wynik;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator * (TYP l) const /* Wektor razy liczba */ /*const x2*/
{
    Wektor <TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[0]=tabW[i]*l;
    }
    return wynik;
}

template <class TYP, int ROZM> 
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator / (TYP l) const 
{
    Wektor <TYP,ROZM> wynik;
    if (l==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<ROZM; i++)
    {
        wynik[i]=tabW[i]/l;
    }
    return wynik;
}

template <class TYP, int ROZM> 
const double Wektor<TYP,ROZM>::dlugosc () const
{
    return abs(pow(tabW[0],2)+pow(tabW[1],2)+pow(tabW[1],2));
}

/*
template <> const Wektor<LZespolona,5> Wektor<LZespolona, 5>::operator / (LZespolona l) const 
{
    Wektor <LZespolona,5> wynik;
    if (l.re==0.0 && l.im==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<5; i++)
    {
        wynik[i]=tabW[i]/l;
    }
    return wynik;
}

template <> const Wektor<LZespolona,3> Wektor<LZespolona, 3>::operator / (LZespolona l) const 
{
    Wektor <LZespolona,3> wynik;
    if (l.re==0.0 && l.im==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<3; i++)
    {
        wynik[i]=tabW[i]/l;
    }
    return wynik;
}
*/
template <class TYP, int ROZM>
bool Wektor<TYP, ROZM>::operator == (const Wektor<TYP, ROZM> & W2) const
{
    double epsilon=0.000000000000001; int i;
    for (i=0; i<ROZM; i++)
    {
        if(abs(tabW[i]-W2[i])>epsilon)
        return false;
    }
    return true;
}

template <class TYP, int ROZM>
bool Wektor<TYP, ROZM>::operator != (const Wektor<TYP, ROZM> & W2) const
{      
    return !(*this==W2);
}






