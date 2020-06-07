#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dno.hh"
using namespace std;

int Dno::rysuj(std::shared_ptr<Draw3DAPI> api) 
{
    if (id != 0)
		api -> erase_shape(id);
    id = api->draw_surface(vector<vector<Point3D> > {{
	    Point3D(-100,-100,-100), Point3D(100,-100,-100), Point3D(100,100,-100)
	    },{
	    Point3D(-100,-100,-100), Point3D(-100,100,-100), Point3D(100,100,-100)       
	    }	      
	    },"yellow");
	return id;
}

bool Dno::czy_kolizja (shared_ptr<Interfejs> X)
{
    double glebokosc = -100;
	Wektor3D Odn = X->zwroc_odniesienie();
	if (Odn[2] < glebokosc)
		return true;
	return false;
}