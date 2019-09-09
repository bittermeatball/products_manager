#include <iostream>
#include <string>
#include "Headers\ProductController.h"

using namespace std;

ProductController::ProductController() {
    // Contrustor function
};

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