#include <iostream>
#include <string>
#include <time.h>
#include "Headers/Helpers.h"

using namespace std;

Helpers::Helpers() {
    // Constructor
}
void Helpers::clearScreen()
{
    // Clear the ugly screen !
    int n;
    for (n = 0; n < 10; n++)
        cout << endl << endl << endl << endl;
}
string Helpers::now() {
    // Get the time
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    string now = asctime(timeinfo);
    // Replace space with underscore
    int length = now.size();
    int x = 0;
    string fixed;
    while (x != length) {
        string letter = now.substr(x, 1);
        if (letter == " ") {
        letter = "_";}
        fixed = fixed + letter;
        x = x + 1;
    }
    return fixed;
}

string Helpers::str_replace(string input,string pre,string pos) {
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
int Helpers::findPosition(string str, string x) {
    int i,j,k,pos;
    // If you enter only one word
    if(x.size() == 1) {
        cout << str << endl;
        for(i=0 ; i<str.size();i++) {
            if(str[i] == x[0]) {
                cout << "FUNCTION FOUND ONE WORD AT " << i << endl;
                return i;
            }
        }
    }
    // If you enter more than one word
        for(i=0; i<str.size();i++) {
            j=0;
            // First word match
            if(str[i] == x[j]) {
                // Save the position of that word
                pos = i;
                // Loops through the word that needs searching
                for(k=0;k<x.size();k++) {
                    // If every letter is the same increase i
                    if(str[i] == x[k]) {
                        i++;
                    }
                    // 
                    if(i-pos == x.size()) {
                        return pos;
                    }
                }
            }
        }
    return 0;
}
int Helpers::findProductQuantity(string input) {
    int firstSpace = this->findPosition(input, " ");
    string removefirst = input.erase(0, firstSpace+1);
    int quantity = stoi(input.substr(0, input.find(' ')));
    return quantity;
}