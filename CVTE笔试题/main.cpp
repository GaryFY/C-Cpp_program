/**********************************************/
/* Author:	GaryFY
/*   Date:	2017.2.19
/**********************************************/
#include <iostream>
using namespace std;
int main()
{
    int x, n;  
    int circle[20];
    while (cin >> x >> n)
    {
        int k = 1;  //表示查找次数
        x = x - 1;  //洞数组下标
        int step = 2;
        for (int i = 0; i < 20; i++)
        {
            circle[i] = 1;  //表示可能藏着兔子
        }
        while (k <= n)
        {
            circle[x] = 0;  //表示不可能藏着兔子
            x = (x + step)%20;     
            step++;
            k++;
        }
        bool flag = true; //洞中藏兔子标志
        for (int i = 0; i < 20; i++)
        {
            if (circle[i] == 1)
            {
                cout << i + 1 << " ";
                flag = false;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << endl;
        }
    }
     
    return 0;
}