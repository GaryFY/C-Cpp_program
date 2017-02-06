//动态规划问题
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N,M,K;

    while(cin >> N >> M >> K){
        vector<vector<int>> map((N+1), vector<int>(M+1));//用于保存有蘑菇的位置
        vector<vector<double>> deep((N+1), vector<double>(M+1));//构造动态图

        int x,y;
        for(int i = 0;i < K;i++){
            cin >> x >> y;
            map[x][y] = -1;
        }

        deep[1][1] = 1.0;//起始位置

        for(int i = 1;i <= N;i++)
            for(int j = 1;j <= M;j++){
                if(!(i == 1 && j == 1)){
                    deep[i][j] = deep[i-1][j] * (j == M ? 1.0 : 0.5) + deep[i][j-1] * (i == N ? 1.0 : 0.5);//当走到最下方或者最右方时，行走路线只有一种选择，概率为1
                    if(map[i][j] == -1) deep[i][j] = 0;//遇到蘑菇
                }
            }

        printf("%.2lf\n", deep[N][M]);
    }

    return 0;
}

