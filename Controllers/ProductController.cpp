#include <iostream>
#include "Headers\ProductController.h"
#include "../Models/Headers/Product.h"
using namespace std;

ProductController::ProductController() {
    // Contrustor function
};
void ProductController::createProduct() {
    Product pc;
    cout << "Creating Product" << endl;
    pc.create();
}
void ProductController::showProducts() {
    Product pc;
    cout << "Show products" << endl;
    pc.read();
}

void ProductController::showCategories() {
    cout << "Show products's list" << endl;
}

void ProductController::find() {
    cout << "This is the thing" << endl;
}

void ProductController::destroy() {
    Product pc;
    cout << "Delete" << endl;
    pc.destroy();
}

void ProductController::destroy100() {
    Product pc;
    cout << "Delete 3000" << endl;
    pc.destroy100();
}