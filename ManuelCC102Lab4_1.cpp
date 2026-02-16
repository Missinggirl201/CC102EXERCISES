#include <iostream>
using namespace std;

int main() {
    int students ,quiz ;
    double s, t, ave;
    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of quizzes: ";
    cin >> quiz;


    for (int i = 1; i <= students; i++) {
        t = 0;
        cout << "Student " << i << endl;

        for (int j = 1; j <= quiz; j++) {
            cout << "Enter score for Quiz " << j << ": ";
            cin >> s;
            t+= s;
        }

        ave= t / quiz;

        cout << "Average score of Student " << i << " is: " << ave<< endl;
    }

    return 0;
}