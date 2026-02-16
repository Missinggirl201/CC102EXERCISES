#include <iostream>
using namespace std;

int main() {
    int m = 12;
    double sales[m];
    double t = 0, ave;
    int hm = 0, lm = 0;

    cout << "Enter the sales for 12 months: " << endl;

    for (int i = 0; i < m; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> sales[i];
        t += sales[i];

        if (sales[i] > sales[hm]) {
            hm = i;
        }

        if (sales[i] < sales[lm]) {
            lm = i;
        }
    }

    ave = t / m;

    
    cout << "-------------------------------------\n";
    cout << "Total Sales: " << t << endl;
    cout << "-------------------------------------\n";
    cout << "Average Monthly Sales: " << ave << endl;
    cout << "-------------------------------------\n";
    cout << "Highest Sales: Month " << hm + 1 
         << " (" << sales[hm] << ")" << endl;
    cout << "-------------------------------------\n";
    cout << "Lowest Sales: Month " << lm + 1
         << " (" << sales[lm] << ")" << endl;
         
    cout << "=====================================\n";

    return 0;
}