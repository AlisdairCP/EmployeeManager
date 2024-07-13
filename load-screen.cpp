#include <fstream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "load-screen.h"
#include <iostream>

using namespace std;

LoadScreen::LoadScreen() {
}

void LoadScreen::bar() {
	system("cls");

	char a = 255;
	char b = 219;

	cout << "Employee Manager" << endl;
	cout << "Loading..." << endl;

	for (int i = 0; i < 5; i++) {
		cout << a << endl;
	}

	for (int i = 0; i < 10; i++) {
		cout << b;
		Sleep(200);
	}
}