// Date: 2020-04-13
// - Template/Generic function/classes
// - Overloading with template

#include<iostream>
using namespace std;

// - With template, program size is reduced
template <class clsT>
class baseClassA
{
private:
    /* data */
    clsT dataA;
public:
    baseClassA(/* args */);
    ~baseClassA();
    void printData(clsT);
};

template <class clsT>
baseClassA<clsT>::baseClassA(/* args */)
{
    cout << "In base template class constructor\n";
}

template <class clsT>
baseClassA<clsT>::~baseClassA()
{
    cout << "In base template class destructor\n";
}

template <class clsT>
void baseClassA<clsT>::printData(clsT data)
{
    cout << "Data is: " << data << endl;
}

// Template function
// T is called the place holder
template <typename T>
T findMax(T a, T b)
{
    return((a>b)? a:b);
}

// Template array
template <class T>
T arraySum (T arr[], int size)
{
    T dataSum = 0;
    for(int index=0; index<size; index++)
    {
        dataSum += arr[index];
    }
    return(dataSum);
}

// Template function with different data type
template <class T1, class T2>
float sum(T1 t1, T2 t2)
{
    return (t1+t2);
}

// Template with function overloading
template<class T1, class T2>
float sum(T1 t1, T2 t2, T1 t3, T2 t4)
{
    return(t1+t2+t3+t4);
}

int main()
{
    baseClassA <int>DataObj;
    int arr1[] = {1,3,4,6,7};
    float arr2[] = {1.5,2.3,4.5};

    cout << "Greater is: " << findMax(1,2) << endl;
    cout << "Greater is: " << findMax('a','b') << endl;

    cout << "Array sum is: " << arraySum(arr1,5) << endl;
    cout << "Array sum is: " << arraySum(arr2,3) << endl;

    cout << "Sum is: " << sum(1,1.5) << endl;
    cout << "Sum is: " << sum('a',1.5) << endl;
    cout << "Sum is: " << sum(1,1.5, 2, 4.5) << endl;

    DataObj.printData(5);

    return(0);
}