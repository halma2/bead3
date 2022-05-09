#include "staticText.hpp"
#include "graphics.hpp"
using namespace genv;

#include <iostream>

staticText::staticText(wingui* w, int x, int y, int sx, int sy, std::string it) : Widget(w,x,y,sx,sy)
{
    _text = it;
}

void staticText::draw(){
    gout << color(100,100,100) << move_to(_x,_y) << box(_size_x, _size_y) << genv::move(-keret, -keret) <<
    color(255,255,255) << box_to(_x+keret, _y+keret);
    gout << color(0,0,0) << move_to(_x + 5, _y + keret + _size_y/2) << text(_text);
}

void staticText::handle(genv::event ev) {
    if (ev.type == ev_key) {
        _text = ev.keycode;
        std::cout << ev.keycode;
    }
}
