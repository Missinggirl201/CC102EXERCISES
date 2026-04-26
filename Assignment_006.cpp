#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimesInFile(string filename) {
    ifstream file(filename);
    int count = 0;
    int num;
    while (file >> num) {
        if (isPrime(num)) count++;
    }
    file.close();
    return count;
}

int main() {
    string filename = "NUMS.TXT";
    int primeCount = countPrimesInFile(filename);
    cout << "Number of prime numbers: " << primeCount << endl;
    return 0;
}