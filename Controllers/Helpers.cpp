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

int Helpers::findProductQuantity(string input) {
    int firstSpace = input.find(' ');
    string removefirst = input.erase(0, firstSpace+1);
    int quantity = stoi(input.substr(0, input.find(' ')));
    cout << quantity;
    return quantity;
}