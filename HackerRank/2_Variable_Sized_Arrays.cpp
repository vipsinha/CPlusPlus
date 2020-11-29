#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    int index, jndex;
     
    //cout << "Input the array size and query" << endl;
    cin >> n >> q;
    
    vector < vector<int> > outerVector;
    for(index=0;index<n;index++){
        vector<int> innerVector;
        int k;
        int data;
        
        //cout << "Enter the size and array" << endl;
        cin >> k;
        
        for(jndex=0;jndex<k;jndex++){
            cin >> data;
            innerVector.push_back(data);
        }
        outerVector.push_back(innerVector);
    }
    
    //cout << "Enter the indexs" << endl;
    for(int i=0; i<q;i++){
        cin >> index >> jndex;
        cout << outerVector[index][jndex] << endl;
    }
    
    return 0;
}
