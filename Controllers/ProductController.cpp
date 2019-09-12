#include <iostream>
#include <fstream>
#include <string>
#include "Headers\ProductController.h"

using namespace std;

ProductController::ProductController() {
    // Contrustor function
};
void ProductController::createProduct() {
    cout << "Creating Product" << endl;
    string name ,manufacter;
    int quantity, price_per_unit;
    int total;

    // open a file in append mode.
    ofstream file;
    file.open("db.dat", ios::app);

    cout << "Enter your supply name: "; 
    getline(cin, name);

    cout << "Enter the quantity of your supply:  "; 
    cin >> quantity;
    cin.ignore();

    cout << "Enter the price per unit of your supply:  "; 
    cin >> price_per_unit;
    cin.ignore();

    total = quantity*price_per_unit;
    cout << "Enter the supply's manufacter: "; 
    getline(cin, manufacter);


    // write inputted data into the file.
    file << name << "    " << quantity << "    " << manufacter << "    " << total << endl;
}
void ProductController::showProducts() {
    cout << "Show products" << endl;
}

void ProductController::showCategories() {
    cout << "Show products's list" << endl;
}

void ProductController::find() {
    cout << "This is the thing" << endl;
}

void ProductController::destroy() {
    cout << "Delete" << endl;
}

void ProductController::destroy100() {
    cout << "Delete 3000" << endl;
}