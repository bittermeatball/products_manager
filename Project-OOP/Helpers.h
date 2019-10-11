#ifndef HELPERS_H
#define HELPERS_H
#include <string>	
class Helpers {
public:
	// Constructor
	Helpers();
	//
	void clearScreen();
	std::string now();
	std::string str_replace(std::string input, std::string pre, std::string pos);
	int str_find(std::string str, std::string x);
	int findProductQuantity(std::string input);
};
#endif