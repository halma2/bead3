#include "spinbox.hpp"
#include "graphics.hpp"
using namespace genv;
#include <string>

spinbox::spinbox(wingui * w, int x, int y, int sx, int sy, int lk, int ln) : Widget(w,x,y,sx,sy), legkisebb(lk), legnagyobb(ln)
{
	number = (0 < legkisebb || 0 > legnagyobb) ? legkisebb : 0;
	tmp = std::to_string(number);
	b1 = new button(w, x+sx - 20, y,20,20, "+");
	b2 = new button(w, x+sx - 20, y+sy-20, 20,20, "-");
}

void spinbox::draw(){
	gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y) << color(0,0,0) << move_to(_x + 2, _y + 2) <<
	box(_size_x-2-2, _size_y-2-2) << move_to(_x+5, _y+_size_y/2+5) << color(255,255,255) << text(tmp);
}

void spinbox::handle(event ev){
	if(megnyomhato){
		if(((b1->is_selected(ev.pos_x, ev.pos_y)&& ev.button == btn_left) || ev.keyname == "Up") && number < legnagyobb)
			novel(1);
		else if(((b2->is_selected(ev.pos_x, ev.pos_y)&& ev.button == btn_left) || ev.keyname == "Down") && number > legkisebb)
			novel(-1);
		else if(ev.keyname == "PageUp" && number+10 <= legnagyobb)
			novel(10);
		else if(ev.keyname == "PageDown" && number-10 >= legkisebb)
			novel(-10);
	}
	if(ev.type == ev_timer)
		megnyomhato = true;
}
