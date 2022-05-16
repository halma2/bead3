#ifndef WINGUI_HPP
#define WINGUI_HPP
#include "Widget.hpp"
#include <vector>

class wingui
{
protected:
	const int _xx;
    std::vector<Widget*> widgets;

public:
	const int _yy;
		wingui(const int& xx, const int& yy);
        void regWidget(Widget * w) {
            widgets.push_back(w);
        }
        void event_loop();
};

#endif // WINGUI_HPP
