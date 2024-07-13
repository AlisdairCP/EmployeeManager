#include <fstream>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "admin.h"
#include <vector>
#include <sstream>

using namespace std;

Admin::Admin() {

}

void Admin::asAdmin() {
	int choice1;

	system("cls");

	cout << "Logged in as admin" << endl;
	cout << "1. Return to Main Menu" << endl;
	cout << "2. View Employee List" << endl;
	cout << "3. Add Employee" << endl;
	cout << "4. Delete Employee" << endl;
	cout << "5. Update Employee" << endl;
	cout << "6. Exit Manager" << endl;

	cout << "\nPick a number (1-6): " << endl;

	do {
		cin >> choice1;
		{
			switch (choice1) {
			case 1:
				manaMain();
				break;
			case 2:
				view();
				break;
			case 3:
				add();
				break;
			case 4:
				removeEmployeeData();
				break;
			case 5:
				update();
				break;
			case 6:
				exitProgram();
				break;
			default:
				system("cls");
				cout << "Input not recognised..." << endl;
				cout << "\n1. Return to Main Menu" << endl;
				cout << "2. View Employee List" << endl;
				cout << "3. Add Employee" << endl;
				cout << "4. Delete Employee" << endl;
				cout << "5. Update Employee" << endl;
				cout << "6. Exit Manager" << endl;
				cout << "\nPick a number (1-6): " << endl;
				cin.clear();
				cin.ignore();
				break;
			}
		}
	} while (choice1 != 6);
}

void Admin::manaMain() {
	int choice2;

	system("cls");
	cout << "Entering Main Menu" << endl;
	Sleep(500);

	system("cls");
	cout << "1. Login as Admin" << endl;
	cout << "2. Login as Employee" << endl;
	cout << "3. Exit Manager" << endl;

	cout << "\nPick a number (1-3): " << endl;
	do {
		cin >> choice2;
		{
			switch (choice2) {
			case 1:
				verifyAdmin();
				break;
			case 2:
				system("cls");
				cout << "Logging in as an employee...";
				asEmployee();
				break;
			case 3:
				exitProgram();
				break;
			default:
				system("cls");
				cout << "Input not recognised..." << endl;
				cout << "\n1. Login as Admin" << endl;
				cout << "2. Login as Employee" << endl;
				cout << "3. Exit Manager" << endl;
				cout << "\nPick a number (1-3): " << endl;
				cin.clear();
				cin.ignore();
				break;
			}
		}
	} while (choice2 != 3);
}

void Admin::exitProgram() {
	system("cls");
	cout << "Exiting";

	for (int i = 0; i < 5; i++) {
		Sleep(500);
		cout << ".";
	}
	exit(0);
}

void Admin::removeEmployeeData() {
	fstream fInput;
	fstream fOutput;

	string fileName;
	string fileType;
	string line;
	string val;
	string id;
	string newId;
	string encore;

	system("cls");

	int freshEmp;
	int count = 0;
	int entry_size;

	vector<string> entry;


	cout << "Enter file" << endl;
	while (fileType != ".csv") {
		cin >> fileName;
		if (fileName == "Menu" || fileName == "menu" || fileName == "MENU") {
			manaMain();
		}
		else if (fileName.length() < 5) {
			cout << "File name is too small." << endl;
			cout << "Enter file or type 'menu' to return to the main menu." << endl;
			cin.clear();
			cin.ignore();
		}
		else {
			fileType = fileName.substr(fileName.length() - 4, fileName.length() - 1);
			if (fileType != ".csv") {
				cout << "Input not recognised..." << endl;
				cout << "Enter file or type 'menu' to return to the main menu." << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
	cout << "\nInput accepted" << endl;
	
	fInput.open(fileName, ios::in);

	cout << "\nEnter employee ID to be deleted" << endl;
	cin >> id;

	fOutput.open("newfile.csv", ios::out);

	while (!fInput.eof()) {
		entry.clear();

		getline(fInput, line);
		stringstream striStre(line);

		while (getline(striStre, val, ',')) {
			entry.push_back(val);
		}

		entry_size = entry.size();

		if (entry_size == 0) {
			break;
		}
		newId = entry[0];

		if (newId != id) {
			for (int i = 0; i < entry_size - 1; i++) {
				fOutput << entry[i] << ',';
			}
			fOutput << entry[entry_size - 1] << '\n';
		}
		else {
			count = 1;
		}
	}

	if (count == 1) {
		cout << "Employee data deleted";
	}
	else {
		cout << "Employee data not found";
	}

	fInput.close();
	fOutput.close();

	const char* chFN = fileName.c_str();
	remove(chFN);
	rename("newfile.csv", chFN);

	encore = "";
	while (encore != "y" || encore != "Y" || encore != "n" || encore != "N") {
		cout << "\nDelete another record (Y/N)?:" << endl;

		cin >> encore;

		if (encore == "y" || encore == "Y") {
			removeEmployeeData();
		}
		else if (encore == "n" || encore == "N") {
			asAdmin();
		}
		else {
			cout << "Invalid option" << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

void Admin::update() {
	system("cls");

	fstream fInput;
	fstream fOutput;

	string fileName;
	string fileType;
	string record;
	string line;
	string val;
	string id;
	string newId;
	string encore;

	char area;

	int index;
	int entry_size;
	int count = 0;

	vector<string> entry;

	cout << "Enter file" << endl;
	while (fileType != ".csv") {
		cin >> fileName;
		if (fileName == "Menu" || fileName == "menu" || fileName == "MENU") {
			manaMain();
		}
		else if (fileName.length() < 5) {
			cout << "File name is too small." << endl;
			cout << "Enter file or type 'menu' to return to the main menu." << endl;
			cin.clear();
			cin.ignore();
		}
		else {
			fileType = fileName.substr(fileName.length() - 4, fileName.length() - 1);
			if (fileType != ".csv") {
				cout << "Input not recognised..." << endl;
				cout << "Enter file or type 'menu' to return to the main menu." << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
	cout << "\nInput accepted" << endl;

	fInput.open(fileName, ios::in);

	cout << "Enter employee number to be updated" << endl;
	cin >> id;

	cout << "Enter the first letter of a field" << endl;
	cout << "N/P/B/R/W/S" << endl;
	cout << "Enter 'H' to know which letter represents what." << endl;
	cin >> area;

	if (area == 'h' || area == 'H') {
		cout << "N = Name" << endl;
		cout << "P = Post code" << endl;
		cout << "B = Date of birth" << endl;
		cout << "R = Job role" << endl;
		cout << "W = Working hours" << endl;
		cout << "S = Salary" << endl;
		cin >> area;
	}
	
	else if (area == 'n' || area == 'N') {
		index = 1;
	}
	
	else if (area == 'p' || area == 'P') {
		index = 2;
	}

	else if (area == 'b' || area == 'B') {
		index = 3;
	}

	else if (area == 'r' || area == 'R') {
		index = 4;
	}

	else if (area == 'w' || area == 'W') {
		index = 5;
	}

	else if (area == 's' || area == 'S') {
		index = 6;
	}

	else {
		cout << "Input not recognised" << endl;
		cin >> area;
	}

	cout << "Enter new record:" << endl;
	cin >> record;

	fOutput.open("newfile.csv", ios::out);

	while (!fInput.eof()) {
		entry.clear();

		getline(fInput, line);
		stringstream striStre(line);

		while (getline(striStre, val, ',')) {
			entry.push_back(val);
		}

		entry_size = entry.size();

		if (entry_size == 0) {
			break;
		}

		newId = entry[0];

		if (newId == id) {
			count = 1;

			entry[index] = record;

			for (int i = 0; i < entry_size - 1; i++) {
				fOutput << entry[i] << ',';
			}
			fOutput << entry[entry_size - 1] << '\n';
		}
		else {
			for (int i = 0; i < entry_size - 1; i++) {
				fOutput << entry[i] << ',';
			}
			fOutput << entry[entry_size - 1] << '\n';
		}
	}

	if (count == 1) {
		cout << "Employee record updated";
	}
	else {
		cout << "Employee record not found";
	}

	fInput.close();
	fOutput.close();

	const char* chFN = fileName.c_str();
	remove(chFN);
	rename("newfile.csv", chFN);

	encore = "";
	while (encore != "y" || encore != "Y" || encore != "n" || encore != "N") {
		cout << "\nUpdate another record (Y/N)?:" << endl;

		cin >> encore;

		if (encore == "y" || encore == "Y") {
			update();
		}
		else if (encore == "n" || encore == "N") {
			asAdmin();
		}
		else {
			cout << "Invalid option" << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

void Admin::add() {
	system("cls");

	string fileName;
	string fileType;
	string name;
	string postCode;
	string jobRole;
	string dOB;
	string hours;
	string salary;
	string encore;
	string number;

	cout << "Enter file" << endl;
	while (fileType != ".csv") {
		cin >> fileName;
		if (fileName == "Menu" || fileName == "menu" || fileName == "MENU") {
			manaMain();
		}
		else if (fileName.length() < 5) {
			cout << "File name is too small." << endl;
			cout << "Enter file or type 'menu' to return to the main menu." << endl;
			cin.clear();
			cin.ignore();
		}
		else {
			fileType = fileName.substr(fileName.length() - 4, fileName.length() - 1);
			if (fileType != ".csv") {
				cout << "Input not recognised..." << endl;
				cout << "Enter file or type 'menu' to return to the main menu." << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
	cout << "\nInput accepted" << endl;

	fstream appendedFile(fileName, ios::app);

	cout << "\nEnter ID:" << endl;
	cin >> number;
	appendedFile << "\n" + number << ",";

	cout << "Enter name:" << endl;
	cin >> name;
	appendedFile << name << ",";

	cin.clear();
	cin.ignore();

	cout << "Enter post code:" << endl;
	getline(cin, postCode);
	appendedFile << postCode << ",";

	cout << "Enter date of birth:" << endl;
	cin >> dOB;
	appendedFile << dOB << ",";

	cin.clear();
	cin.ignore();

	cout << "Enter job role:" << endl;
	std::getline(cin, jobRole);
	appendedFile << jobRole << ",";

	cout << "Enter working hours:" << endl;
	cin >> hours;
	appendedFile << hours << ",";

	cout << "Enter salary:" << endl;
	cin >> salary;
	appendedFile << salary;

	appendedFile.close();

	cout << "Record added" << endl;
	encore = "";
	while (encore != "y" || encore != "Y" || encore != "n" || encore != "N") {
		cout << "\nAdd a new record (Y/N)?:" << endl;

		cin >> encore;

		if (encore == "y" || encore == "Y") {
			add();
		}
		else if (encore == "n" || encore == "N") {
			asAdmin();
		}
		else {
			cout << "Invalid option" << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

void Admin::view() {
	system("cls");

	string fileName;
	string fileType;
	string name;
	string postCode;
	string jobRole;
	string dOB;
	string hours;
	string salary;
	string number;
	
	int choice3;

	cout << "Enter file" << endl;
	while (fileType != ".csv") {
		cin >> fileName;
		if (fileName == "Menu" || fileName == "menu" || fileName == "MENU") {
			manaMain();
		}
		else if (fileName.length() < 5) {
			cout << "File name is too small." << endl;
			cout << "Enter file or type 'menu' to return to the main menu." << endl;
			cin.clear();
			cin.ignore();
		}
		else {
			fileType = fileName.substr(fileName.length() - 4, fileName.length() - 1);
			if (fileType != ".csv") {
				cout << "Input not recognised..." << endl;
				cout << "Enter file or type 'menu' to return to the main menu." << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
	cout << "\nInput accepted" << endl;

	fstream checkedFile(fileName);

	cout << "\nEmployee Record" << endl;
	cout << "\nID | Name | Post Code | Date of Birth | Job Role | Working Hours | Salary" << endl;

	while (!checkedFile.eof()) {
		getline(checkedFile, number, ',');
		getline(checkedFile, name, ',');
		getline(checkedFile, postCode, ',');
		getline(checkedFile, dOB, ',');
		getline(checkedFile, jobRole, ',');
		getline(checkedFile, hours, ',');
		getline(checkedFile, salary, '\n');

		if (number != "") {
			cout << number << " | " << name << " | " << postCode << " | " << dOB << " | " << jobRole << " | " << hours << " | " << salary << endl;
		}
	}
	checkedFile.close();

	cout << "\n1. New Record" << endl;
	cout << "2. Remove Record" << endl;
	cout << "3. Update Record" << endl;
	cout << "4. Main Menu" << endl;
	cout << "5. Exit" << endl;

	cout << "\nPick a number (1-5): " << endl;
	do {
		cin >> choice3;
		switch (choice3) {
		case 1:
			add();
			break;
		case 2:
			removeEmployeeData();
			break;
		case 3:
			update();
			break;
		case 4:
			manaMain();
			break;
		case 5:
			exitProgram();
			break;
		default:
			cout << "Input not recognised..." << endl;
			cout << "\nPick a number (1-5): " << endl;
		}
	} while (choice3 != 5);

}

void Admin::verifyAdmin() {
	system("cls");

	string pword;

	cout << "Enter Password:" << endl;

	do {
		cin >> pword;

		if (pword != "password") {
			cout << "Incorrect password" << endl;
			cout << "Try again or type 'menu' to return to the main menu." << endl;
		}

		if (pword == "Menu" || pword == "menu" || pword == "MENU") {
			manaMain();
		}
	}

	while (pword != "password");
	
	cout << "Password accepted" << endl;
	asAdmin();
}

void Admin::asEmployee() {
	system("cls");

	string fileName;
	string fileType;
	string name;
	string postCode;
	string jobRole;
	string dOB;
	string hours;
	string salary;
	string number;

	cout << "Enter file" << endl;
	while (fileType != ".csv") {
		cin >> fileName;
		if (fileName == "Menu" || fileName == "menu" || fileName == "MENU") {
			manaMain();
		}
		else if (fileName.length() < 5) {
			cout << "File name is too small." << endl;
			cout << "Enter file or type 'menu' to return to the main menu." << endl;
			cin.clear();
			cin.ignore();
		}
		else {
			fileType = fileName.substr(fileName.length() - 4, fileName.length() - 1);
			if (fileType != ".csv") {
				cout << "Input not recognised..." << endl;
				cout << "Enter file or type 'menu' to return to the main menu." << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
	cout << "\nInput accepted" << endl;

	fstream viewedFile(fileName);

	if (!viewedFile) {
		cout << "Error opening file" << endl;
	}

	else {
		cout << "\nEmployee Record" << endl;
		cout << "\nID | Name | Post Code | Date of Birth | Job Role | Working Hours | Salary" << endl;

		while (!viewedFile.eof()) {
			getline(viewedFile, number, ',');
			getline(viewedFile, name, ',');
			getline(viewedFile, postCode, ',');
			getline(viewedFile, dOB, ',');
			getline(viewedFile, jobRole, ',');
			getline(viewedFile, hours, ',');
			getline(viewedFile, salary, '\n');

			if (number != "") {
				cout << number << " | " << name << " | " << postCode << " | " << dOB << " | " << jobRole << " | " << hours << " | " << salary << endl;
			}
		}
	}
	viewedFile.close();
	system("pause");
	manaMain();
}