#include <iostream>

using namespace std;

int conNum(int pfirst[],int psecond[],int qfirst[],int qsecond[],int pValue,int qValue,int minGetup,int maxGetup)
{
    int pDis[100];
    int qDis[100];
    int qNewFirst[100];
    int qNewSecond[100];
    int okFlag;

    for(int i = 0;i < pValue;i++)
    {
        pDis[i] = psecond[i] - pfirst[i];//存放A每个时间段的间隔
        //cout << pfirst[i] << psecond[i] << endl;
    }
    for(int j = 0;j < qValue;j++)
    {
        qDis[j] = qsecond[j] - qfirst[j];//存放B每个时间段的间隔
        qNewFirst[j] = qfirst[j] + minGetup;
        qNewSecond[j] = qsecond[j] + maxGetup;
        //cout << qfirst[j] << qsecond[j] << endl;
    }
    int ATime[1000];
    int AIndex = 0;
    for(int k = 0;k < pValue;k++)
    {
        for(int x = 0;x <= pDis[k];x++)
        {
            AIndex = AIndex + 1;//A有一共时间点
            ATime[AIndex-1] = pfirst[k] + x;
            if(ATime[AIndex-1] > 24)
            {
                ATime[AIndex-1] = ATime[AIndex-1] - 24;
            }
            //cout << ATime[AIndex-1] << endl;
        }
    }

    int BTime[1000];
    int BIndex =0;
    for(int k = 0;k < qValue;k++)
    {
        for(int x = 0;x <= qDis[k];x++)
        {
            BIndex = BIndex + 1;//A有一共时间点
            BTime[BIndex-1] = qfirst[k] + x;
            if(BTime[BIndex-1] > 24)
            {
                BTime[BIndex-1] = BTime[BIndex-1] - 24;
            }
            //cout << BTime[BIndex-1] << endl;
        }
    }
    //cout << BTime[0] << endl;
    int BBIndex = 0;
    int sameTime[1000];
    int BBTime[1000];
    for(int i = minGetup;i <= maxGetup;i++)
    {
        for(int j = 0;j < BIndex;j++)
        {
            BBTime[j] = BTime[j] + i;
            if(BBTime[j] > 24)
            {
                BBTime[j] = BBTime[j] - 24;
            }
            for(int m = 0;m < AIndex;m++)
            {
                if(ATime[m] == BBTime[j])
                {
                    sameTime[i-minGetup] = 1;
                    //cout << i << endl;
                }
            }
            //cout << BTime[j] << endl;
        }
    }
    int sameBB = 0;
    for(int z=0;z <= (maxGetup - minGetup);z++)
    {
        if(sameTime[z] == 1)
        {
            sameBB = sameBB + 1;
            //cout << z << endl;
        }
    }

    return sameBB;
}
int main()
{
    int p,q,l,r;
    int num;//用于统计合适的时间点
    int a[100];
    int b[100];
    int c[100];
    int d[100];

    while(cin >> p >> q >> l >> r)
    {
        for(int i = 0;i < p;i++)
        {
            cin >> a[i] >> b[i];
        }
        for(int j = 0;j <q;j++)
        {
            cin >> c[j] >> d[j];
        }
        num = conNum(a,b,c,d,p,q,l,r);
        cout << num << endl;
    }

    return 0;
}
