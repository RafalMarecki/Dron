#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/rozmiar.h"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wektor.hh"
#include <iostream>


template <class TYP, int ROZM>
class Macierz {
  protected:
  Wektor<TYP, ROZM> tabM[ROZM];

  public:
  Macierz();
  Macierz(Wektor<TYP,ROZM> A, Wektor<TYP,ROZM> B, Wektor<TYP,ROZM> C); /*konstruktor macierzy*/
  Wektor<TYP, ROZM> & operator [] (int i);
  const Wektor<TYP,ROZM> & operator [] (int i) const;
  const Macierz<TYP,ROZM> transpozycja () const ;
  const Wektor<TYP,ROZM> operator * (const Wektor<TYP,ROZM> & W2) const; /* Macierz*Wektor */
  Macierz<TYP,ROZM> operator * (Macierz<TYP,ROZM> A) const; /* Macierz*Macierz */
  const Macierz<TYP,ROZM> operator * (TYP l) const; /****************/
  const Macierz<TYP,ROZM> operator / (TYP l) const; /****************/
  const Macierz<TYP,ROZM> operator + (const Macierz<TYP,ROZM> & A) const;
  const Macierz<TYP,ROZM> operator - (const Macierz<TYP,ROZM> & A) const;
  bool operator == (const Macierz<TYP,ROZM> & A) const;
  bool operator != (const Macierz<TYP,ROZM> & A) const;
  Macierz<TYP,ROZM> schodkowa () const;
  const TYP wyznacznik_gauss() const;
  const TYP wyznacznik() const;
  void jednostkowa ();
  /*const Macierz wstaw_kolumne (int, Macierz, Wektor) const;*/
};
template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZM> &Mac);
template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZM> &Mac);



//typedef Macierz <double, 3> Macierz3D;
//typedef Macierz <double, 3> MacierzObr;


#endif
