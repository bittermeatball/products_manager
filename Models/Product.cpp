#include <iostream>
#include <fstream>
#include <string>
#include "Headers\Product.h"

using namespace std;

Product::Product() {
    //
}

void Product::all() {
    
    string line;
    ifstream data ;
    data.open("Database/data.txt", ios::in);

    if (data.is_open()) {
        while ( getline(data,line) )
        {
            cout << line << "\n";
        };
        data.close();
    } else {
        cout << "Unable to open file !" << endl;
    };

}

void Product::destroy() {

}

void Product::find() {

}

void Product::create() {

    Product p; // Assign class to object p 
     
    ofstream data; // Assign ofstream class to object data
    //
    // Variables
    string product;
    string type;
    string unit;
    string created_at;
    string manufacter;
    int quantity;
    int price_per_unit;
    int total;
    //
    
    cout << "Enter product's name : " << endl;
    cin.ignore();
    getline(cin,product);
    product = p.str_replace(product," ","_");
    //
    cout << "Enter product's type : " << endl;
    cin >> type;
    cout << "Enter product's manufacter : " << endl;
    cin >> manufacter;
    cout << "Enter charge unit : " << endl;
    cin >> unit;    
    cout << "Enter product's quantity : " << endl;
    cin >> quantity;
    cout << "Enter product's price per unit : " << endl;
    cin >> price_per_unit;

    created_at = p.now(); // Helpers's function
    total = price_per_unit*quantity;

    //
    // Work with file
    data.open("Database/data.txt",ios::app); // Add mode, not replace mode (ios::out)
 
    data << product << " " << type << " " << manufacter << " " << quantity << " " << price_per_unit << " " << unit << " " << total << " " << created_at << "\n";
 
    data.close();   // close the file

    cout<<"\nFile saved and closed succesfully."<<endl;

}