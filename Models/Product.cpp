#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "Headers\Product.h"

using namespace std;

Product::Product() {

}
void Product::create() {
    string name ,manufacter;
    int quantity, price_per_unit;
    int total;

    // open a file in append mode.
    ofstream file;

    file.open("./Database/db.dat", ios::app);
    if (file.is_open())
        {
            cout << "Enter your product name: "; 
            getline(cin, name);

            cout << "Enter the quantity of your product:  "; 
            cin >> quantity;
            cin.ignore();

            cout << "Enter the price per unit of your product:  "; 
            cin >> price_per_unit;
            cin.ignore();

            total = quantity*price_per_unit;
            cout << "Enter the product's manufacter: "; 
            getline(cin, manufacter);

            // write inputted data into the file.
            file << name << " " << quantity << " " << manufacter << " " << total << endl;
            cout << "Writing to File";
        }
        else cout << "Unable to open file";
    file.close();
}

void Product::read() {
    string data;
    int i=1;
    ifstream file;
    file.open("./Database/db.dat");

    if (file.is_open())
        {
            while ( getline (file,data) )
                {
                    cout << "Supply number : " << i << '\n';
                    cout << data << '\n';
                    i++;
                }
        }
        else cout << "Unable to open file";

    file.close();
}

void Product::destroy() {
    string deleteData, newData;

    cout << "Please type in the name of your product that you want to delete: " << "\n";
    getline(cin,deleteData);

    ofstream newFile;
    ifstream file;

    newFile.open("./Database/newdb.dat");
    file.open("./Database/db.dat");

        if (file.is_open())
        {   
            // Read each line in the database
            while ( getline (file,newData) )
                {
                    // Take the first word in one line ( Product Name ) and compare it with the word you want to delete
                    if(newData.substr(0, newData.find(' ')) != deleteData) {
                        // Write the whole line into new File if the first product is not the product which is supposed to be deleted
                        newFile << newData << endl;
                    }
                    else {
                        cout << "Deleted all product with that name";
                    }
                }
        }
        else cout << "Unable to open file";

    file.close();
    newFile.close();
    remove("./Database/db.dat");
    rename("./Database/newdb.dat", "./Database/db.dat");
}
// Dunt worry , imma move this to Helper soon
int findProductQuantity(string a) {
    int firstSpace = a.find(' ');
    string removefirst = a.erase(0, firstSpace+1);
    int quantity = stoi(a.substr(0, a.find(' ')));
    cout << quantity;
    return quantity;
}
void Product::destroy100() {
    string newData;
    ofstream newFile;
    ifstream file;

    newFile.open("./Database/newdb.dat");
    file.open("./Database/db.dat");

        if (file.is_open())
        {   
            // Read each line in the database
            while ( getline (file,newData) )
                {
                    if(findProductQuantity(newData) < 100) {
                        newFile << newData << endl;
                    }
                }
        }
        else cout << "Unable to open file";

    file.close();
    newFile.close();
    remove("./Database/db.dat");
    rename("./Database/newdb.dat", "./Database/db.dat");
}