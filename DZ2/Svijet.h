#pragma once
#include<string>
#include<vector>

class Svijet
{
public:
	Svijet(int & retci, int & stupci);
	void render_svijet();
	void update_svijet();
	void draw_svijet();
	~Svijet();
private:
	int generate_random(int min, int max);
	void stvori_novi_svijet();
	void lokacija();
	void gore_lijevo();
	void gore();
	void gore_desno();
	void lijevo();
	void desno();
	void dolje_lijevo();
	void dolje();
	void dolje_desno();
	void sredina();
	void gore_lijevo_od();
	void gore_od();
	void gore_desno_od();
	void lijevo_od();
	void desno_od();
	void dolje_lijevo_od();
	void dolje_od();
	void dolje_desno_od();
	void odluka();
private:
	int redak, stupac;
	std::string ** svijet;   //sad sa unique pointerima
	std::vector<std::string> novi_svijet;
	unsigned long long brojac = 0;
	int lokacijax;
	int lokacijay;
	int ukupno = 0;
	bool ziv;
};