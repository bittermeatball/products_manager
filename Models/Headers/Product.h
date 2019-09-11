#include <string>
using namespace std; // string lives in the std class

#ifndef PRODUCT_H
    #define PRODUCT_H

    class Product {
        public :
            // Constructor
            Product();
            void create();
            //
        private :
            int last_index;
            string fillable[8] = {
                "id",
                "name",
                "unit",
                "created_at",
                "manufacter",
                "quantity",
                "price_per_unit",
                "total"
            };
    };

#endif