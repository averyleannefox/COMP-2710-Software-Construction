/* COMP 2710 project3FinalCode.cpp
* Avery Fox alf00752auburn.edu
* I refered to the skeleton pseudocode structure Dr. Li explained in class lecutre on 10/11/23.
* I referenced @https://stackoverflow.com/ many times while debugging / verifying correct syntax for c++.
* FINAL!
*/


#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib> //for exit()

using namespace std;

    // declaring varibles / functions

    ifstream inStream, inStream2;
    
    vector<int> merge(vector<int>, vector<int>);

    // **debug instance one

    vector<int> read_files(string);

    bool checkToSeeGood(string);

    void write_file(string, vector<int>);

    void toString(vector<int>);


    

int main() {

    // declaring local varibles 

    vector<int> fileContent1, fileContent2, fileContent3;
    string fileName1, fileName2, fileName3;

    //user interface

    cout << endl << "*** Welcome to Avery's sorting program ***\n";

    // file 1

    do {
		cout << "Enter the first file name: ";
		cin >> fileName1;
	} while (cin.fail() || !checkToSeeGood(fileName1));


// **this is where the error is located
      fileContent1 = read_files(fileName1);
      cout << "The list of " << fileContent1.size() 
                << " numbers in the file " + fileName1 + " is:\n";
      toString(fileContent1);

    // file 2
    
    do {
		cout << "Enter the second file name: ";
		cin >> fileName2;
	} while (cin.fail() || !checkToSeeGood(fileName2));

    fileContent2 = read_files(fileName2);
      cout << "The list of " << fileContent2.size() 
                << " numbers in the file " + fileName2 + " is:\n";
      toString(fileContent2);


    fileContent3 = merge(fileContent1, fileContent2);

    cout << "The sorted list of " << fileContent3.size() << " numbers is: ";
    for (unsigned int i = 0; i < fileContent3.size(); i++) {
        cout << fileContent3.at(i) << " ";
    }
    cout << endl;

    do {
        cout << "Enter the output file name: ";
        cin >> fileName3;

    } while (cin.fail());

    write_file(fileName3, fileContent3);

    cout << "*** Please check the new file - " + fileName3 + " ***" << endl
		 << "*** Goodbye. ***";

         return 0;


}

    // toString function

    void toString(vector<int> v) {
        for (unsigned int i = 0; i < v.size(); i++) {
            cout << v.at(i) << endl;
        }

        cout << endl;
   
    }

    // checkToSeeGood function

    bool checkToSeeGood(string file) {
        ifstream stream;

        stream.open(file.c_str());
        if (stream.fail()) {
            stream.close();
            return false;
        }
        stream.close();

        return true;
    }

    // read_file function

    vector<int> read_files(string file) {

        ifstream stream;
        vector<int> v;
        int i;

        stream.open(file.c_str());
        while (stream >> i) {
            v.insert(v.end(), i);
        }
        stream.close();

        return v;
    }

    // write_file function

    void write_file(string file3, vector<int> vector3) {
        ofstream stream;
        

        stream.open(file3.c_str());
        for (unsigned int i = 0; i < vector3.size();  i++) {
            stream << vector3.at(i) << endl;
        }
        stream.close();
    }

    // merge function

    vector<int> merge(vector<int> vector1, vector<int> vector2) {
        vector<int> vector3;
        int i = 0;

        while (vector1.size() > 0 && vector2.size() > 0) {
            if (vector1.at(0) < vector2.at(0)) {
                vector3.push_back(vector1.at(0));
                vector1.erase(vector1.begin());
            } 
            else {  
                vector2.at(0);
            }

        if (vector1.size() > 0) {
            for (i = 0; i <= vector1.size(); i++) {
                vector3.push_back(vector1.at(0));
                vector1.erase(vector1.begin());
            }
        }

        if (vector2.size() > 0) {
            for (i = 0; i <= vector2.size(); i++) {
                vector3.push_back(vector2.at(0));
                vector2.erase(vector2.begin());
            }
        }

       }


       return vector3;
    }

    
    

    





