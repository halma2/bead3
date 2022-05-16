#ifndef POTTYTABLA_HPP
#define POTTYTABLA_HPP

#include "Widget.hpp"


class pottytabla : public Widget
{	int ** tablahiv;
	public:
		pottytabla(wingui * w, int x, int y, int sx, int sy, int** t);
		virtual void draw();
        void kor_rajz(const float& x, const float& y, const int& r);
        virtual void handle(genv::event ev){}
};

#endif // POTTYTABLA_HPP
