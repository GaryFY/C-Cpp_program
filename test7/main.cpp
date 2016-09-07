#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

template<class Type>
//√∞≈›≈≈–Ú
void BubbleSort(Type* array,int start,int end)
{
    for(int i = 0;i < end - start;i++)
        {
            for(int j = 0;j < end - start;j++)
            {
                if(array[j] > array[j + 1])
                    swap(array[j],array[j + 1]);
            }
        }

}
//»•÷ÿ
void deleteSame(int Num[],int *NumInput)
{
    int k = 0;
    for(int i = 1;i < *NumInput;i++)
    {
        if(Num[i] != Num[k])
        {
            Num[k+1] = Num[i];
            k++;
        }
    }
    *NumInput = k + 1;
}

int main()
{
    int num[1000];//input array
    int numInput;//input number

    while(cin >> numInput)
    {
        for(int i = 0;i < numInput;i++)
        {
            cin >> num[i];
        }

        BubbleSort(num,0,numInput-1);
        deleteSame(num,&numInput);

        for(int j = 0;j < numInput;j++)
        {
            cout << num[j] << endl;
        }
    }
    return 0;
}
