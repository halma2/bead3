#include "wingui.hpp"
#include "Widget.hpp"
#include "button.hpp"
#include "inputText.hpp"
#include "staticText.hpp"
#include "dropdown.hpp"
#include "pottytabla.hpp"
#include <vector>
using namespace std;

const int XX = 900;
const int YY = 600;

struct Ablak : public wingui{
	bool jatekos1_kore = 1;
	bool jatekon_jivul = true;

	int * pontszam;
	int** tabla;

    staticText * s1;
    staticText * s2;
    staticText * p1;
    staticText * p2;
    inputText * pont1;
    inputText * pont2;
    inputText * jatekos_kore_jelzo;
    vector<button*> * oszlopgombok;
    button * resetGomb;
    button * restartGomb;
    pottytabla * ptabla;

	Ablak(const int& xx, const int& yy):wingui(xx,yy) {
		pontszam = new int[2];
		pontszam[0] = 0;
		pontszam[1] = 0;
		tabla = new int*[6];
		for(int i = 0; i < 7; ++i){
			tabla[i] = new int[6];
			for (int j = 0; j < 6; j++){
				tabla[i][j] = 0;
			}
		}



		s1 = new staticText(this,50,30,80,30,"Jatekos1");
		s2 = new staticText(this,XX-80-50,30,80,30,"Jatekos2");
		pont1 = new inputText(this,45,80,40,30);
		pont2 = new inputText(this,XX-90-40,80,40,30);
		p1 = new staticText(this,90,80,40,30,"pont");
		p2 = new staticText(this,XX-45-40,80,40,30,"pont");
		jatekos_kore_jelzo = new inputText(this,XX/2-120/2,50,120,30);
		oszlopgombok = new vector<button*>();
		for (int i = 0; i < 7; i++){
			oszlopgombok->push_back(new button(this,200+80*i,100,20,20,"V"));
			oszlopgombok->at(i)->lambd = [=](){lerakas(i);};
		}
		restartGomb = new button(this,XX-80-60-20,500,80,40,"New Game");
		resetGomb = new button(this,XX-60-20,500,60,40,"Reset");
		resetGomb->lambd = [=](){pontszam[0] = 0; pontszam[1] = 0;};
		restartGomb->lambd = [=](){elokeszites();};
		ptabla = new pottytabla(this,XX/2-275,150,275*2,YY-1-150,tabla);
    }




    ///Innentol mas osztalyba kerulnek, egy grafik, es egy gm class-ba












    void kovi_kor(){
		jatekos1_kore = !jatekos1_kore;
		jatekos_kore_jelzo->write("jatekos"+jatekos1_kore+1);
    }




    void elokeszites(){

		//marad:
		//1.menu eltuntetes, blokkolaskezeles
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < 6; j++){
				tabla[i][j] = 0;
			}
		}
		jatekos1_kore = 1;
		//felirateltuntetes,pontfeltuntet
		//elso kor meghivasa
		kovi_kor();

    }



    void sorozatkereses(){
		int maxsor = 0;
		bool nyert = false;

		//1.nezopont:sor
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < 6; j++){
				if (tabla[i][j] == jatekos1_kore + 1)
					maxsor++;
				else maxsor = 0;
			}
				if (maxsor >= 4){
					nyert = true;
					break;//return true
				}
		}


		//2.nezopont:oszlop
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 7; j++){
				if (tabla[j][i] == jatekos1_kore + 1)
					maxsor++;
				else maxsor = 0;
			}
				if (maxsor >= 4){
					nyert = true;
					break;//return true
				}
		}

		//3.nezopont: atlo!!!

    }







	void lerakas(int hova){
		for (int i = 0; i < 6; i++){
			if (tabla[hova][i] == 0){//ha tele van, baj van
				tabla[hova][i] == jatekos1_kore+1;
				break;
			}
		}
		//ell-nyertem?
		//kovikor()
	}



};

int main()
{
    Ablak a(XX, YY);
    a.event_loop();

    return 0;
}
