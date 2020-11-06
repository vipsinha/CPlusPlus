#include <sstream>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    int a;
    vector<int> vec;

    while (ss >> a){
        // Provide proper checks here for "a" like if empty
        // Also strip down symbols like !, ., ?, etc.
        // Finally push it.
        vec.push_back(a);

        if (ss.peek() == ','){
            ss.ignore();
        }
    }

    return vec;
}

void printFrequency(string st) 
{ 
    // each word it mapped to it's frequency 
    map<string, int> FW; 
    stringstream ss(st); // Used for breaking words 
    string Word; // To store individual words 
  
    while (ss >> Word) 
        FW[Word]++; 
  
    map<string, int>::iterator m; 
    for (m = FW.begin(); m != FW.end(); m++) 
        cout << m->first << " -> "
             << m->second << "\n"; 
} 

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    string s = "Geeks For Geeks Ide"; 
    printFrequency(s);
    
    return 0;
}
