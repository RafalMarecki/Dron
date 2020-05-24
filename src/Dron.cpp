#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dron.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wirnik.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"

#define PI 3.14

Dron::Dron (double bokA, double bokB, double bokC)
{
    if (bokA<0.0  || bokB<0.0 || bokC<0.0)
    {
        cerr<<"Wpisano ujemne wartosci bokow!"<<endl;
        exit(1);
    }
    A=bokA; B=bokB; C=bokC; /* Rozmiary i pozycja DRONA */
    Wektor3D tmp (A/2, B/2, C/2);
    PozycjaSrodka = tmp; 

    Wirnik Lewy (A/4, C/4); /* Rozmiary, pozycja i orientacja WIRNIKOW */
    Wirnik Prawy (A/4, C/4);
    L = Lewy; P = Prawy;
    Wektor3D SrodekL (0 , -A/4, 0);
    Wektor3D SrodekP (0, A/4, 0);
    L.ustaw_orientacja ((*this).Orientacja);
    P.ustaw_orientacja ((*this).Orientacja);
    L.ustaw_pozycja (SrodekL);
    P.ustaw_pozycja (SrodekP);
}

void Dron::ObrotX (double kat)
{
    MacierzObr tmp (kat, 'x');
    Orientacja = tmp * Orientacja;
}

void Dron::ObrotY (double kat)
{
    MacierzObr tmp (kat, 'y');
    Orientacja = tmp * Orientacja;
}

void Dron::ObrotZ (double kat)
{
    MacierzObr tmp (kat, 'z');
    Orientacja = tmp * Orientacja;
}
/*
void Dron::przesun_o_wektor (Wektor3D & W)
{
    PozycjaSrodka = PozycjaSrodka + W;
}
*/
void Dron::Przesun(double dlugosc,double kat)
{
    Wektor3D ruch (cos(kat)*dlugosc, cos(kat)*dlugosc , sin(kat)*dlugosc);
    Odniesienie = Odniesienie + ruch; //PozycjaSrodka
}

void Dron::Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc, double kat)
{
    for (int j=0; j<odleglosc; j++)
    {   
        (*this).Przesun (1,kat); 
        int dron2 = (*this).rysuj(api); 
        if (odleglosc - j > 1)
        api-> erase_shape(dron2); 
    } 
}
/*
void Dron::Obrot_AnimX (shared_ptr<Draw3DAPI> api, double kat)
{
    for(int i=0; i<kat; i++)
    {    
        double a = kat * PI/180;
        int dron = (*this).rysuj(api);
        (*this).ObrotX(a);
        if (kat - i > 1)
        api-> erase_shape(dron);   
    }
}

void Dron::Obrot_AnimY (shared_ptr<Draw3DAPI> api, double kat)
{
    for(int i=0; i<kat; i++)
    {    
        double a = kat * PI/180;
        int dron = (*this).rysuj(api);
        (*this).ObrotY(a);
        if (kat - i > 1)
        api-> erase_shape(dron);     
    }
}
*/
void Dron::Obrot_AnimZ (shared_ptr<Draw3DAPI> api, double kat)
{
    for(int i=0; i<kat; i++)
    {    
        int dron = (*this).rysuj(api);
        (*this).ObrotZ(1);
        //if (kat - i > 1)
        api-> erase_shape(dron); 
    }
}

void Dron::plyn (shared_ptr<Draw3DAPI> api, double odleglosc, double kat)
{
    /*
    kat = kat * PI / 180;
    
    for (int i=0; i<kat; i++)
    {   
        int dron = (*this).rysuj(api); 
        api->erase_shape(dron);
        (*this).ObrotY(1);
    }*/
    (*this).Przesun_Anim (api, odleglosc, kat);
    //(*this).Obrot_AnimX (api, 180-kat);
    /*
    Wektor3D przesuniecie (sin(kat), 0, cos(kat));
    for (int j=0; j<odleglosc; j++)
    { 
        (*this).przesun_o_wektor(przesuniecie);
        int dron2 = (*this).rysuj(api);
        if (odleglosc - j > 1)
        api-> erase_shape(dron2);     
    } */
}

void Dron::narysuj (shared_ptr<Draw3DAPI> api)
{
    rysuj(api);
    L.rysuj(api);
    P.rysuj(api);
}



