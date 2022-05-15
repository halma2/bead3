#include "wingui.hpp"
#include "Widget.hpp"
#include "button.hpp"
#include "inputText.hpp"
#include "staticText.hpp"
#include "pottytabla.hpp"
#include <vector>
using namespace std;

#include <iostream>

const int XX = 900;
const int YY = 600;

struct Ablak : public wingui{
	bool jatekos1_kore = 1;
	bool jatekon_kivul = true;

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
		jatekos_kore_jelzo->write("   Welcome!   ");
		oszlopgombok = new vector<button*>();
		for (int i = 0; i < 7; i++){
			oszlopgombok->push_back(new button(this,200+80*i,100,20,20,"V"));
			oszlopgombok->at(i)->lambd = [=](){lerakas(i);};
			oszlopgombok->at(i)->enabled = false;
		}
		restartGomb = new button(this,XX-80-60-20,500,80,40,"New Game");
		resetGomb = new button(this,XX-60-20,500,60,40,"Reset");
		resetGomb->lambd = [=](){
			pontszam[0] = 0; pontszam[1] = 0;
			pont1->write(to_string(pontszam[0]));
			pont2->write(to_string(pontszam[1]));
		};
		pont1->write(to_string(pontszam[0]));
		pont2->write(to_string(pontszam[1]));
		restartGomb->lambd = [=](){elokeszites();};
		ptabla = new pottytabla(this,XX/2-275,150,275*2,YY-1-150,tabla);
    }





    void kovi_kor(){
		jatekos1_kore = !jatekos1_kore;
		jatekos_kore_jelzo->write("Jatekos"+to_string(jatekos1_kore+1)+" köre");
    }

    void elokeszites(){
		restartGomb->enabled = false;
		resetGomb->enabled = false;

		for (int i = 0; i < 7; i++){
			oszlopgombok->at(i)->enabled = true;
			for (int j = 0; j < 6; j++){
				tabla[i][j] = 0;
			}
		}
		jatekos1_kore = 1;
		//elso kor meghivasa
		kovi_kor();

    }





    bool talalt_sorozat(){
		int maxsor = 0;

		//1.nezopont: oszlop
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < 6; j++){
				if (tabla[i][j] == jatekos1_kore + 1)
					maxsor++;
				else maxsor = 0;
				if (maxsor >= 4)
					return true;
			}
		}

		//2.nezopont:oszlop
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 7; j++){
				if (tabla[j][i] == jatekos1_kore + 1)
					maxsor++;
				else maxsor = 0;
				if (maxsor >= 4)
					return true;
			}
		}

		//3.nezopont: atlo!!!
		return false;
    }







	void lerakas(int hova){
		for (int i = 0; i < 6; i++){
			if (tabla[hova][i] == 0){
				tabla[hova][i] = jatekos1_kore+1;
				if (i == 5){
					oszlopgombok->at(hova)->enabled = false;
				}
				break;
			}
		}

		if (talalt_sorozat()){
			jatekos_kore_jelzo->write("Jatekos" + to_string(jatekos1_kore+1) + " nyert!");
			for (int i = 0; i < 7; i++){
				oszlopgombok->at(i)->enabled = false;
				restartGomb->enabled = true;
				resetGomb->enabled = true;
			}
			pontszam[jatekos1_kore]++;
			pont1->write(to_string(pontszam[0]));
			pont2->write(to_string(pontszam[1]));
		}
		else kovi_kor();
	}
};

int main()
{
    Ablak a(XX, YY);
    a.event_loop();

    return 0;
}
