#include <iostream>
#include <string>
#include "Headers\ProductController.h"

using namespace std;

ProductController::ProductController() {
    // Contrustor function
};

void ProductController::showProducts() {
    cout << "Show products";
}

void ProductController::showCategories() {
    cout << "Show products's list";
}

void ProductController::find() {
    cout << "This is the thing";
}

void ProductController::destroy() {
    cout << "Delete";
}

void ProductController::destroy100() {
    cout << "Delete 3000";
}