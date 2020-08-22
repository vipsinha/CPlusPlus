// Date - 2020-03-30
#include <iostream>
using namespace std;

class StudentInfo
{
private:
    /* data members */
    int id;
    char name[20];
    int marks;
public:
    /* Member functions */
    void getStudentName();
    void printStudentInfo();
};

void StudentInfo::getStudentName()
{
    cout << "Enter student name and id\n";
    cin >> name >> id;
}

void StudentInfo::printStudentInfo()
{
    cout << "Student name is " << name << "\n";
    cout << "Student id is " << id << "\n";

}

int main()
{
    StudentInfo Student1;

    Student1.getStudentName();
    Student1.printStudentInfo();
    return 0;
}