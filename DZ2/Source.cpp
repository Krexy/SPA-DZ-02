#include<iostream>
#include<ctime>
#include<chrono>
#include<conio.h>
#include<Windows.h>
#include "Svijet.h"


int main()
{
	//window
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	//font
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(outcon, 0x0A);         //->>>>>>>>>>> AKO NEKOM VISE PASE ZELENA
	
	//setrandom
	srand(time(nullptr));

	//deklaracija
	int retci, stupci;

	//inicijalizacija
	std::cout << "Unesite zeljeni broj redaka i stupaca: ";
	std::cin >> retci >> stupci;
	Svijet svijet(retci, stupci);

	//start
	bool prvi_put = true;
	do {
		auto begin = std::chrono::high_resolution_clock::now();

		system("cls");
		if (prvi_put) {
			svijet.render_svijet();
			prvi_put = false;
		}
		else {
			svijet.update_svijet();
		}
		svijet.draw_svijet();

		std::cout << "Pritisnite bilo koju tipku za izlazak";

		auto end = std::chrono::high_resolution_clock::now();

		_sleep(2000 - std::chrono::duration_cast<std::chrono::milliseconds > (end - begin).count());

	} while (!_kbhit());

}