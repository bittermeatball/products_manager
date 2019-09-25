#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "Headers\Product.h"

using namespace std;

Helpers help_product;

Product::Product() {
    // Constructor
}
void Product::create() {
    string name ,manufacter, created_at, type;
    int quantity, price_per_unit;
    int total;

    // open a file in append mode.
    ofstream file;

    file.open("Database/db.dat", ios::app);
    if (file.is_open())
        {
            cout << "Enter your product name: "; 
            getline(cin, name);
            name = help_product.str_replace(name, " ", "_");
            //
            cout << "Enter the quantity of your product:  "; 
            cin >> quantity;
            cin.ignore();
            //
            cout << "Enter the price per unit of your product:  "; 
            cin >> price_per_unit;
            cin.ignore();
            //
            cout << "Enter product's type : ";
            getline(cin,type);
            type = help_product.str_replace(type," ","_");
            //
            total = quantity*price_per_unit;
            cout << "Enter the product's manufacter: "; 
            getline(cin, manufacter);
            manufacter = help_product.str_replace(manufacter, " ", "_");
            //
            created_at = help_product.now(); // Helpers's function

            // write inputted data into the file.
            file << name << " " << quantity << " " << type << " " <<manufacter << " " << price_per_unit << " " << total << " " << created_at << endl;
            cout << "Writing to File" << endl;
        }
        else cout << "Unable to open file";
    file.close();
}

void Product::read() {
    string data;
    int i=1;
    //
    ifstream file;
    file.open("Database/db.dat");
    //
    if (file.is_open()){
            while ( getline (file,data) ){
                cout << "Supply number " << i << endl;
                data=help_product.str_replace(data,"_"," ");
                cout << data << endl << endl;
                i++;
            }
        }
        else cout << "Unable to open file";
    //
    file.close();
}

void Product::destroy() {
    string deleteData, newData;
    int match=0;
    //
    cout << "Please type in the name of your product that you want to delete: " << "\n";
    getline(cin,deleteData);
    deleteData = help_product.str_replace(deleteData, " ", "_");
    //
    ofstream newFile;
    ifstream file;
    //
    newFile.open("Database/newdb.dat");
    file.open("Database/db.dat");

        if (file.is_open()){   
            // Read each line in the database
            while ( getline (file,newData) ) {
                    // Take the first word in one line ( Product Name ) and compare it with the word you want to delete
                    if(newData.substr(0, help_product.str_find(newData," ")) == deleteData) {
                        match++;
                    }
                    else {
                        // Write the into new File if the first product is not the product which is supposed to be deleted
                        newFile << newData << endl;
                    }
                }
            if(match == 0) {
                cout << "Sorry, but we did not find any products with that name" << endl;
            }
            else {
                cout << "Deleted Successfully!" << endl;
            }
        }
        else cout << "Unable to open file";
    //
    file.close();
    newFile.close();
    //
    remove("Database/db.dat");
    rename("Database/newdb.dat", "Database/db.dat");
}

void Product::destroy100() {
    string newData;
    int match=0;
    //
    ofstream newFile;
    ifstream file;
    //
    newFile.open("Database/newdb.dat");
    file.open("Database/db.dat");

        if (file.is_open()){   
            // Read each line in the database
            while ( getline (file,newData) ) {
                    if(help_product.findProductQuantity(newData) < 100) {
                        newFile << newData << endl;
                    }
                    else match++;
                }
            if(match == 0) cout << "I'm sorry but we do not find any products with the quantities that are larger than 100" << endl;
        }
        else cout << "Unable to open file";

    file.close();
    newFile.close();
    remove("Database/db.dat");
    rename("Database/newdb.dat", "Database/db.dat");
}

void Product::find() {
    string findData, data;
    int match=0;
    //
    cout << "Please type in the name of your product that you want to find: " << "\n";
    getline(cin,findData);
    findData = help_product.str_replace(findData, " ", "_");
    cout << findData;
    //
    ifstream file;
    //
    file.open("Database/db.dat");

        if (file.is_open())
        {   
            // Read each line in the database
            while ( getline (file,data) ) {
                    // Take the first word in one line ( Product Name ) and compare it with the word you want to delete
                    if(data.substr(0, help_product.str_find(data," ")) == findData) {
                        cout << data << endl << endl;
                        match++;
                    }
                }
            if(match == 0) {
                cout << endl<< endl<< endl<< "Sorry, but we did not find any products with that name" << endl << endl << endl;
            }
            else {
                cout << "We found " << match << " product with that name" << endl << endl;
            }
        }
        else cout << "Unable to open file";
    //
    file.close();
    //
}