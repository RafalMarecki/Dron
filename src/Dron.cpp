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

void Dron::Obroc_L_Wirnik ()
{
    L.ustaw_pozycja (Odniesienie - Orientacja * (Odniesienie - Odsuniecie_L)   /*- XD  * Odsuniecie_L + Odsuniecie_L*/);
    L.ustaw_orientacja (Orientacja);
}

void Dron::Obroc_P_Wirnik ()
{
    P.ustaw_pozycja (Odniesienie - Orientacja * (Odniesienie - Odsuniecie_P) /*- XD * Odsuniecie_P + Odsuniecie_P*/);
    P.ustaw_orientacja (Orientacja);  
}
/*
void Dron::ObrotX (double kat)
{
    MacierzObr XD (-kat, 'x');
    ustaw_orientacja_razy(XD);
    L.ustaw_orientacja_razy(XD);
    P.ustaw_orientacja_razy(XD);
}
*/
void Dron::ObrotY (double kat)
{
    MacierzObr XD (-kat, 'y');
    ustaw_orientacja_razy(XD);
    //Obroc_L_Wirnik();
    //Obroc_P_Wirnik();
    L.ustaw_orientacja_razy(XD);
    P.ustaw_orientacja_razy(XD);
    L.Krec_Wirnik (5);
    P.Krec_Wirnik (-5);
}

void Dron::ObrotZ (double kat)
{
    MacierzObr XD (-kat, 'z');
    ustaw_orientacja_razy(XD);
    Obroc_L_Wirnik();
    Obroc_P_Wirnik();
    L.ustaw_orientacja_razy(XD);
    P.ustaw_orientacja_razy(XD);
    if (kat>=0)
    {
        L.Krec_Wirnik (-5);
        P.Krec_Wirnik (-5);
    }
    else
    {
        L.Krec_Wirnik (5);
        P.Krec_Wirnik (5);
    }
}

void Dron::Przesun(double dlugosc)
{
    Wektor3D ruch (dlugosc, 0, 0);
    ruch = Orientacja * ruch;
    //Odniesienie = Odniesienie + ruch; //////////
    ustaw_pozycja (Odniesienie + ruch); /* TO TAK JAKBY NIWELUJE PROBLEM COFANIA SIE WIRNIKOW, ALE DRON SIE NIE RUSZA*/
    P.Przesun(dlugosc);
    L.Przesun(dlugosc);
    L.Krec_Wirnik(5);
    P.Krec_Wirnik(-5);
}

void Dron::Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc)
{
    bool kolizja = false;
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
            /*
            for (auto elem : kolekcja_przeszkod)
            {
                if (elem->czy_kolizja(shared_ptr<>))
            }
            */
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
            api-> erase_shape((*this).id); 
        }
    }
    else
    {
        for(int i=kat; i<0; i++)
        {    
            (*this).narysuj(api);
            (*this).ObrotY(-1);
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
    (*this).Przesun_Anim (api,odleglosc);
    (*this).Obrot_AnimY(api,-kat);
    (*this).narysuj(api);
}

void Dron::narysuj (shared_ptr<Draw3DAPI> api)
{
    (*this).rysuj(api);
    L.rysuj(api);
    P.rysuj(api);
}

bool Dron::czy_kolizja (shared_ptr<Interfejs> X)
{
    return 1;
}

double Dron::wez_promien ()
{
    return A/2;
}

void Dron::ustaw_pozycja1 (const Wektor3D & srodek)
{
    ustaw_pozycja(srodek);
    L.ustaw_pozycja(Odsuniecie_L+srodek);
    P.ustaw_pozycja(Odsuniecie_P+srodek);
}
















/*
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
*/


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