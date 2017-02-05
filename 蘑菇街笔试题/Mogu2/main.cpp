#include <iostream>

using namespace std;

int minDiff(int numInput[],int minInput)
{
    int dis;
    //int dis0;
    int maxdis[1000];
    int maxdisNew[1000];
    int maxNum;
    int maxdisNum;
    maxdisNum = maxdis[0] = numInput[1] - numInput[0];
    for(int j = 0;j < minInput -1;j++)
    {
        maxdis[j] = numInput[j+1] - numInput[j];
    }
    for(int j = 0;j < minInput -1;j++)
    {
        if(maxdis[j] > maxdisNum)
        {
            maxdisNum = maxdis[j];
        }
    }

    maxNum = maxdis[0];
    for(int k = 0;k < minInput - 2;k++)
    {
        maxdisNew[k] = maxdis[k+1] + maxdis[k];
        //cout << maxdisNew[k] << endl;
    }

    maxdisNew[minInput-2] = maxdis[1];
    maxdisNew[minInput-1] = maxdis[minInput-3];
    //cout << maxdisNew[minInput-1] << endl;
    maxNum = maxdisNew[0];

    for(int m = 0;m < minInput;m++)
    {
        //cout << maxdisNew[m] << endl;
        if(maxdisNew[m] > maxNum)
        {
            maxNum = maxdisNew[m];
        }
    }
    if(maxdisNum > maxNum)
        return maxNum;
    else
        return maxdisNum;
}

int main()
{
    int maxDis;
    int num[1000];
    int minDis;
    while(cin >> maxDis)
    {
        for(int i = 0;i < maxDis;i++)
        {
            cin >> num[i];
        }
        minDis = minDiff(num,maxDis);
        cout << minDis << endl;
    }
    return 0;
}
