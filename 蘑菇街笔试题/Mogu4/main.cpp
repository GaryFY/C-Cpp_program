#include <iostream>

using namespace std;

long long getNum(long long numBaseInput[],long long numBasketballInput,long numNetInput)
{
    long long numReset[1000];
    long long numSame[1000];
    for(long long i = 0;i < numBasketballInput;i++)
    {
        numReset[i] = numBaseInput[i] % numNetInput;
        //cout << numReset[i] << endl;
    }
    for(long long j = 0;j < numBasketballInput;j++)
    {
        for(long long k = j+1;k < numBasketballInput;k++)
        {
            if(numReset[j] == numReset[k])
            {
                numSame[k] = k;
                //cout << numSame[j] << endl;
            }
        }
        //cout << numSame[j] << endl;
    }
    long long flagOk;
    long long flagNo;
    for(long long m = (numBasketballInput - 1);m >= 0;m--)
    {
        if(numSame[m] == 0)
        {
            flagOk = 0;
        }
        else
        {
            flagNo = numSame[m];
        }
    }
    if(flagNo != 0)
    {
        return (flagNo + 1);
    }
    else
        return -1;

}

int main()
{
    long long numNet;
    long long numBasketball;
    long long numBase[1000];
    long long Value;
    while(cin >> numNet >> numBasketball)
    {
        for(long long i = 0;i < numBasketball;i++)
        {
            cin >> numBase[i];
        }
        if(numBasketball == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            Value = getNum(numBase,numBasketball,numNet);
        	cout << Value << endl;
        }

    }
    //cout << "Hello world!" << endl;
    return 0;
}
