//ÿ�깫˾ƽ�������Ҫ��һ�꣬��ӡ���
//ceil(y)���ش���y����С����  �����������
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
