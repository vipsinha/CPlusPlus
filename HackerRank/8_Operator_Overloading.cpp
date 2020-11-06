/*
Input:
1
2 2
2 2 2 2
1 2 3 4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
        vector <vector <int> > a;
        
        Matrix operator+(const Matrix& B){
            Matrix res;
            vector<int> resRow;
            int num;
            for(int i=0; i<B.a.size();++i){
                resRow.clear();
                for(int j=0; j<B.a[0].size();++j){
                    num = a[i][j] + B.a[i][j];
                    resRow.push_back(num);
                }
                res.a.push_back(resRow);
            }
            return(res);
        }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
