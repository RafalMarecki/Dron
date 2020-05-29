#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wirnik.hh"

Wirnik::Wirnik (double bok, double h)
{
    if (bok<0.0  || h<0.0)
    {
        cerr<<"Wpisano ujemne wymiary!"<<endl;
        exit(1);
    }
    Bok = bok;
    H = h;
    Wektor3D srodek (Bok/2, Bok/2, H/2); //to ostatnio bylo zakomentowane
    PozycjaSrodka = srodek;
}

void Wirnik::Set_Wymiary (double bok, double h) 
{  
    if (bok<0.0  || h<0.0)
    {
        cerr<<"Wpisano ujemne wymiary!"<<endl;
        exit(1);
    }
    Bok = bok;
    H = h;
    Wektor3D srodek (Bok/2, Bok/2, H/2);//to ostatnio bylo zakomentowane
    PozycjaSrodka = srodek;
}

void Wirnik::Przesun (double dlugosc)
{
    Wektor3D ruch (dlugosc,0,0);  
    ruch = Obrot * ruch;  
    ruch = Orientacja * ruch;
    Odniesienie = Odniesienie + ruch;
}

void Wirnik::Obrot_Wirnik (double kat)
{
    MacierzObr XD (-kat, 'y');
    ustaw_orientacja_razy(XD);
}

void Wirnik::Obrot_Wirnik (Wektor3D Odsuniecie, MacierzObr Orientacja_Drona, MacierzObr Orientacja_Wirnik) 
{
    Odniesienie = Odniesienie + (Orientacja_Drona * (Odsuniecie*(-1.0))) + ((Orientacja_Drona * Orientacja_Wirnik) * Odsuniecie);
    ustaw_orientacja_razy(Orientacja_Wirnik);
}

void Wirnik::get_global_wspolrzedne (Wektor3D Wspolrzedne[]) const
{
    Wektor3D dodaj_pozycja (-H/2,-Bok/2,-Bok);
    Wektor3D tmp = Orientacja * (PozycjaSrodka + dodaj_pozycja);
    Wektor3D x (H, 0, 0);
    Wektor3D y (0, Bok, 0);
    Wektor3D y2 (0, Bok/2, 0);
    Wektor3D z (0, 0, Bok * sqrt(3) / 2);

    Wspolrzedne[0] = Odniesienie  + tmp - Orientacja * (x + y);
    Wspolrzedne[1] = Odniesienie  + tmp + Orientacja * (y2 + z - y - x);
    Wspolrzedne[2] = Odniesienie  + tmp + Orientacja * (y2 + z - x);
    Wspolrzedne[3] = Odniesienie  + tmp + Orientacja * (y - x);
    Wspolrzedne[4] = Odniesienie  + tmp + Orientacja * (y2 -z - x);
    Wspolrzedne[5] = Odniesienie  + tmp + Orientacja * (y2 - z - y - x);
    Wspolrzedne[6] = Odniesienie  + tmp - Orientacja * (x + x + y);
    Wspolrzedne[7] = Odniesienie  + tmp + Orientacja * (y2 + z -x - y - x);
    Wspolrzedne[8] = Odniesienie  + tmp + Orientacja * (y2 + z - x - x);
    Wspolrzedne[9] = Odniesienie  + tmp + Orientacja * (y - x - x);
    Wspolrzedne[10] = Odniesienie  + tmp + Orientacja * (y2 - x - z - x);
    Wspolrzedne[11] = Odniesienie  + tmp + Orientacja * (y2 - x - z - y - x);
/*
    Wspolrzedne[0] = Odniesienie  + tmp + Orientacja;
    Wspolrzedne[1] = Odniesienie  + tmp + Orientacja * (y2 +z);
    Wspolrzedne[2] = Odniesienie  + tmp + Orientacja * (y + y2 +z);
    Wspolrzedne[3] = Odniesienie  + tmp + Orientacja * (y + y);
    Wspolrzedne[4] = Odniesienie  + tmp + Orientacja * (y + y2 -z);
    Wspolrzedne[5] = Odniesienie  + tmp + Orientacja * (y2 - z);
    Wspolrzedne[6] = Odniesienie  + tmp - Orientacja * x;
    Wspolrzedne[7] = Odniesienie  + tmp + Orientacja * (y2 + z -x);
    Wspolrzedne[8] = Odniesienie  + tmp + Orientacja * (y + y2 + z - x);
    Wspolrzedne[9] = Odniesienie  + tmp + Orientacja * (y + y - x);
    Wspolrzedne[10] = Odniesienie  + tmp + Orientacja * (y + y2 - x - z);
    Wspolrzedne[11] = Odniesienie  + tmp + Orientacja * (y2 - x -z);*/
}

int Wirnik::rysuj(shared_ptr<Draw3DAPI> api) 
{
    Wektor3D tab[12];
    (*this).get_global_wspolrzedne(tab);
    if (id != 0)
        api->erase_shape(id);
    id = api->draw_polyhedron(vector<vector<Point3D> > {{
    Point3D(tab[0][0],tab[0][1],tab[0][2]), Point3D(tab[1][0],tab[1][1],tab[1][2]), Point3D(tab[2][0],tab[2][1],tab[2][2]),
    Point3D(tab[3][0],tab[3][1],tab[3][2]), Point3D(tab[4][0],tab[4][1],tab[4][2]), Point3D(tab[5][0],tab[5][1],tab[5][2])
        },{
    Point3D(tab[6][0],tab[6][1],tab[6][2]), Point3D(tab[7][0],tab[7][1],tab[7][2]), Point3D(tab[8][0],tab[8][1],tab[8][2]),
    Point3D(tab[9][0],tab[9][1],tab[9][2]), Point3D(tab[10][0],tab[10][1],tab[10][2]), Point3D(tab[11][0],tab[11][1],tab[11][2])
	    }},"blue");
    return id;
}
