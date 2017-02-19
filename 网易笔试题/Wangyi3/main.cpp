/**********************************************/
/* Author:	GaryFY
/*   Date:	2017.2.19
/**********************************************/
#include <iostream>
#include <vector>
 
using namespace std;
 
//统计3*3中最多的蘑菇数，并保存第一个格子的行号和列号
void scan(vector<vector<int> > field,int N,int M,int result[]){
    for(int i = 0;i < N-2;i++){
        for(int j = 0;j < M-2;j++){
            int tmp = 0;
            for(int m = i;m < i+3;m++){
                for(int n = j;n < j+3;n++){
                    if(field[m][n] > 0)
                        ++tmp;
                }
            }
            if(result[0] < tmp){
                result[0] = tmp;
                result[1] = i;
                result[2] = j;
            }
        }
    }
}
 
int main(){
    int N,M,K;
    int X,Y;  //用于存储蘑菇所在位置
 
     
    while(cin >> N >> M >> K){
        if(N<3)
            N = 3;
        if(M<3)
            M = 3;
         
        vector<vector<int> > field(N,vector<int>(M,0));
         
        for(int i = 0;i < K;i++){
            cin >> X >> Y;
            ++field[X-1][Y-1];  //有一个蘑菇，相应的位置的值加1
        }
         
        int firstScope[3]={0};
        int secScope[3]={0};
         
        //第一次扫描
        scan(field,N,M,firstScope);
         
        //将第一次扫描后的蘑菇数减1
        for(int j = firstScope[1];j < firstScope[1]+3;j++){
            for(int k = firstScope[2];k < firstScope[2]+3;k++){
                if(field[j][k] > 0){
                    --field[j][k];
                }
            }
        }
         
        //第二次扫描
        scan(field,N,M,secScope);
         
        cout << firstScope[0]+secScope[0] << endl;
    }
    return 0;
}