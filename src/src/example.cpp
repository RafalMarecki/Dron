#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dr3D_gnuplot_api.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/MacierzObr.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Prostopadloscian.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dron.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Plaszczyzna.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dno.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Tafla_wody.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Graniastoslup.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wirnik.hh"

using drawNS::Draw3DAPI;
using std::shared_ptr;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

using namespace std;

void wait4key() {
  do {
    cout << "\n Press a key to continue..." << endl;
  } while(cin.get() != '\n');
}

int main() {
  shared_ptr<Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,1000)); 
  //Dron droniarz (27,20,15);
  Dron droniarz (54,40,30);
  Dno dno;
  Tafla tafla;
  char s;
  double Odleglosc=0;
  double Kat=0;

  api->change_ref_time_ms(0); //odświeżanie z ze zniknieciem i pojawieniem
  tafla.rysuj(api);
  dno.rysuj(api);
  droniarz.plyn(api,0,0);

//MEU UZYTKOWNIKA
  cout<<endl<<"DRON PODWODNY 2020"<<endl<<endl;
  cout<<"Menu uzytkownika:"<<endl;
  cout<<"p - Plyn do przodu"<<endl;
  cout<<"o - Obroc drona"<<endl;
  cout<<"q - Zakoncz dzialanie"<<endl;

  while (s!='q')
  {
    cout << "Wybierz opcje: "; cin >> s;
    switch (s)
    {
      case 'q':
        break;
    
      case 'p':
      {
        cout << "Wybierz odleglosc na jaka ma plynac i kat"<<endl;
        cout << "Odleglosc: ";
        cin >> Odleglosc;
        cout << "Kat: ";
        cin >> Kat;
        droniarz.plyn(api,Odleglosc,Kat);
      }break;

      case 'o':
      {
        cout << "Wybierz kat o jaki chcesz obrocic drona"<<endl;
        cout << "Kat: ";
        cin >> Kat;
        droniarz.Obrot_AnimZ(api,Kat);
      }break;

      default:
      {
        cout<<"Wybrales zla opcje!"<<endl;
      }break;
    }
    cout<<endl;
  }
  
/*
  droniarz.plyn(api,45,45);
  wait4key();
  droniarz.plyn(api,45,-45);
  wait4key();
  droniarz.plyn(api,45,120);
  wait4key();
  */
  /*
  droniarz.plyn(api,45,60);
  wait4key();
  droniarz.plyn(api,45,90);
  wait4key();
  */







  
  /*
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  */
  
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}

