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
//Włączenie gnuplota
  shared_ptr<Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,1000)); 

//Deklaracja drona, tafli, dna i przeszkód
  shared_ptr<Dron> Dron1 (new Dron(54,40,30));
  shared_ptr<Dron> Dron2 (new Dron(40,30,20));
  shared_ptr<Dron> Dron0 (new Dron(0,0,0));
  shared_ptr<Dno> Dno1 (new Dno());
  shared_ptr<Tafla> Tafla1 (new Tafla());
  shared_ptr<Przeszkoda_Prostopadloscian> Przeszkoda1 (new Przeszkoda_Prostopadloscian (20,10,40));

//Dodawanie do kolekcji
  vector<shared_ptr<Przeszkoda>> kolekcja_przeszkod;
  vector<shared_ptr<Interfejs>> kolekcja_dronow;
  kolekcja_dronow.push_back(Dron1);
  kolekcja_dronow.push_back(Dron2);
  kolekcja_przeszkod.push_back(Dno1);
  kolekcja_przeszkod.push_back(Tafla1);
  kolekcja_przeszkod.push_back(Przeszkoda1);

//Dodawanie do kolekcji w klasie
  Dron1->set_kolekcja_przeszkod(kolekcja_przeszkod);
  Dron2->set_kolekcja_przeszkod(kolekcja_przeszkod);
  Dron1->set_kolekcja_dronow(kolekcja_dronow);
  Dron2->set_kolekcja_dronow(kolekcja_dronow);

//Deklaracja wektorow przesuniecia Przeszkód na planszy
  Wektor3D Przes_Dron2 (40,40,40);
  Wektor3D Przes_Przeszkoda1 (20,0,-60);

//Ustawianie Drona2 i Przeszkód na planszy
  Dron2->ustaw_pozycja1 (Przes_Dron2);
  Przeszkoda1->ustaw_pozycja (Przes_Przeszkoda1);

//Rysowanie drona, tafli, dna i przeszkód
  api->change_ref_time_ms(0); 
  Tafla1->rysuj(api);
  Dno1->rysuj(api);
  Dron1->plyn(api,0,0);
  Dron2->plyn(api,0,0);
  Przeszkoda1-> rysuj(api);

//Dane do sterowania
  Dron0 = Dron1;
  int nr = 1;
  char s;
  double Odleglosc=0;
  double Kat=0;

//MEU UZYTKOWNIKA
  cout<<endl<<"DRON PODWODNY 2020"<<endl<<endl;
  cout<<"Menu uzytkownika:"<<endl;
  cout<<"p - Plyn do przodu"<<endl;
  cout<<"o - Obroc drona"<<endl;
  cout<<"d - Zmien drona"<<endl;
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
        Dron0->plyn(api,Odleglosc,Kat);
      }break;

      case 'o':
      {
        cout << "Wybierz kat o jaki chcesz obrocic drona"<<endl;
        cout << "Kat: ";
        cin >> Kat;
        Dron0->Obrot_AnimZ(api,Kat);
      }break;

      case 'd':
      {
        cout << "Wybierz nr drona (1 lub 2):";
        cin >> nr;

        if (nr!=1 && nr!=2)
          cout<< "Wybrales zly nr drona!" <<endl;

        if(nr==2)
          Dron0=Dron2;
    
        if(nr==1)
          Dron0=Dron1;
      }break;

      default:
      {
        cout<<"Wybrales zla opcje!"<<endl;
      }break;
    }
    cout<<endl;
  }
}
  
/*
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
*/
