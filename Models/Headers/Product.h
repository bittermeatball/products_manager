#include <iostream>
#include <string>
using namespace std; // string lives in the std class
#include "../../Controllers/Helpers.cpp"
#ifndef PRODUCT_H
    #define PRODUCT_H

    class Product : public Helpers{
        public :
            // Constructor
            Product();
            // template
            // Model's methods
            void all();
            void create();
            void destroy();
            void find();
            //
        private :
            // int last_index;

            // int id;
            string name;
            string type;
            string created_at;
            string manufacter;
            int quantity;
            int price_per_unit;
            string unit;
            int total;
            
            // string fillable[8] = {
            //     "id",
            //     "name",
            //     "unit",
            //     "created_at",
            //     "manufacter",
            //     "quantity",
            //     "price_per_unit",
            //     "total"
            // };
    };

#endif