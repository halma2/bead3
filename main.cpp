#include "wingui.hpp"
#include "Widget.hpp"
#include "button.hpp"
#include "inputText.hpp"
#include "plcheckbox.hpp"
#include "staticText.hpp"
#include "pottytabla.hpp"
#include <vector>
using namespace std;

//#include <unistd.h>
#include <iostream>

const int XX = 900;
const int YY = 600;

struct Ablak : public wingui{
	bool jatekos1_kore = 1;
	bool gepi_jatekosMod = false;

	int * pontszam;
	int** tabla;
	bool * teltOszlop;

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
    plcheckbox * cb;
    staticText * aifel;

	Ablak(const int& xx, const int& yy):wingui(xx,yy) {
		pontszam = new int[2];
		pontszam[0] = 0;
		pontszam[1] = 0;
		teltOszlop = new bool[7];
		tabla = new int*[7];
		for(int i = 0; i < 7; ++i){
			tabla[i] = new int[6];
			for (int j = 0; j < 6; j++){
				tabla[i][j] = 0;
			}
		}

		s1 = new staticText(this,40,30,120,30,"Jatekos1-piros");
		s2 = new staticText(this,XX-120-40,30,120,30,"Jatekos2-zöld");
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
		resetGomb = new button(this,XX-60-10,500,50,40,"Reset");
		resetGomb->lambd = [=](){
			pontszam[0] = 0; pontszam[1] = 0;
			pont1->write(to_string(pontszam[0]));
			pont2->write(to_string(pontszam[1]));
		};
		pont1->write(to_string(pontszam[0]));
		pont2->write(to_string(pontszam[1]));
		restartGomb->lambd = [=](){elokeszites();};
		ptabla = new pottytabla(this,XX/2-275,150,275*2,YY-1-150,tabla);
		cb = new plcheckbox(this,XX-50,YY-40,30,30);
		aifel = new staticText(this,XX-160,YY-40,100,30,"AI player");
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
			teltOszlop[i] = false;
			for (int j = 0; j < 6; j++){
				tabla[i][j] = 0;
			}
		}
		//ide jon, h jatekoskore2-nel blokkolva legyen az oszlopgombok, helyette a gepi lepest hivja meg
		gepi_jatekosMod = cb->is_checked();

		jatekos1_kore = 1;
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
			maxsor = 0;
		}

		//2.nezopont:sor
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 7; j++){
				if (tabla[j][i] == jatekos1_kore + 1)
					maxsor++;
				else maxsor = 0;
				if (maxsor >= 4)
					return true;
			}
			maxsor = 0;
		}

		//3.nezopont: atlo!!!
			//3.1: jobbfel
		int i2 = 0;
		int j2 = 0;
		for (int i = 0; i < 7-3; i++){
			for (int j = 0; j < 6-3; j++)
			{
				if (tabla[i][j] == jatekos1_kore+1)
				{
					for (i2 = i, j2 = j; i2 < 7, j2 < 6; i2++, j2++)
					{
						if (tabla[i2][j2] == jatekos1_kore+1)
							maxsor++;
						else break;
						if (maxsor >= 4)
							return true;;
					}
				}

				maxsor = 0;
			}
		}

		//3.2: jobble
		for (int i = 0; i < 7-3; i++){
			for (int j = 5; j >= 3; j--)
			{
				if (tabla[i][j] == jatekos1_kore+1)
				{
					for (i2 = i, j2 = j; i2 < 7, j2 >= 0; i2++, j2--)
					{
						if (tabla[i2][j2] == jatekos1_kore+1)
							maxsor++;
						else break;
						if (maxsor >= 4)
							return true;;
					}
				}
				maxsor = 0;
			}
		}
		return false;
    }

    void pottyant(const int& ide, bool isj1){
		for (int i = 0; i < 6; i++){
			if (tabla[ide][i] == 0){
				tabla[ide][i] = isj1+1;
				if (i == 5){
					oszlopgombok->at(ide)->enabled = false;
					teltOszlop[ide] = true;
				}
				return;
			}
		}
    }


	void lerakas(const int hova){
		pottyant(hova, jatekos1_kore);

		bool tele = true;
		for (int i = 0; i < 7; i++){
			if (!teltOszlop[i]) tele = false;
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
		else if (tele){
			jatekos_kore_jelzo->write("Döntetlen!");
			for (int i = 0; i < 7; i++){
				oszlopgombok->at(i)->enabled = false;
				restartGomb->enabled = true;
				resetGomb->enabled = true;
			}
		}
		else {
			if (gepi_jatekosMod)
				gepLepes();
			for (int i = 0; i < 7; i++){
				if (!teltOszlop[i])
					oszlopgombok->at(i)->enabled = true;
			}
			kovi_kor();
		}
	}

	void gepLepes(){
		kovi_kor();
		for (int i = 0; i < 7; i++){
			oszlopgombok->at(i)->enabled = false;
		}
		int rakx = 0;
		int raky = 0;
		//1.biztos_nyeres->nyeres,lerakas_Vege()
		if (mintaLehtoseg(4, !jatekos1_kore, rakx, raky)){
			cout << "juhé!";
		}
		//2.blokkolás
		else if (mintaLehtoseg(4, jatekos1_kore, rakx, raky))
			cout << "ajaj";
		//3.par_kieg:
		else if (mintaLehtoseg(3, !jatekos1_kore, rakx, raky))
			cout << "hajra";
		//4.kiegeszites
		else if (mintaLehtoseg(2, !jatekos1_kore, rakx, raky))
			cout << "ok";
		//tiszta_korrel_kezdes
		else{
			pottyant(rand()%7, 1);
			cout << "start";//ha nem telt meg
		}
		//kovi_kor();//lerakas_vege
	}





	bool mintaLehtoseg(const int hanyat, const bool& kinek, int& jox, int& joy){///atlonal + szempontok: alatamasztas
		int maxsor = 0;
		bool volt1ures = false;
		/*for (int i = 0; i < 7; i++){
			for (int j = 0; j < 6; j++){

				if (tabla[i][j] == kinek + 1)
					maxsor++;
				else if (!volt1ures && tabla[i][j] == 0){
					maxsor++;
					volt1ures = true;
					jox = i;
					joy = j;
				}
				else{
					maxsor = 0;
					volt1ures = false;
				}
				if (maxsor >= hanyat)
					return true;
			}
			maxsor = 0;
			volt1ures = false;
		}*/

		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 7; j++){
				if (tabla[j][i] == jatekos1_kore + 1)
					maxsor++;
				else if (!volt1ures && tabla[j][i] == 0){
					maxsor++;
					volt1ures = true;
					jox = i;
					joy = j;
				}
				else{
					maxsor = 0;
					volt1ures = false;
				}
				if (maxsor >= hanyat)
					return true;
			}
			maxsor = 0;
			volt1ures = false;
		}


		//atlo
			//3.1: jobbfel+alatamasztas
		int i2 = 0;
		int j2 = 0;
		for (int i = 0; i < 7-3; i++){
			for (int j = 0; j < 6-3; j++)
			{
				if (tabla[i][j] == jatekos1_kore+1)
				{
					for (i2 = i, j2 = j; i2 < 7, j2 < 6; i2++, j2++)
					{
						if (tabla[i2][j2] == jatekos1_kore+1){
							maxsor++;
							if(j2 != 0){
								if (tabla[i2][j2-1] == 0)
									maxsor = 0;//
							}
						}

						else break;
						if (maxsor >= 4)
							return true;;
					}
				}

				maxsor = 0;
			}
		}
























		return false;
	}
};

int main()
{
    Ablak a(XX, YY);
    a.event_loop();

    return 0;
}
