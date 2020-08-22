// Date - 2020-03-31
#include <iostream>
using namespace std;

class One_D_Array
{
private:
    /* data members */
    int size;
public:
    /* Member functions */
    int getArraySize();
    void getArrayData(int *ArrPointer, int size);
    void printArray(int *ArrPointer, int size);
};


class Two_D_Array
{
private:
    /* data members */
    int rowSize;
    int colSize;
public:
    /* Member functions */
    int getArraySize();
    void getArrayData(int **ArrPointer);
    void printArray(int **ArrPointer);
};


int One_D_Array::getArraySize()
{
    cout << "Enter the array size\n";
    cin >> size;

    return (size);
}

void One_D_Array::getArrayData(int *ArrPointer, int size)
{
    cout << "Enter the array values\n";
    for(int Index=0; Index<size; Index++)
    {
        cin >> ArrPointer[Index];
    }
}

void One_D_Array::printArray(int *ArrPointer, int size)
{
    cout << "Array elements are\n";
    for(int Index=0; Index<size; Index++)
    {
        cout << ArrPointer[Index] << "\t";
    }
    cout << endl;
}


int Two_D_Array::getArraySize()
{
    cout << "Enter the array Row size\n";
    cin >> rowSize;

    cout << "Enter the array Column size\n";
    cin >> colSize;
    
    return(rowSize);
}

void Two_D_Array::getArrayData(int **ArrPointer)
{
    cout << "Enter the array values\n";
    for(int rowIndex=0; rowIndex<rowSize; rowIndex++)
    {
        ArrPointer[rowIndex] = new int[colSize];

        for(int colIndex=0; colIndex<colSize; colIndex++)
        {
            cin >> ArrPointer[rowIndex][colIndex];
        }
    }
}

void Two_D_Array::printArray(int **ArrPointer)
{
    cout << "Array elements are\n";
    for(int rowIndex=0; rowIndex<rowSize; rowIndex++)
    {
        for(int colIndex=0; colIndex<colSize; colIndex++)
        {
            cout << ArrPointer[rowIndex][colIndex] << "\t";
        }
        cout << endl;
    }

}

int main()
{
    // One dimentional array
    cout << "## 1-D Array ##\n";
    One_D_Array Array_1_D;
    int arraySize;
    int *p;

    arraySize = Array_1_D.getArraySize();
    p = new int[arraySize];

    Array_1_D.getArrayData(p, arraySize);
    Array_1_D.printArray(p, arraySize);

    delete p;

    // Two Dimensional array
    cout << "## 2-D Array ##\n";
    Two_D_Array Array_2_D;
    int Array_2_D_rowSize;
    int **Array_2_D_p;

    Array_2_D_rowSize = Array_2_D.getArraySize();
    Array_2_D_p = new int*[Array_2_D_rowSize];

    Array_2_D.getArrayData(Array_2_D_p);
    Array_2_D.printArray(Array_2_D_p);

    delete Array_2_D_p;

    return 0;
}