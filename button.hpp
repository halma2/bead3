#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Widget.hpp"
#include <functional>
class button : public Widget
{
protected:
	std::string _text;
	bool pressed;
public:
		button(wingui * w, int x, int y, int sx, int sy, std::string text);
		virtual void draw();
		virtual void handle(genv::event ev);
		std::function<void()> lambd = [](){};
		void action(){lambd();}
		bool enabled;
		std::string getLabel() {return _text;}
};

#endif // BUTTON_HPP
