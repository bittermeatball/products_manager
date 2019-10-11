#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Helpers.h"

using namespace std;
Helpers::Helpers() {
	// Constructor
}
void Helpers::clearScreen()
{
	// Clear the ugly screen !
	// int n;
	// for (n = 0; n < 10; n++)
	//     cout << endl << endl << endl << endl;
	if (system("CLS")) system("clear");
}

string toString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

string Helpers::now() {
	// Get the time
	//time_t rawtime;
	//struct tm* timeinfo;
	//time(&rawtime);
	//timeinfo = localtime(&rawtime);
	//string now = asctime(timeinfo);

	time_t result = time(NULL);

	char str[26]; // Date length
	char t = ctime_s(str, sizeof str, &result);

	string now = toString(&t,26);

	// Replace space with underscore
	int length = now.size();
	int x = 0;
	string fixed;
	while (x != length) {
		string letter = now.substr(x, 1);
		if (letter == " ") {
			letter = "_";
		}
		fixed = fixed + letter;
		x = x + 1;
	}
	return fixed;
}

string Helpers::str_replace(string input, string pre, string pos) {
	int length = input.size();
	int x = 0;
	string fixed;
	while (x != length) {
		string letter = input.substr(x, 1);
		if (letter == pre) {
			letter = pos;
		}
		fixed = fixed + letter;
		x++;
	}
	return fixed;
}
// Similar to find()
int Helpers::str_find(string str, string x) {
	int i, j, k, pos;
	int sizeSTR = str.size();
	int sizeX = x.size();
	// If you enter only one word
	if (x.size() == 1) {
		for (i = 0; i < sizeSTR; i++) {
			if (str[i] == x[0]) {
				return i;
			}
		}
	}
	// If you enter more than one word
	for (i = 0; i < sizeSTR; i++) {
		j = 0;
		// First word match
		if (str[i] == x[j]) {
			// Save the position of that word
			pos = i;
			// Loops through the word that needs searching
			for (k = 0; k < sizeX; k++) {
				// If every letter is the same increase i
				if (str[i] == x[k]) {
					i++;
				}
				// 
				if (i - pos == sizeX) {
					return pos;
				}
			}
		}
	}
	return 0;
}
int Helpers::findProductQuantity(string input) {
	int firstSpace = this->str_find(input, " ");
	string removefirst = input.erase(0, firstSpace + 1);
	int quantity = stoi(input.substr(0, input.find(" ")));
	return quantity;
}