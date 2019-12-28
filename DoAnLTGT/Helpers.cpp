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