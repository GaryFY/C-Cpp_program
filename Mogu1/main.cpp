#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long minTimes(long numInput[])
{
    long long disX,disY,dis2;
    long double dis;
    disX = abs(numInput[3] - numInput[1]);
    disY = abs(numInput[4] - numInput[2]);
    dis2 = pow(disX,2)+pow(disY,2);
    dis = sqrt(dis2);
    dis = dis / numInput[0] / 2;
    if(dis > (long long)dis)
    {
        return (long long)dis + 1;
    }
    else
    {
        return (long long)dis;
    }
}

int main()
{
    long num[4];
    int minNum;
    while(cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4])
    {
        minNum = minTimes(num);
        cout << minNum << endl;
    }

    return 0;
}
