#ifndef INPUTTEXT_HPP
#define INPUTTEXT_HPP
#include "Widget.hpp"
#include "graphics.hpp"

class inputText: public Widget
{
    int keret = 3;
    std::string _text = "";
    public:
        inputText(wingui * w, int x, int y, int sx, int sy);
        virtual void draw();
        virtual void handle(genv::event ev);
        void write(std::string ezt) {_text = ezt;}
        std::string read() {return _text;}
};

#endif // INPUTTEXT_HPP
