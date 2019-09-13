#include <iostream>
#include <string>
#include "Headers/ProductController.h"
#include "../Models/Product.cpp"

using namespace std;

ProductController::ProductController() {
    // Contrustor function
};

void ProductController::showProducts() {
    Product p;
    cout << endl << "Here are the products available : " << endl;
    p.all();
}

void ProductController::createProduct() {
    Product p;
    p.create();
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