#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Tafla_wody.hh"

void Plaszczyzna::ustaw_poziom (double poz)
{}

int Tafla::rysuj(shared_ptr<Draw3DAPI> api)
{	
	if (id != 0)
		api -> erase_shape(id);
    id = api->draw_surface(vector<vector<Point3D> > {{

	Point3D(-100,-100,100), Point3D(100,-100,100), Point3D(100,100,100)
	  },{
	Point3D(-100,-100,100), Point3D(-100,100,100), Point3D(100,100,100)       
	  }	      
	  },"blue");
	return id;
}

bool Tafla::czy_kolizja (shared_ptr<Interfejs> X) 
{
	double wysokosc = 100;
	Wektor3D Odn = X->zwroc_odniesienie();
	if (Odn[2]>wysokosc)
		return true;
	return false;
}
