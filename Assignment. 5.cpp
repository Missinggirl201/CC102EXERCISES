#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream outFile("original.txt");

    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    outFile << "One\nTwo\nThree\nFour\nFive\nSix\n";
    outFile.close();

    ifstream inFile("original.txt");

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string words[6];
    int i = 0;

    while (getline(inFile, words[i])) {
        i++;
    }

    inFile.close();

    sort(words, words + 6);

    ofstream sortedFile("sorted.txt");

    if (!sortedFile) {
        cout << "Error creating sorted file!" << endl;
        return 1;
    }

    for (int j = 0; j < 6; j++) {
        sortedFile << words[j] << endl;
    }

    sortedFile.close();

    cout << "Sorting completed!" << endl;

    return 0;
}