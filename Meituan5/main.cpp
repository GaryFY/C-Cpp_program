//每年公司平均年龄就要加一岁，大坑。。
//ceil(y)返回大于y的最小整数  向无穷大舍入
#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int w,n;
    double x,y;
    while(cin>>w>>y>>x>>n){
        for(int i=0;i<n;++i){
            y=(y+1)*(1-x)+21*x;
        }
        cout<<ceil(y)<<endl;
    }
}
