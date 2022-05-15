#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP
#include "Widget.hpp"
#include "graphics.hpp"

class staticText : public Widget
{
    const int keret = 3;
    std::string _text = "";
    public:
        staticText(wingui * w, int x, int y, int sx, int sy, std::string it);
        virtual void draw();
        virtual void handle(genv::event ev){}

};

#endif // STATICTEXT_HPP
