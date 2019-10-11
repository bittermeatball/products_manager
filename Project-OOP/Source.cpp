#include <iostream>
#include <string>
#include <conio.h>
#include "Helpers.h"
#include "ProductController.h"
// Remember to put CPP file in here for it to complie , you can avoid Undefined Reference error

using namespace std;

Helpers help_menu;

void showMenu();
void navigator(int picked_work);
//
//
void showMenu() {
	help_menu.clearScreen();

	int picked_work;

	cout << "Choose your work :" << endl;

	// Create work list, change n if you add more works
	const int n = 6;

	string works_list[n] = {
		"Create a Product",
		"Show products list",
		"Show products's categories list",
		"Find a product",
		"Delete a product",
		"Delete products in quantity of 100"
	};

	// Create beautiful index
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " | ";
		for (int j = 0; j < 70 - works_list[i].length(); j++) {
			cout << "-";
		};
		cout << " | " << works_list[i] << " | " << endl;
	}

	// Get user's choice of work
	cout << "Type in the work's index number : ";
	cin >> picked_work;

	// Clear the error in case of an invalid input
	cin.clear();
	// Take the error in the buffer out
	cin.ignore();

	// If user chooses the wrong index
	if (picked_work > n || picked_work < 1) {
		cout << endl << "Invalid input ! | Work not found ! | Please choose from 1 - " << n << endl << endl;
		showMenu();
	}
	// else
	cout << "--------- | " << endl;
	cout << "--------- | " << works_list[picked_work - 1] << " | ---------" << endl; // Print picked work
	cout << "--------- | " << endl;

	navigator(picked_work);

};
//
//
//
void navigator(int picked_work) {
	ProductController pc;
	char do_continue;
	// Proceed user's option
	switch (picked_work)
	{
	case 1:
		pc.createProduct();
		break;
	case 2:
		pc.showProducts();
		break;
	case 3:
		pc.showCategories();
		break;
	case 4:
		pc.find();
		break;
	case 5:
		pc.destroy();
		break;
	case 6:
		pc.destroy100();
		break;
	}

	// Choose whether continue the program or not
	cout << "Do you want to continue the program ? (y/n)" << endl;
	cin >> do_continue;
	if (do_continue == 'y' || do_continue == 'Y') {
		cout << "--------- | " << endl;
		cout << "--------- | " << "Nice !" << endl;
		cout << "--------- | " << endl;
		help_menu.clearScreen();
		showMenu();
	}

}

int main() {
	showMenu();
	return 0;
}