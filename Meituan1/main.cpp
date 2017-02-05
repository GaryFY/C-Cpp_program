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
        //���ǰc���������к�
        for (int i = 0; i <c; i++){
            sum += a[i];
        }
        //�ж��Ƿ�����Ҫ��
        if (sum <= t){
            result++;
        }
        //����ƶ�
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

