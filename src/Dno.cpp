#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dno.hh"
using namespace std;

int Dno::rysuj(std::shared_ptr<Draw3DAPI> api) 
{
    int x;	
    x=api->draw_surface(vector<vector<Point3D> > {{
	    Point3D(-100,-100,-100), Point3D(100,-100,-100), Point3D(100,100,-100)
	    },{
	    Point3D(-100,-100,-100), Point3D(-100,100,-100), Point3D(100,100,-100)       
	    }	      
	    },"yellow");
	return x;
}