#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/rozmiar.h"
#include <iostream>

template <class TYP, int ROZM>
class Wektor {
  protected:
  TYP tabW[ROZM];

  public:
  TYP & operator [] (int i); 
  const TYP & operator[](int i) const;
  Wektor ();
  Wektor (TYP ,TYP ,TYP);
  void wpisz();
  void wypisz();
  const Wektor <TYP,ROZM> operator + (const Wektor <TYP, ROZM> & W2) const;
  const Wektor <TYP,ROZM> operator - (const Wektor <TYP, ROZM> & W2) const;
  const TYP operator * (const Wektor <TYP, ROZM> & W2) const; /* Iloczyn skalarny */
  const Wektor <TYP,ROZM> operator * (TYP l) const; /* Wektor * liczba */ /*const x2*/
  const Wektor <TYP,ROZM> operator / (TYP l) const; /* Wektor / liczba */ /*const x2*/
  bool operator == (const Wektor <TYP, ROZM> & W2) const;
  bool operator != (const Wektor <TYP, ROZM> & W2) const;
  const double dlugosc () const;
};
template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, Wektor <TYP, ROZM> &Wek);
template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const Wektor <TYP, ROZM> &Wek);

typedef Wektor <double,3> Wektor3D;
#endif
