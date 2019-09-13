#include <iostream>
#include <string>
#include "Headers/Helpers.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

Helpers::Helpers() {
    //
}

void Helpers::clearScreen() {
    // Clear the ugly screen !
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

string Helpers::now() {
    // Get the time
    time_t _tm =time(NULL );
    struct tm * curtime = localtime ( &_tm );
    string now = asctime(curtime);
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

string str_replace(string str,string pre,string pos) {
    // Replace space with underscore
    int length = str.size();
    int x = 0;
    string fixed;
    while (x != length) {
        string letter = str.substr(x, 1);
        if (letter == pre) {
        letter = pos;}
        fixed = fixed + letter;
        x = x + 1;
    }
    return fixed;
}