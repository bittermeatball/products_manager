#include <string>
#ifndef HELPERS_H
    #define HELPERS_H
    class Helpers {
        public:
            // Constructor
            Helpers();
            //
            void clearScreen();
            string now();
            string str_replace(string input,string pre, string pos);
            int findPosition(string str, string x);
            int findProductQuantity(string input);
    };
#endif