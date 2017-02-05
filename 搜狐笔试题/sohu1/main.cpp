#include <iostream>

using namespace std;

void getChildIncrease(int data[],int numInputChild)
{
    int lgs[numInputChild];
    int index[numInputChild];
    int Max = 1;

    for(int i = 0;i < numInputChild;i++)
    {
        lgs[i] = 1;//给每一个序列点作为右端时的最大序列长度为1
        //index[i] = i;
    }
    for(int i = 1;i < numInputChild;i++)
    {
        Max=1;
        for(int j = 0;j < i;j++)
        { /*与其前面的每一个进行比较*/
            if(data[i] >= data[j])
            { /*如果数据比前面的某一个的值大*/
                if(lgs[i] + lgs[j] > Max)
                { /*找出该点的最大子序列长度*/
                    Max = lgs[i] + lgs[j];
                }
            }
        }
        lgs[i]=Max;
    }
    Max=lgs[0];
    for(int i = 1;i < numInputChild;i++)
    {
        if(lgs[i] > Max)
        {
            Max = lgs[i];
        }
    }
    cout << Max << endl;
}

void getMostHeight(int NumInput[],int WeightInput[],int HeightInput[],int numInput)
{
    int tempHeight[1000];
    int tempWeight[1000];
    int tempNum[1000];
    //按照体重从小到大的顺序排列
    for(int j = 0;j < numInput;j++)
    {
        for(int i = 0;i < (numInput - 1);i++)
        {
            if(WeightInput[i] > WeightInput[i+1])
            {
                tempHeight[i+1] = HeightInput[i+1];
                HeightInput[i+1] = HeightInput[i];
                HeightInput[i] = tempHeight[i+1];

                tempWeight[i+1] = WeightInput[i+1];
                WeightInput[i+1] = WeightInput[i];
                WeightInput[i] = tempWeight[i+1];

                tempNum[i+1] = NumInput[i+1];
                NumInput[i+1] = NumInput[i];
                NumInput[i] = tempNum[i+1];
            }
            else if(WeightInput[i] == WeightInput[i+1])
            {
                if(HeightInput[i] < HeightInput[i+1])
                {
                    tempHeight[i+1] = HeightInput[i+1];
                    HeightInput[i+1] = HeightInput[i];
                    HeightInput[i] = tempHeight[i+1];

                    tempWeight[i+1] = WeightInput[i+1];
                    WeightInput[i+1] = WeightInput[i];
                    WeightInput[i] = tempWeight[i+1];

                    tempNum[i+1] = NumInput[i+1];
                    NumInput[i+1] = NumInput[i];
                    NumInput[i] = tempNum[i+1];
                }
            }
            else
            {
                continue;
            }
        }
    }

    getChildIncrease(HeightInput,numInput);
    /*for(int i = 0;i < numInput;i++)
    {
        cout << NumInput[i] << WeightInput[i] << HeightInput[i] << endl;
    }*/
    //cout << (numInput - okHeight) << endl;
}

int main()
{
    int numPerson;
    int Num[1000];//people's number
    int Weight[1000];//weight
    int Height[1000];//height
    while(cin >> numPerson)
    {
        for(int i = 0;i < numPerson;i++)
        {
            cin >> Num[i] >> Weight[i] >> Height[i];
        }
        getMostHeight(Num,Weight,Height,numPerson);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
