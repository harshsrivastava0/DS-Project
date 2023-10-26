#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> marks = {
        {80, 90, 75, 85, 70},
        {70, 85, 92, 78, 88},
        {60, 75, 80, 70, 68},
        {92, 88, 95, 90, 78}
    };

    int numStudents = marks.size();
    int numSubjects = marks[0].size();

    vector<int> studentTotals(numStudents, 0);
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            studentTotals[i] += marks[i][j];
        }
    }

    vector<double> subjectAverages(numSubjects, 0.0);
    for (int j = 0; j < numSubjects; j++) {
        for (int i = 0; i < numStudents; i++) {
            subjectAverages[j] += marks[i][j];
        }
        subjectAverages[j] /= numStudents;
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "Total marks of Student " << i + 1 << ": " << studentTotals[i] << endl;
    }

    for (int j = 0; j < numSubjects; j++) {
        cout << "Average marks in Subject " << j + 1 << ": " << subjectAverages[j] << endl;
    }

    return 0;
}
