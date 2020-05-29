#include <iostream>
#include <unistd.h>
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

 /* Rozmiary, pozycja i orientacja WIRNIKOW */
    L.Set_Wymiary(C/3, A/5); 
    P.Set_Wymiary(C/3, A/5); 

    Wektor3D Lewy((-A/3), (-B/4),0.0);
    Odsuniecie_L = Lewy;
    L.ustaw_pozycja(Lewy);

    Wektor3D Prawy((-A/3), (B/4),0.0);
    Odsuniecie_P = Prawy;
    P.ustaw_pozycja(Prawy);
}

void Dron::ObrotX (double kat)
{
    MacierzObr XD (-kat, 'x');
    ustaw_orientacja_razy(XD);
    L.ustaw_orientacja_razy(XD);
    P.ustaw_orientacja_razy(XD);
    //L.Obrot_Wirnik (Odsuniecie_L, Orientacja, XD);
    //P.Obrot_Wirnik (Odsuniecie_L, Orientacja, XD);
}

void Dron::ObrotY (double kat)
{
    MacierzObr XD (-kat, 'y');
    ustaw_orientacja_razy(XD);
    L.ustaw_orientacja_razy(XD);
    P.ustaw_orientacja_razy(XD);
}

void Dron::ObrotZ (double kat)
{
    MacierzObr XD (-kat, 'z');
    ustaw_orientacja_razy(XD);
    L.ustaw_orientacja_razy(XD);
    P.ustaw_orientacja_razy(XD);
    //L.Obrot_Wirnik (Odsuniecie_L, Orientacja, XD);
    //P.Obrot_Wirnik (Odsuniecie_P, Orientacja, XD);
}

void Dron::Przesun(double dlugosc)
{
    Wektor3D ruch (dlugosc, 0, 0);
    ruch = Orientacja * ruch;
    Odniesienie = Odniesienie + ruch; //PozycjaSrodka
    P.Przesun(dlugosc);
    L.Przesun(dlugosc);
}

void Dron::Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc)
{
    if (odleglosc >= 0)
    {
        for (int j=0; j<odleglosc; j++)
        {   
            (*this).Przesun(1); 
            (*this).narysuj(api); 
            if (odleglosc - j > 1)
            api-> erase_shape((*this).id); 
        } 
    }
    else
    {
        for (int j=odleglosc; j<0; j++)
        {   
            (*this).Przesun(-1); 
            (*this).narysuj(api); 
            if (j < -1)
            api-> erase_shape((*this).id); 
        } 
    }
}

void Dron::Obrot_AnimY (shared_ptr<Draw3DAPI> api, double kat)
{
    if (kat >= 0)
    {
        for(int i=0; i<kat; i++)
        {    
            (*this).narysuj(api);
            (*this).ObrotY(1);
            //if (kat - i > 1)
            api-> erase_shape((*this).id); 
        }
    }
    else
    {
        for(int i=kat; i<0; i++)
        {    
            (*this).narysuj(api);
            (*this).ObrotY(-1);
            //if (kat - i > 1)
            api-> erase_shape((*this).id); 
        }
    }
}

void Dron::Obrot_AnimZ (shared_ptr<Draw3DAPI> api, double kat)
{
    if (kat >= 0)
    {
        for(int i=0; i<kat; i++)
        {    
            (*this).narysuj(api);
            (*this).ObrotZ(1);
            if (kat - i > 1)
            api-> erase_shape((*this).id); 
        }
    }
    else
    {
        for(int i=kat; i<0; i++)
        {    
            (*this).narysuj(api);
            (*this).ObrotZ(-1);
            if (kat - i > 1)
            api-> erase_shape((*this).id); 
        }
    }
}

void Dron::plyn (shared_ptr<Draw3DAPI> api, double odleglosc, double kat)
{
    (*this).Obrot_AnimY(api,kat);
    (*this).Przesun_Anim (api, odleglosc);
    (*this).Obrot_AnimY(api,-kat);
    (*this).narysuj(api);
}

void Dron::narysuj (shared_ptr<Draw3DAPI> api)
{
    (*this).rysuj(api);
    L.rysuj(api);
    P.rysuj(api);
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

/*
void Dron::przesun_o_wektor (Wektor3D & W)
{
    PozycjaSrodka = PozycjaSrodka + W;
}
*/
/*
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
    Orientacja =  tmp * Orientacja;
}

void Dron::Przesun(double dlugosc,double kat)
{
    Wektor3D ruch (cos(kat)*dlugosc, cos(kat)*dlugosc , sin(kat)*dlugosc);
    Odniesienie = Odniesienie + ruch; //PozycjaSrodka
}

void Dron::Przesun(double dlugosc)
{
    Wektor3D ruch (dlugosc, 0, 0);
    ruch = Orientacja * ruch;
    Odniesienie = Odniesienie + ruch; //PozycjaSrodka
    P.Przesun(dlugosc);
    L.Przesun(dlugosc);
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
*/
/*
void Dron::Przesun(double dlugosc,double kat)
{
    Wektor3D ruch (cos(kat)*dlugosc, cos(kat)*dlugosc , sin(kat)*dlugosc);
    Odniesienie = Odniesienie + ruch; //PozycjaSrodka
}
*/