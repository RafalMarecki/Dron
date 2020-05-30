#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/src/Wektor.cpp"

template class Wektor <double, 5>;
template std::istream & operator>>(std::istream &strm, Wektor<double,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,5> &W);

template class Wektor <double, 3>;
template std::istream & operator>>(std::istream &strm, Wektor<double,3> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,3> &W);





