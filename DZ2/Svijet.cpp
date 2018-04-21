#include "Svijet.h"
#include<iostream>
#include<assert.h>

int i, j;

Svijet::Svijet(int &redak, int& stupac)
{
	this->redak = redak;
	this->stupac = stupac;
	svijet = new std::string*[redak];
	for (i = 0; i<redak; i++)
	{
		svijet[i] = new std::string[stupac];
		for (j = 0; j<stupac; j++)
			svijet[i][j] = "[ ]";
	}
}

void Svijet::render_svijet()
{
	for (i = 0; i < redak; i++)
		for (j = 0; j < stupac; j++)
		{
			if (generate_random(0, 4) == 4) {
				svijet[i][j] = "[+]";
			}
			else {
				svijet[i][j] = "[ ]";
			}
		}
}

void Svijet::update_svijet()
{
	for (i = 0; i < redak; i++) {
		for (j = 0; j < stupac; j++) {
			if (svijet[i][j] == "[+]") {
				ziv = true;
				lokacijax = i;
				lokacijay= j;
				lokacija();
			}
			else {
				ziv = false;
				lokacijax = i;
				lokacijay = j;
				lokacija();
			}
		}
	}
	stvori_novi_svijet();
}

void Svijet::draw_svijet()
{
	for (i = 0; i < redak; i++) {
		for (j = 0; j < stupac; j++)
		{
			std::cout << svijet[i][j];
		}
		std::cout << std::endl;
	}
}

Svijet::~Svijet()
{
	for (i = 0; i<redak; i++)
		delete[] svijet[i];
	delete[] svijet;
}

int Svijet::generate_random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void Svijet::stvori_novi_svijet()
{
	for (i = 0; i < redak; ++i) {
		for (j = 0; j < stupac; ++j) {
			svijet[i][j] = novi_svijet[brojac];
			brojac++;
		}
	}
}

void Svijet::lokacija()
{
	assert(svijet[lokacijax][lokacijay] == "[ ]" || svijet[lokacijax][lokacijay] == "[+]");
	if (lokacijax == 0 && lokacijay == 0) {
		gore_lijevo();
	}
	else if (lokacijax == 0 && lokacijay == stupac - 1) {
		gore_desno();
	}
	else if (lokacijax == redak - 1 && lokacijay == 0) {
		dolje_lijevo();
	}
	else if (lokacijax == redak - 1 && lokacijay == stupac - 1){
		dolje_desno();
	}
	else if (lokacijax == 0 && !((lokacijax == 0 && lokacijay == stupac - 1) || (lokacijax == 0 && lokacijay == 0))) {
		gore();
	}
	else if (lokacijay == 0 && !((lokacijax == redak - 1 && lokacijay == 0) || (lokacijax == 0 && lokacijay == 0))) {
		lijevo();
	}
	else if (lokacijay == stupac - 1 && !((lokacijax == 0 && lokacijay == stupac - 1) || (lokacijax == redak - 1 && lokacijay == stupac - 1))) {
		desno();
	}
	else if (lokacijax == redak - 1 && !((lokacijax == redak - 1 && lokacijay == stupac - 1) || (lokacijax == redak - 1 && lokacijay == 0))) {
		dolje();
	}
	else {
		sredina();
	}
}

void Svijet::gore_lijevo()
{
	desno_od();
	dolje_desno_od();
	dolje_od();
	odluka();
	
}

void Svijet::gore()
{
	desno_od();
	dolje_desno_od();
	dolje_od();
	dolje_lijevo_od();
	lijevo_od();
	odluka();
}

void Svijet::gore_desno()
{
	dolje_od();
	dolje_lijevo_od();
	lijevo_od();
	odluka();
}

void Svijet::lijevo()
{
	gore_od();
	gore_lijevo_od();
	desno_od();
	dolje_desno_od();
	dolje_od();
	odluka();

}

void Svijet::desno()
{
	dolje_od();
	dolje_lijevo_od();
	lijevo_od();
	gore_lijevo_od();
	gore_od();
	odluka();
}

void Svijet::dolje_lijevo()
{
	gore_od();
	gore_desno_od();
	desno_od();
	odluka();
}

void Svijet::dolje()
{
	lijevo_od();
	gore_lijevo_od();
	gore_od();
	gore_desno_od();
	desno_od();
	odluka();
}

void Svijet::dolje_desno()
{
	gore_od();
	gore_lijevo_od();
	lijevo_od();
	odluka();
}

void Svijet::sredina()
{
	gore_lijevo_od();
	gore_od();
	gore_desno_od();
	desno_od();
	dolje_desno_od();
	dolje_od();
	dolje_lijevo_od();
	lijevo_od();
	odluka();
}

void Svijet::gore_lijevo_od()
{
	if (svijet[lokacijax - 1][lokacijay - 1] == "[+]") {
		ukupno++;
	}
}

void Svijet::gore_od()
{
	if (svijet[lokacijax - 1][lokacijay] == "[+]") {
		ukupno++;
	}
}

void Svijet::gore_desno_od()
{
	if (svijet[lokacijax - 1][lokacijay + 1] == "[+]") {
		ukupno++;
	}
}

void Svijet::lijevo_od()
{
	if (svijet[lokacijax][lokacijay - 1] == "[+]") {
		ukupno++;
	}
}

void Svijet::desno_od()
{
	if (svijet[lokacijax][lokacijay + 1] == "[+]") {
		ukupno++;
	}
}

void Svijet::dolje_lijevo_od()
{
	if (svijet[lokacijax + 1][lokacijay - 1] == "[+]") {
		ukupno++;
	}
}

void Svijet::dolje_od()
{
	if (svijet[lokacijax + 1][lokacijay] == "[+]") {
		ukupno++;
	}

}

void Svijet::dolje_desno_od()
{
	if (svijet[lokacijax + 1][lokacijay + 1] == "[+]") {
		ukupno++;
	}
}

void Svijet::odluka()
{
	if (ziv) {
		if (ukupno == 2 || ukupno == 3)
			novi_svijet.push_back("[+]");
		else {
			novi_svijet.push_back("[ ]");
		}
	}
	else {
		if (ukupno == 3)
			novi_svijet.push_back("[+]");
		else {
			novi_svijet.push_back("[ ]");
		}
	}
	//ocisti
	ukupno = 0;
}
