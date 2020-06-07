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

bool Przeszkoda_Prostopadloscian::czy_kolizja (shared_ptr<Interfejs> X)
{
    double R = X->wez_promien();

    Wektor3D Odn = X->zwroc_odniesienie();
    if (Odn[0] >  Odniesienie[0] - A/2 - R && Odn[1] >  Odniesienie[1] - B/2 - R && Odn[2] >  Odniesienie[2] - C/2 - R)
    return true;
    
    return false;
}