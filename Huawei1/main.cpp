#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int times;
int i;
int getMinNum(int Mnum)
{
	int ModNum;// ำเสý
	int DivNum;// ษฬ

    //if(Mnum == 2)
    //{
    //   	ModNum = Mnum % 3 ;
    //    DivNum = Mnum / 3 -1;
    //}
    //else
    //{
        ModNum = Mnum % 3;
        DivNum = Mnum / 3;
    //}


	if (DivNum >= 1)
	{
		times = times + DivNum;
	}
	if(DivNum == 0 )
	{
		if (ModNum == 2)
		{
			times = times + 1;
		}
		else
		{
			times = times;
		}
	}
	if(DivNum  > 0)
	{
		Mnum = DivNum + ModNum;

		getMinNum(Mnum);
	}
	int mtimes = times;
	return mtimes;
}

int main()
{
	int num[10];
	int MinNum;
	int temp;
    i = 0;

    while(cin >> num[i])
    {
        if(num[i] == 0)
        {
            for(int m=0;m<i;m++)
            {
                temp = num[m];
                //cout << temp << endl;
                MinNum = getMinNum(temp);
                times = 0;
                cout << MinNum << endl;
            }
        i = 0;
        }
        else
        {
            i++;
        }

    }

	return 0;
}


