#include "Helpers.h"
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
char Helpers::char_lowerCase(char input) {
	if (input >= 'A' && input <= 'Z') return input + 32;
	return input;
}
string Helpers::string_lowerCase(string input) {
	for (int i = 0; i < input.size(); i++) {
		input[i] = this->char_lowerCase(input[i]);
	}
	return input;
}