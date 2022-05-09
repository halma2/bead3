#include "lista.hpp"
#include "graphics.hpp"
using namespace genv;

lista::lista(wingui * w, int x, int y, int sx, int sy, int es, std::vector<std::string> * sv) :
	Widget(w,x,y,sx,sy), elemnt_size(es), _tomb(sv) {
	_index = 0;
}

std::string lista::cut(){
	std::string tmp = getValue();
	for (int i = 0; i < _tomb->size(); i++){
		if (_tomb->at(i) == tmp){
			_tomb->erase(_tomb->begin()+i);
			if (_index == i)
				_index = 0;
			break;
		}
	}
	return tmp;
}

void lista::draw(){
	gout << move_to(_x,_y) << color(255,255,255) << box(_size_x, _size_y) << move_to(_x+2, _y+2);

	for (int i = 0; i < _tomb->size(); i++){
        gout << move_to(_x+2, _y+2 + i*elemnt_size) << color(0,0,0);
        if (i == _hovered) gout << color(0,0,255);
        if (i == _index) gout << color(0,155,0);
        gout << box(_size_x-2-2, elemnt_size-2-2) << color(255,255,255) << move_to(_x+5, _y+elemnt_size*i + elemnt_size/2 + 5) << text(_tomb->at(i));
	}
}

void lista::handle(event ev){

    for(size_t i = 0; i <= _tomb->size(); i++){
        if(is_hovered(ev, i)){
            _hovered = i;
            break;
        }
    }

	if(ev.button == btn_left){
        for(int i = 0; i <= _tomb->size(); i++){
            if(is_hovered(ev, i)){
                _index = i;
                break;
            }
        }
    }
}

bool lista::is_hovered(event ev, const int& ix){
	return _y + 2 + ix*elemnt_size < ev.pos_y && ev.pos_y < _y  + (ix+1)*elemnt_size && _x < ev.pos_x && ev.pos_x < _x+_size_x-20;
}
