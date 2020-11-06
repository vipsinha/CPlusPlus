/*
Sample Input
6
1 4 6 2 8 9
2
2 4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> inData;
    int data;
    int N, x, a, b;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> data;
        inData.push_back(data);
    }
    
    cin >> x;
    inData.erase(inData.begin()+x-1);
    
    cin >> a >> b;
    inData.erase(inData.begin()+a-1, inData.begin()+b-1);

    cout << inData.size() << endl;
    for(int i=0; i<inData.size(); i++){
        cout << inData[i] << " ";
    }  
    return 0;
}
