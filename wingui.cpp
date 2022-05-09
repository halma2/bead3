#include "wingui.hpp"
#include "graphics.hpp"
using namespace genv;

wingui::wingui(const int& xx, const int& yy) : _xx(xx), _yy(yy){
	gout.open(xx, yy);
}

void wingui::event_loop(){
        event _ev;
        gin.timer(300);
        int focus = -1;
        while(gin >> _ev && _ev.keycode != key_escape){
            if(_ev.type == ev_mouse && _ev.button==btn_left){
                for(size_t i = 0; i< widgets.size(); i++){
                    if(widgets[i]->is_selected(_ev.pos_x, _ev.pos_y)){
                    	if (focus != -1 && focus != i){
							widgets[focus]->handle(_ev);
						}
                        focus = i;
                        break;
                    }
                }
            }
            if(focus != -1){
                widgets[focus]->handle(_ev);
            }
            for(Widget * w : widgets){
                w->draw();
            }
            gout << refresh;
            gout << move_to(0,0) << color(0,0,0) << box(_xx, _yy);
        }
    }
