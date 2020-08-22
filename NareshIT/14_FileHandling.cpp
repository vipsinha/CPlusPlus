// Date: 2020-04-19
// File handling

#include<iostream>
#include<fstream>
using namespace std;

// ifstream- read the data from file
// ofstream- output the file into the file
// fstream- combination of ifstream and ofstream
// file can be opnened using parameterised constructor and open 

class classA
{
    private:
        int dataA;
        string lineA;
    public:
        void getDataA();
        void showDataA();      
};

void classA::getDataA()
{
    cout << "Get the data\n";
    cin >> dataA;
    cin >> lineA;
}

void classA::showDataA()
{
    cout << "Entered data is: " << dataA << lineA << endl;
}

int main(void)
{
    char choice;
    classA ObjA;
    string line;

    // Open the file using the parameterised constructor
    fstream file;
    file.open("14_FileIO.txt", ios::trunc | ios::in | ios::out);

    // using the member function to open a file
    // ios::out is optional
    // ifstream file_2("14_File_2.txt",ios::in);

    do
    {
        /* code */
        //ObjA.getDataA();
        cout << "Enter the string\n";
        cin >> line;
        //file.write((char *)&ObjA, sizeof(ObjA));
        //file << (char *)&ObjA << endl;
        file << line << endl;

        cout << "Data is entered\n" << "Want to enter more data press 'Y' or 'y'\n";
        cin >> choice; 
    } while (choice == 'Y' || choice == 'y');
    
    file.seekg(0,ios_base::beg);
    while(file)
    {
        //file.read((char *)&ObjA,sizeof(ObjA));
        //file.read((char *)&line,sizeof(line));
        file >> line;
        cout << "Data is:" << line << endl;
        //ObjA.showDataA();
    }

    file.close();
    //file_2.close();

    return(0);
}