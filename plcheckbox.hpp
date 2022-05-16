#ifndef PLCHECKBOX_HPP
#define PLCHECKBOX_HPP
#include "Widget.hpp"

class plcheckbox : public Widget
{
	protected:
		bool _checked;
	public:
		plcheckbox(wingui * w, int x, int y, int sx, int sy);
		virtual void draw();
		virtual void handle(genv::event ev);
		virtual const bool is_checked();
};

#endif // PLCHECKBOX_HPP
