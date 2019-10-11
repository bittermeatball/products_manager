#include <iostream>
#include "ProductController.h"
#include "Product.h"

using namespace std;

ProductController::ProductController() {
	// Contrustor function
};
void ProductController::createProduct() {
	Product pc;
	pc.create();
}
void ProductController::showProducts() {
	Product pc;
	pc.read();
}

void ProductController::showCategories() {

}

void ProductController::find() {
	Product pc;
	pc.find();
}

void ProductController::destroy() {
	Product pc;
	pc.destroy();
}

void ProductController::destroy100() {
	Product pc;
	pc.destroy100();
}