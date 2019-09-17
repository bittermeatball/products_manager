#include <string>
#include <windows.h>
#ifndef HELPERS_H
    #define HELPERS_H
    class Helpers {
        public:
            // Constructor
            Helpers();
            //
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
            //
            void clearScreen();
            string now();
            string str_replace(string input,string pre, string pos);
            void set_color(int color_code);
    };
#endif