#ifndef INPUTTEXT_HPP
#define INPUTTEXT_HPP
#include "Widget.hpp"
#include "graphics.hpp"

class inputText: public Widget
{
    std::string _text = "";
    public:
        inputText(wingui * w, int x, int y, int sx, int sy);
        virtual void draw();
        virtual void handle(genv::event ev);
        void write(std::string ezt) {_text = ezt;}
};

#endif // INPUTTEXT_HPP
