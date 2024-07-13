#include <iostream>
#include <string>
#include <Windows.h>

#include "load-screen.h"
#include "admin.h"

using namespace std;

void verifyPWord(void);
//void main(void);

Admin admin = Admin();
LoadScreen load = LoadScreen();

void verifyPWord() {
	system("cls");

	string pWord;

	cout << "Enter Password:" << endl;

	do {
		cin >> pWord;

		if (pWord != "password") {
			cout << "Incorrect password..." << endl;
			cout << "Please try again or enter 'exit' to exit the program:" << endl;
		}

		if (pWord == "exit" || pWord == "Exit" || pWord == "EXIT") {
			admin.exitProgram();
		}
	} while (pWord != "password");
	admin.manaMain();
}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	system("color B0");

	load.bar();
	verifyPWord();

	return 0;
}


