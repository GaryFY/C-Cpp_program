#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n, t, c;
    while (cin >> n >> t >> c){
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int result = 0;
        int sum = 0;
        //求出前c个犯人罪行和
        for (int i = 0; i <c; i++){
            sum += a[i];
        }
        //判断是否满足要求
        if (sum <= t){
            result++;
        }
        //向后移动
        for (int i = c; i < n; i++){
            sum -= a[i - c];
            sum += a[i];
            if (sum <= t){
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}

