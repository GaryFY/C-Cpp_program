/*****************************************************************/
//��������Ŀ����ת��Ϊ���������ҵ��������˵���С�����������Ӧ����ֵ��Ϊ1
//Ȼ���մ�С�����˳��
//��ֵ���Ӧ�Ľ����1��ʼ
//eg1:-20 32 || 12 32 45 || 11 21 31 41 || 33            20 32 _ 32 45 _ 21 31 41 33 ---->20 _ _ _ 45 _ _31 41 33------>20_ _ _ _ _ _ 41 33
//    - 1  2     1  2  3     1  2  3  4     1
//eg2:-33 ||32 || 12 32 45 || 11 21 31 41 || 33
//      3    2     1  2  3     1  2  3  4     1
//eg3:-20 32 || 12 32 45 || 11 21 31 41 || 42
//     3   2     1  2  3     1  2  3  4     5
/*****************************************************************/
#include <iostream>

using namespace std;

void conMinMoney(int scoreInput[],int numInput)
{
    int money = 1;
    int moneyScore[1000];
    int beforeIndex;
    int afterIndex;
    for(int i = 0;i < numInput;i++)
    {
        afterIndex = i + 1;
        if(scoreInput[i] < scoreInput[afterIndex])
        {
            moneyScore[i] = 1;
        }
    }
}

int main()
{
    int num;
    int score[1000];
    while(cin >> num)
    {
        for(int i = 0;i < num;i++)
        {
            cin >> score[i];
        }
        conMinMoney(score,num);
    }
    cout << "Hello world!" << endl;
    return 0;
}
