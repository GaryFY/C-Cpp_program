//t���Ӻ������ĸ���ΪPt=1-(1-p)^t
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n,m,x,y,t;
    float pcc,pss;
    double flag = 0;


    while(cin >> n >> m >> x >> y >> t){
        vector<vector<float>> pp(n,vector<float>(m,0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> pp[i][j];
                if(x == i+1 && y == j+1)	pcc = pp[i][j];//ccһ���ӵĸ���
                pss += pp[i][j];
            }
        }

        pss = pss/(m*n);//ssһ���ӵĸ���

        //���߸�����ͬ
        if(pss == pcc){
            cout << "equal" << endl;
            flag = 1 - pow(1-pss,t);
            printf("%.2f\n",flag);
        }
        //ss�ĸ��ʴ�
        if(pss > pcc){
            cout << "ss" << endl;
            flag = 1 - pow(1-pss,t);
            printf("%.2f\n",flag);
        }
        //cc�ĸ��ʴ�
        if(pss < pcc){
            cout << "cc" << endl;
            flag = 1 - pow(1-pcc,t);
            printf("%.2f\n",flag);
        }
    }


    return 0;
}
