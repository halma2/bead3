#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include "Widget.hpp"
#include "button.hpp"
#include <string>

class spinbox : public Widget
{
protected:
		int number, legkisebb, legnagyobb;
		std::string tmp;
		button * b1;
		button * b2;
		bool megnyomhato;
public:
		spinbox(wingui * w, int x, int y, int sx, int sy, int lk, int ln);
		virtual void draw();
		virtual void handle(genv::event ev);
		int getValue(){return number;}
		void novel(int plusz){
			number += plusz;
			tmp = std::to_string(number);
			megnyomhato = false;
		}
};

#endif // SPINBOX_HPP
