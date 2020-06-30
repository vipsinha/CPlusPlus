// Structs
/* Aut: Vipul Sinha, Date: 2020-02-20 */

#include "iostream"

using namespace std;

typedef struct
{
    string studentName;
    float GPA;
}studentData;

int main()
{
    studentData student[3];

    cout << "Enter the student name : ";
    cin >> student[0].studentName;

    cout << "Enter the " << student[0].studentName <<" GPA : ";
    cin >> student[0].GPA;

    cout << student[0].studentName << " got " << student[0].GPA << " grades\n";

    return 0;
}
