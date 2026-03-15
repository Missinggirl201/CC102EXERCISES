#include <iostream>
#include <vector>
using namespace std;

void ag(const vector<vector<int>>& grades)
{
    int st = grades.size();
    int sb = grades[0].size();
    int h = grades[0][0];
    vector<double> averages(st, 0.0); // Changed to double

    for(int i = 0; i < st; i++){
        int sum = 0;
        for(int j = 0; j < sb; j++){
            sum += grades[i][j];
            if(grades[i][j] > h) h = grades[i][j];
        }
        averages[i] = sum / (1.0 * sb); // 1.0 is double by default anyway
    }

    int dashCount = 12 + (sb * 5);
    for(int k = 0; k < dashCount; k++) cout << "-";
    cout << "\nStudent    ";
    for(int j = 0; j < sb; j++){
        cout << "S" << j+1 << "   ";
    }
    cout << "Avg\n";
    for(int k = 0; k < dashCount; k++) cout << "-";
    cout << "\n";

    for(int i = 0; i < st; i++){
        cout << i+1 << "          ";
        if(i+1 >= 10) cout << " ";

        for(int j = 0; j < sb; j++){
            int grade_val = grades[i][j];
            cout << grade_val;
            if(grade_val < 10) cout << "    ";
            else cout << "   ";
        }

        int whole = averages[i];
        int decimal = (averages[i] - whole) * 100;
        cout << whole << ".";
        if(decimal < 10) cout << "0";
        cout << decimal << "\n";
    }

    for(int k = 0; k < dashCount; k++) cout << "-";
    cout << "\n";
    for(int k = 0; k < 12 + (sb * 5) - 15; k++) cout<<"" ;
    cout << "Highest grade: " << h << "\n";
    for(int k = 0; k < dashCount; k++) cout << "-";
    cout << "\n";
}

int main()
{
    int st, sb;

    cout << "Enter students: ";
    cin >> st;
    cout << "Enter subjects: ";
    cin >> sb;

    vector<vector<int>> grades(st, vector<int>(sb));

    int inputDash = 22;
    for(int k = 0; k < inputDash; k++) cout << "-";
    cout << "\n     ENTER GRADES     \n";
    for(int k = 0; k < inputDash; k++) cout << "-";
    cout << "\n";
    for(int i = 0; i < st; i++){
        cout << "Student " << i+1 << ":\n";
        for(int j = 0; j < sb; j++){
            cout << " S" << j+1 << ": ";
            cin >> grades[i][j];
        }
    }

    ag(grades);

    return 0;
}
