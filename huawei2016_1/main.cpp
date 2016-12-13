#include <iostream>

using namespace std;

void getMaxNum(int IDInput[],char QUInput[],int idInput[],int numInput[],int nInput,int mInput)
{
    int maxNum;
    for(int k = 0;k < mInput;k++)
    {
        if(QUInput[k] == 'U')
        {
            IDInput[idInput[k]-1] = numInput[k];
            //cout << numInput[k] << endl;
            //cout << IDInput[idInput[k]-1] << endl;
        }
        if(QUInput[k] == 'Q')
        {
            maxNum = IDInput[idInput[k]-1];
            if(idInput[k] <= numInput[k])
            {

                for(int h = idInput[k];h < numInput[k];h++)
                {
                    if(maxNum < IDInput[h])
                    {
                        maxNum = IDInput[h];
                    }
                }
            }
            else
            {
                for(int l = idInput[k]-1;l >= numInput[k]-1;l--)
                {
                    if(maxNum < IDInput[l])
                    {
                        maxNum = IDInput[l];
                    }
                    //cout << IDInput[l] << endl;
                }
                //cout << maxNum << endl;
            }

            cout << maxNum << endl;
        }
    }
}

int main()
{
    int n,m;
    int ID[30000];
    char QU[30000];
    int id[30000];
    int num[30000];
    while(cin >> n >> m)
    {
        for(int i = 0; i < n;i++)
        {
            cin >> ID[i];
        }
        for(int j = 0;j < m;j++)
        {
            cin >> QU[j] >> id[j] >> num[j];
        }

        getMaxNum(ID,QU,id,num,n,m);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
