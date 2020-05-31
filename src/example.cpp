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
//#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Interfejs.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda_Prostopadloscian.hh"

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

//Deklaracja drona, tafli i dna
  Dron droniarz (54,40,30);
  Dno dno;
  Tafla tafla;

//Kolekcja przeszkód
  Przeszkoda_Prostopadloscian P1 (10,10,10);

//Dane do sterowania
  char s;
  double Odleglosc=0;
  double Kat=0;

//Rysowanie drona, tafli, dna i przeszkód
  api->change_ref_time_ms(0); 
  tafla.rysuj(api);
  dno.rysuj(api);
  droniarz.plyn(api,0,0);
  P1.rysuj(api);
  
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
}

