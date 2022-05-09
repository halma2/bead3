#ifndef lista_HPP
#define lista_HPP
#include <vector>
#include "Widget.hpp"
#include "button.hpp"
using namespace std;

class lista : public Widget
{
protected:
		int elemnt_size, _index, _hovered, e_x, e_y;
		vector<string> * _tomb;

public:
		lista(wingui * w, int x, int y, int sx, int sy, int es, vector<string> * sv);
		void draw();
		void handle(genv::event ev);
		bool is_hovered(genv::event ev, const int& ix);
		string getValue(){return _tomb->at(_index);}
		bool is_not_empty() {return _tomb->size() > 0;}
		string cut();
		void paste(string szov){
            _tomb->push_back(szov);
		}
};

#endif // lista_HPP
