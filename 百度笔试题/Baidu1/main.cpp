#include<stdio.h>
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> x(n,0);
        vector<int> y(n,0);
        int xmin = INT_MAX;
        int xmax = INT_MIN;
        int ymin = INT_MAX;
        int ymax = INT_MIN;
        for(int i=0; i<n; ++i){
            cin >> x[i];
            cin >> y[i];
            xmin = min(x[i],xmin);
            xmax = max(x[i],xmax);
            ymin = min(y[i],ymin);
            ymax = max(y[i],ymax);
        }
        int k = max(xmax-xmin,ymax-ymin);
        cout << k*k <<endl;
    }
}


