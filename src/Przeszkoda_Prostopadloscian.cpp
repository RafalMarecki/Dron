#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda_Prostopadloscian.hh"

Przeszkoda_Prostopadloscian::Przeszkoda_Prostopadloscian (double bokA, double bokB, double bokC) 
{
    if (bokA<0.0  || bokB<0.0 || bokC<0.0)
    {
        cerr<<"Wpisano ujemne wartosci bokow przeszkody!"<<endl;
        exit(1);
    }
    A=bokA; B=bokB; C=bokC;
}