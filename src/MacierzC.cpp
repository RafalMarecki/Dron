#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/src/Macierz.cpp"

template class Macierz <double, 5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 5> &Mac);

template class Macierz <double, 3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 3> &Mac);