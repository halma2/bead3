#include "inputText.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
using namespace genv;

inputText::inputText(wingui * w,int x, int y, int sx, int sy) : Widget(w,x,y,sx,sy)
{

}

void inputText::draw(){
    gout << color(100,100,100) << move_to(_x,_y) << box(_size_x, _size_y) << genv::move(-keret, -keret) <<
    color(255,255,255) << box_to(_x+keret, _y+keret);
    gout << color(0,0,0) << move_to(_x + 5, _y + keret + _size_y/2) << text(_text);
}

void inputText::handle(event ev){

}
