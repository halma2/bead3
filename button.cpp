#include "button.hpp"
#include "graphics.hpp"
using namespace genv;
#include "wingui.hpp"

#include <iostream>

button::button(wingui * w, int x, int y, int sx, int sy, std::string text) : Widget(w, x,y,sx,sy), _text(text) {
	enabled = true;
	pressed = false;
}

void button::draw(){
	gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y) <<
		move_to(_x+2, _y+2) << color(100,100,100);
	if (pressed){
		gout << color(50,50,50);
	}
	gout << box(_size_x-4, _size_y-4) << move_to(_x + 5, _y + _size_y/2 + 5) << color(255,255,255) << text(_text);
}

void button::handle(event ev){
    if (abs(ev.button) == btn_left && enabled){
        if (ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y))
            pressed = true;
        else {
            pressed = false;
            if(is_selected(ev.pos_x, ev.pos_y)){
                action();
            }
        }
    }
}
