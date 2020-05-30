#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wektor.hh"
#include <iostream>
#include <cmath>
using namespace std;

template <class TYP, int ROZM>
Macierz<TYP,ROZM>::Macierz()
{
    Wektor<TYP,ROZM> X;
    for(int i; i<ROZM; i++)
    {
        tabM[i]=X;
    }
}

template <class TYP, int ROZM>
Macierz<TYP,ROZM>::Macierz(Wektor<TYP,ROZM> A, Wektor<TYP,ROZM> B, Wektor<TYP,ROZM> C)
{    
    tabM[0]=A;
    tabM[1]=B;
    tabM[2]=C;
}

template <class TYP, int ROZM>
Wektor<TYP,ROZM> & Macierz<TYP,ROZM>::operator [] (int i)
{
    if (i<0 || i>=ROZM)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }
    return tabM[i];
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> & Macierz<TYP,ROZM>::operator [] (int i) const
{
    if (i<0 || i>=ROZM)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }
    return tabM[i];
}

template <class TYP, int ROZM>
const Macierz<TYP,ROZM> Macierz<TYP,ROZM>::transpozycja () const
{
    Macierz<TYP,ROZM> A;
    for (int i=0; i<ROZM; i++)
    {
        for (int j=0; j<ROZM; j++)
        {
            A[i][j]=tabM[j][i];
        }
    }
    return A;
}

template <class TYP, int ROZM>
std::istream & operator >> (std::istream &Strm, Macierz<TYP,ROZM> &Mac)
{   
    for (int i=0; i<ROZM; i++)
    {
        Strm>>Mac[i];
    }
    return Strm;
}

template <class TYP, int ROZM>
std::ostream & operator << (std::ostream &Strm, const Macierz<TYP,ROZM> &Mac)
{
    for (int i=0; i<ROZM; i++)
    {
        Strm<<Mac[i]<<endl;
    }
    return Strm;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Macierz<TYP,ROZM>::operator* (const Wektor<TYP,ROZM> & W2) const /* Macierz*Wektor */ 
{
    Wektor<TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[i]=tabM[i]*W2;
    }
    return wynik;
}

template <class TYP, int ROZM>
Macierz<TYP,ROZM> Macierz<TYP,ROZM>::operator* (Macierz<TYP,ROZM> A) const /* Macierz*Macierz */
{
    Macierz<TYP,ROZM> B, wynik; 
    int i;
    A=A.transpozycja();                
    for (i=0; i<ROZM; i++) 
    {
        B[i]=tabM[i];
    }        
    for (i=0; i<ROZM; i++)
    {
        wynik[i]=B*A[i];
    }           
    return wynik.transpozycja();
}
/* Jesli bede mial problem i bede musiał napisac */
/* w nawiasie const Macierz & A, to po prostu podmienie */
/* i stworze sobie nowa zmienna typu Macierz zamiast */
/* pod A podpisywac A=A.transpozycja();. */
/* Nie robie tego, bo nie chce aby ta funkcja zmieniala wartosc A */

template <class TYP, int ROZM>
const Macierz<TYP,ROZM> Macierz<TYP,ROZM>::operator * (TYP l) const
{
    Macierz<TYP,ROZM> Wynik;
    for (int i=0; i<ROZM; i++) 
    {
        Wynik[i]=tabM[i]*l;
    }
    return Wynik;
}


template <class TYP, int ROZM>
const Macierz<TYP,ROZM> Macierz<TYP,ROZM>::operator / (TYP l) const
{
    Macierz<TYP,ROZM> Wynik;
    if (l==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<ROZM; i++) 
    {
        Wynik[i]=tabM[i]/l;
    }
    return Wynik;
}
/*
template <> const Macierz<LZespolona, 5> Macierz<LZespolona, 5>::operator / (LZespolona l) const
{
    Macierz<LZespolona, 5> Wynik; 
    if (l.re==0.0 && l.im==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<5; i++) 
    {
        Wynik[i]=tabM[i]/l;
    }
    return Wynik;
}

template <> const Macierz<LZespolona, 3> Macierz<LZespolona, 3>::operator / (LZespolona l) const
{
    Macierz<LZespolona, 3> Wynik; 
    if (l.re==0.0 && l.im==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<3; i++) 
    {
        Wynik[i]=tabM[i]/l;
    }
    return Wynik;
}
*/
template <class TYP, int ROZM>
const Macierz<TYP,ROZM> Macierz<TYP,ROZM>::operator + (const Macierz<TYP,ROZM> & A) const
{
    Macierz<TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++) 
    {
        wynik[i]=tabM[i]+A[i];
    }
    return wynik;
}

template <class TYP, int ROZM>
const Macierz<TYP,ROZM> Macierz<TYP,ROZM>::operator - (const Macierz<TYP,ROZM> & A) const
{
    Macierz<TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++) 
    {
        wynik[i]=tabM[i]-A[i];
    }
    return wynik;
}

template <class TYP, int ROZM>
bool Macierz<TYP,ROZM>::operator == (const Macierz<TYP,ROZM> & A) const
{
    for (int i=0; i<ROZM; i++)
    {
        if (tabM[i]!=A[i])
        return false;
    }
    return true;
}

template <class TYP, int ROZM>
bool Macierz<TYP,ROZM>::operator != (const Macierz<TYP,ROZM> & A) const
{
    return !(*this==A);
}

template<typename TYP, int ROZM>
const TYP Macierz<TYP,ROZM>::wyznacznik_gauss() const
{
    TYP a, wynik;
    a=0; 
    wynik=1;
    Macierz <TYP, ROZM> M = (*this); 
    for (int i=0; i<ROZM; i++)
    {
        for (int j= i+1; j<ROZM; j++)
        {
            a = M[j][i] / M[i][i];
            for (int k=i; k<ROZM; k++)
                M[j][k] = M[j][k] - a*M[i][k];     
        }
    }
    for (int l=0; l<ROZM; l++)
        wynik = wynik*M[l][l];
    return wynik;   
}

template <class TYP, int ROZM>
const TYP Macierz<TYP,ROZM>::wyznacznik () const
{
    TYP wynik=tabM[0][0]*tabM[1][1]*tabM[2][2]  +  tabM[0][1]*tabM[1][2]*tabM[2][0]  +  tabM[0][2]*tabM[1][0]*tabM[2][1]  -  tabM[2][0]*tabM[1][1]*tabM[0][2]  -  tabM[2][1]*tabM[1][2]*tabM[0][0]  -  tabM[2][2]*tabM[1][0]*tabM[0][1];
    return wynik;
}

template <class TYP, int ROZM>
void Macierz<TYP,ROZM>::jednostkowa ()
{
    for (int i=0; i<ROZM; i++)
    {
        for (int j=0; j<ROZM; j++)
        {
            if (i==j)
            tabM[i][j]=1;
            else
            tabM[i][j]=0;
        }      
    }
}


