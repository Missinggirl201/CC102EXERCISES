#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("color.txt");

    
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    outFile << "Red\n";
    outFile << "Blue\n";
    outFile << "Green\n";
    outFile << "Yellow\n";
    outFile << "Purple\n";

    outFile.close();

    ifstream inFile("color.txt");
    ofstream copyFile("color_copy.txt");

    if (!inFile || !copyFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "File copied successfully!" << endl;

    return 0;
}