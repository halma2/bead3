#include "wingui.hpp"
#include "Widget.hpp"
#include "lista.hpp"
#include "button.hpp"
#include "spinbox.hpp"
#include "inputText.hpp"
#include <vector>
#include <fstream>
using namespace std;

const int XX = 1080;
const int YY = 480;

struct Ablak : public wingui{
	/*spinbox * s1;
	spinbox * s2;

	button * b1;
	button * b2;
	lista * l1;
	lista * l2;
	vector<string> * tomb1 =
		new vector<string>({"elso","masodik","harmadik","negyedik","otodik","hatodik","hetedik"});
	vector<string> * tomb2 = new vector<string>({"alma","korte","szilva"});*/

    //inputText * kijelzo;


	Ablak(const int& xx, const int& yy):wingui(xx,yy) {
       /* s1 = new spinbox(this,720,20,120,50,-15,5);
        s2 = new spinbox(this,630,120,80,100,5,100);

        b1 = new button(this, 300, 60, 30, 30, "->");
        b1->lambd = [&](){d12pakol();};
        b2 = new button(this, 300, 100, 30, 30, "<-");
		b2->lambd = [&](){d21pakol();};

        l1 = new lista(this,100,60,150,400,30,tomb1);
        l2 = new lista(this,420,60,150,400,30,tomb2);*/
    }


    /*virtual void kiiratas() override{
		ofstream f("ertekek.txt");
		/*f << "s1: " << s1->getValue() << "\ns2: " << s2->getValue() <<
		"\nl1: " << l1->getValue() << "\nl2: " << l2->getValue();*/
		f.close();
    }*/
};

int main()
{
    Ablak a(XX, YY);
    a.event_loop();

    return 0;
}
