//��̬�滮����
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N,M,K;

    while(cin >> N >> M >> K){
        vector<vector<int>> map((N+1), vector<int>(M+1));//���ڱ�����Ģ����λ��
        vector<vector<double>> deep((N+1), vector<double>(M+1));//���춯̬ͼ

        int x,y;
        for(int i = 0;i < K;i++){
            cin >> x >> y;
            map[x][y] = -1;
        }

        deep[1][1] = 1.0;//��ʼλ��

        for(int i = 1;i <= N;i++)
            for(int j = 1;j <= M;j++){
                if(!(i == 1 && j == 1)){
                    deep[i][j] = deep[i-1][j] * (j == M ? 1.0 : 0.5) + deep[i][j-1] * (i == N ? 1.0 : 0.5);//���ߵ����·��������ҷ�ʱ������·��ֻ��һ��ѡ�񣬸���Ϊ1
                    if(map[i][j] == -1) deep[i][j] = 0;//����Ģ��
                }
            }

        printf("%.2lf\n", deep[N][M]);
    }

    return 0;
}

