/* - Get and put the inputs 
   - Dynamic memory array allocation 
   - Refernece variable 
   - Polymorphism 
   - Class as an argument 
   - this pointer 
   - class as return type */
/* Aut: Vipul Sinha, Date: 2020-01-25 */

#include "iostream"
// - when iomanip is added the iostream is not required
// #include "iomanip.h"

using namespace std;

// - class is by default is private c++ structure
// - give struture prototype here or before semicolon end of class
// - Object is an instance of class
// - class is new derived operator as compared to c, as in C we have enum, union, struct
class student
{
    // Access specifier
    // Visilibilty label
    private:
        // Initialization is not allowed
        int studentID;
        char studentName[20];
        float marksObtained;
        // bool is new primitive class as compared to C
        bool status;
    public:
        // if function is defined here, then it is called inline function
        // else it is called with seperation operation
        void getData();
        // inline function
        void printData()
        {
            // - implicit coversion hence no %s or %d required for printing or scanning
            // - many times used >> or << called cascading
            cout << "Marks obtained by " << studentName << " is " << marksObtained << '\n';
        }
};

class dynamicMemory
{
    public:
        void dynamicAllocation();
        void one_D_Array();
        void two_D_Array();
};

class classFeatures
{
    private:


    public:
        
        // - should be initialized
        // - alias reference value
        int num = 10;
        int &refVar1 = num;
        int &refVar2 = refVar1;

        // - in case of pass by address swapByRefernce(*numA,*numB);
        void swapByRefernce(int &varA, int &varB);

        // - default argument is 1,2,3
        // - when number of arguments are not consistent when called from
        //   main function.
        // - if number of arguments are 2, then the default value will be
        //   taken as input value. Default argument will be defined only here
        // -  Also called function Polymorphism 
        int defaultArgumentSum(int varA=1, int varB=2, int varC=3);
        // - below are not allowed
        //int defaultArgumentSum(int varA=1, int varB=2, int varC);
        //int defaultArgumentSum(int varA, int varB=2, int varC);
        
};

class classArgument
{
    private:
        int thisA = 0;
        int thisB = 0;
        int prNum = 0;
    public:
        // Pass a class as an argument
        // this feature can be used to compare the number of 
        // two classes
        void passClassAsArgument(classArgument classVar);
        void setValue(void);

        // - This operator
        // - For every non static member
        void thisPointerUsage(int thisA, int thisB);

        // - Member function with class type return value
        // - return int, flaot any data type at same funciton
        // - t3 = t1.returnTypeAsClass(t2)
        // - t1 is implicit and t2 is explicit
        classArgument returnTypeAsClass(classArgument cFeatures);
        void getValue(void);
        void putValue();
};

void student :: getData(void)
{
    // - << and >> are operator overloaded
    // << is caled get in , defined in ostream class
    // >> is called from to , defined in istream class
    // endl is used for new line
    // ends is used for space
    // endl and ends are manipulator operators
    // setw(), setfill(), setprecision() and setioflags() arecalled manipulator functions
    // manipulators need to include iomanip.h
    // /n also called back slash character and occupies 1 byte memory
    cout << "Enter the student ID, name and marks" << endl;
    cin >> studentID >> studentName >> marksObtained;
}

void dynamicMemory :: dynamicAllocation(void)
{
    // pointer to dynamic memory
    // but these values(intPointer, floatPointer and charPointer) are stored in stack
    int *intPointer;
    float *floatPointer;
    char *charPointer;

    // - initialized with 10
    // - data allocated in heap area
    // - base address is stored in intPointer
    intPointer = new int(10);
    floatPointer = new float(1.5);
    charPointer = new char('X');

    delete intPointer;
    delete floatPointer;
    delete charPointer;

}

void dynamicMemory :: one_D_Array(void)
{
    int sizeArray = 0;
    int *pointerArray;

    cout << "Enter the size\n";
    cin >> sizeArray;

    pointerArray = new int[sizeArray];

    for(int index=0;index<sizeArray;index++)
    {
        cout << "Enter the " << index << " value\n";
        cin >> pointerArray[index];
    }

    cout << "Array values are\n";
    for(int prIndex=0;prIndex<sizeArray;prIndex++)
    {
        //cout << pointerArray[prIndex] << endl;
        cout << *(pointerArray + prIndex) << "\t";
    }
    cout << endl;

    // delete the memory allocated 
    delete pointerArray;
}

void dynamicMemory :: two_D_Array()
{
    int **arrayPointer;
    int totalRows = 0;
    int totalColumns = 0;

    cout << "Enter number of rows and colums\n";
    cin >> totalRows >> totalColumns;

    // - Memory allocation
    // - output and size type should be same
    // - size only need to be given, don't give array name after (new int --)
    // - remember this allocation
    // - type of SIZE (RET = new int SIZE) and RET should be same
    // - RET should be one * less
    // - here ** = new int *
    arrayPointer = new int *[totalRows];

    for(int rowsCount=0; rowsCount<totalColumns; rowsCount++)
    {
        // - type of SIZE (RET = new int SIZE) and RET should be same
        // - RET should be one * less
        // - here * = new int 
        arrayPointer[rowsCount] = new int [totalColumns];
    }

    // - Enter values in array
    for(int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < totalColumns; columnIndex++)
        {
            cout << "Enter " << (rowIndex+columnIndex+1) << " value ";
            cin >> arrayPointer[rowIndex][columnIndex];
        }    
    }
    
    // - Print values in array
    cout << "Array elements are\n";
    for(int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < totalColumns; columnIndex++)
        {
            cout << arrayPointer[rowIndex][columnIndex] << "\t";
        }    
        cout << endl;
    }

    delete arrayPointer;
}

// - in case of pass by address swapByRefernce(*numA,*numB);
void classFeatures :: swapByRefernce(int &varA, int &varB)
{
    int temp;

    // - no need of pointers as compared to pointer in pass by address
    temp = varA;
    varA = varB;
    varB = temp;
}

// - when number of arguments are not equal
int classFeatures :: defaultArgumentSum(int varA, int varB, int varC)
{
    return (varA+varB+varC);
}

void classArgument :: passClassAsArgument(classArgument classVar)
{
    if(classVar.prNum > prNum)
    {
        cout << "Argument class has big number\n";
    }
    else if(classVar.prNum < prNum)
    {
        cout << "This class has big number\n";
    }
    else
    {
        cout << "Both have same number\n";
    }
}

void classArgument :: setValue(void)
{
    cout << "Enter a number\n";
    cin >> prNum;
}

void classArgument :: thisPointerUsage(int thisA, int thisB)
{
    //this -> thisA = 10;
    //thisB = 20;
    this -> thisA = thisA;
    (*this).thisB = thisB;
    cout << "Object address = " << this << endl;
    cout << "var a value = " << this -> thisA << endl;
    cout << "var b value = " << this -> thisB << endl;
}

classArgument classArgument :: returnTypeAsClass(classArgument cFeatures)
{
    classArgument cFeatures_1;
    cFeatures_1.thisA = this->thisA + cFeatures.thisA;
    cFeatures_1.thisB = this->thisB + cFeatures.thisB;

    return(cFeatures_1);
} 

void classArgument :: getValue(void)
{
    cout << "Enter the value for variable 1\n";
    cin >> this->thisA;
    cout << "Enter the value for variable 2\n";
    cin >> this->thisB;
}

void classArgument :: putValue(void)
{
    cout << "Value for variable 1 = " << this->thisA << endl;
    cout << "Value for variable 2 = " << this->thisB << endl;
}

int main()
{
    // object creation
    // object is an instane of class
    // Memory is allocated only when object is created
    student s1;
    // . is member access operator
    // . is field access operator
    //s1.getData();
    //s1.printData();

    dynamicMemory dM1;
    //dM1.one_D_Array();
    //dM1.two_D_Array();

    classFeatures classVar;
    cout << "Num is = " << classVar.num << endl;
    cout << "Ref value 1 is = " << classVar.refVar1 << endl;
    cout << "Ref value 2 is = " << classVar.refVar2 << endl;

    cout << "Ref value chnaged to 20\n";
    classVar.refVar1 = 20;
    cout << "Num is = " << classVar.num << endl;
    cout << "Ref value 1 is = " << classVar.refVar1 << endl;
    cout << "Ref value 2 is = " << classVar.refVar2 << endl;

    int numA = 10;
    int numB = 20;

    cout << "Before Swapping\n";
    cout << "numA is = " << numA << endl;
    cout << "numB is = " << numB << endl;

    // - in case of pass by address classVar.swapByRefernce(&numA,&numB);
    classVar.swapByRefernce(numA,numB);

    cout << "After Swapping\n";
    cout << "numA is = " << numA << endl;
    cout << "numB is = " << numB << endl;

    cout << "Sum with 3 argument = " << classVar.defaultArgumentSum(10,20,30) << endl;
    cout << "Sum with 2 argument = " << classVar.defaultArgumentSum(10,20) << endl;
    cout << "Sum with 1 argument = " << classVar.defaultArgumentSum(10) << endl;
    cout << "Sum with no argument = " << classVar.defaultArgumentSum() << endl;

    // - class as an argument
    classArgument class1;
    classArgument class2;
    class1.setValue();
    class2.setValue();
    class1.passClassAsArgument(class2);

    // - This pointer usage
    class1.thisPointerUsage(100,200);

    // - Return class as argument
    classArgument classA;
    classArgument classB;
    classArgument classC;
    classA.getValue();
    classB.getValue();
    classC = classA.returnTypeAsClass(classB);

    classA.putValue();
    classB.putValue();
    classC.putValue();

    return(0);
}