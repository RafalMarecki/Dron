CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17 

_start_: Dron
	./Dron

Dron: obj/Dr3D_gnuplot_api.o obj/example.o obj/Wektor.o obj/Macierz.o obj/Prostopadloscian.o obj/MacierzObr.o obj/Dron.o obj/Dno.o obj/Tafla_wody.o obj/Graniastoslup.o obj/Wirnik.o obj/Przeszkoda_Prostopadloscian.o
	g++ -o Dron obj/example.o obj/Dr3D_gnuplot_api.o obj/Wektor.o obj/Macierz.o obj/Prostopadloscian.o obj/MacierzObr.o obj/Dron.o obj/Dno.o obj/Tafla_wody.o obj/Graniastoslup.o obj/Wirnik.o obj/Przeszkoda_Prostopadloscian.o -lpthread

obj/example.o: src/example.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/example.o src/example.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Macierz.o: src/Macierz.cpp src/MacierzC.cpp inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/MacierzC.cpp

obj/MacierzObr.o:inc/Macierz.hh src/MacierzObr.cpp inc/MacierzObr.hh
	g++ ${CPPFLAGS} -o obj/MacierzObr.o src/MacierzObr.cpp

obj/Wektor.o: src/Wektor.cpp src/WektorC.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/WektorC.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

inc/Dron.hh: inc/Interfejs.hh
	touch inc/Dron.hh

inc/Prostopadloscian.hh: inc/Bryla.hh
	touch inc/Prostopadloscian.hh

obj/Przeszkoda_Prostopadloscian.o: src/Przeszkoda_Prostopadloscian.cpp inc/Przeszkoda_Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Przeszkoda_Prostopadloscian.o src/Przeszkoda_Prostopadloscian.cpp

inc/Przeszkoda_Prostopadloscian.hh: inc/Przeszkoda.hh
	touch inc/Przeszkoda_Prostopadloscian.hh

obj/Dno.o: src/Dno.cpp inc/Dno.hh
	g++ ${CPPFLAGS} -o obj/Dno.o src/Dno.cpp

inc/Dno.hh: inc/Plaszczyzna.hh	
	touch inc/Dno.hh

obj/Tafla_wody.o: src/Tafla_wody.cpp inc/Tafla_wody.hh
	g++ ${CPPFLAGS} -o obj/Tafla_wody.o src/Tafla_wody.cpp	

inc/Tafla_wody.hh: inc/Plaszczyzna.hh	
	touch inc/Tafla_wody.hh

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh 
	g++ ${CPPFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

inc/Graniastoslup.hh: inc/Bryla.hh
	touch inc/Graniastoslup.hh

obj/Wirnik.o: src/Wirnik.cpp inc/Wirnik.hh 
	g++ ${CPPFLAGS} -o obj/Wirnik.o src/Wirnik.cpp

inc/Wirnik.hh: inc/Bryla.hh
	touch inc/Wirnik.hh

clear:
	rm -f obj/*.o Dron