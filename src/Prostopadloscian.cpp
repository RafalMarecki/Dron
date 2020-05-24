#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Prostopadloscian.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"

using namespace std;

Prostopadloscian::Prostopadloscian (double bokA, double bokB, double bokC)
{
    if (bokA<0.0  || bokB<0.0 || bokC<0.0)
    {
        cerr<<"Wpisano ujemne wartosci bokow!"<<endl;
        exit(1);
    }
    A=bokA; B=bokB; C=bokC;
    Wektor3D tmp (A/2,B/2,C/2);
    PozycjaSrodka = tmp; //PozycjaSrodka
}

void Prostopadloscian::ustaw_pozycja (const Wektor3D & W)
{
    Odniesienie = W; //PozycjaSrodka
}

void Prostopadloscian::ustaw_orientacja (const MacierzObr & MacObrot)
{
    Orientacja = MacObrot;
}

void Prostopadloscian::get_global_wspolrzedne (Wektor3D wspolrzedne[])
{
    Wektor3D tmp = Orientacja * PozycjaSrodka; 
    Wektor3D X (A,0,0);
    Wektor3D Y (0,B,0);
    Wektor3D Z (0,0,C);
    wspolrzedne[0] = Odniesienie + tmp; 
    wspolrzedne[1] = Odniesienie + tmp - Orientacja * X;
    wspolrzedne[2] = Odniesienie + tmp - Orientacja * (X + Y);
    wspolrzedne[3] = Odniesienie + tmp - Orientacja * Y;
    wspolrzedne[4] = Odniesienie + tmp - Orientacja * Z;
    wspolrzedne[5] = Odniesienie + tmp - Orientacja * (X + Z);
    wspolrzedne[6] = Odniesienie + tmp - Orientacja * (X + Y + Z);
    wspolrzedne[7] = Odniesienie + tmp - Orientacja * (Y + Z);
}

int Prostopadloscian::rysuj (std::shared_ptr<drawNS::Draw3DAPI> api) {
  Wektor3D tab[8];
  (*this).get_global_wspolrzedne(tab);

  if (id != 0)
    api -> erase_shape(id);
    
  id = api->draw_polyhedron(vector<vector<Point3D> > {{
        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
      },{
        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
	  }},"black");
 
  return id;
}

/*
int Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api) {
  Wektor3D tab[8];
  (*this).get_global_wspolrzedne(tab);
  unsigned int tmp = api->draw_polyhedron(vector<vector<Point3D> > {{
        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
      },{
        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
	  }},"black");
 
  return tmp;
}
*/
/*
void Prostopadloscian::ruch (const Wektor3D &Przesuniecie)
{
    //id=api->draw_polyhedron
}
*/

/*
void Prostopadloscian::ustaw_orientacja_wektor (Wektor3D & W) const
{
    W = Orientacja * W;
}
*/