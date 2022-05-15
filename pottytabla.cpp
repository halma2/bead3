#include "pottytabla.hpp"
#include "graphics.hpp"
using namespace genv;

pottytabla::pottytabla(wingui * w, int x, int y, int sx, int sy, int** t) : Widget(w,x,y,sx,sy), tablahiv(t) {}


void pottytabla::draw(){
	gout << color(50,50,240) << move_to(_x,_y) << box(_size_x,_size_y);
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 6; j++){
			if(tablahiv[i][j] == 1)
				gout << color(255,50,50);
			else if (tablahiv[i][j] == 2)
				gout << color(50,255,50);
			else
				gout << color(255,255,255);
			kor_rajz(_x+25+10+80*i, _y+50+60*j,200);
		}
	}
}


void pottytabla::kor_rajz(const float& x, const float& y, const int& r){
	gout << move_to(x, y);
	for (int i = -r; i < r; i++){
		for (int j = -r; j < r; j++){
			if (i*i + j*j <= r + 1){
				gout << move_to(x + i, y + j) << dot;
			}
		}
	}
}
