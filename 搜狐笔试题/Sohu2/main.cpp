/*********************************************************************/
    //大条件：两个字符串的长度必须不大于6
    //合理输入：1.3<=长度<=6
    //          2.10必须相连
    //          3.一个字符串的三个字符相等，那么另外一个人最多能有一个此字符（0/1个）
    //          4.长度=3:没有0和1
    //            长度=4：一个10
    //            长度=5：两个10
    //            长度=6：三个10，并且只能有一个人出现这种情况
    //
/*********************************************************************/
#include <iostream>

using namespace std;

void intCompare(int intFirstArray[],int intSecondArray[],int intlengthFirst,int intlengthSecond)
{
    int FirstArray[100];
    int SecondArray[100];

    int FirstIndex = 0;
    int SecondIndex = 0;

    FirstArray[0] = intFirstArray[0];
    SecondArray[0] = intSecondArray[0];

    int flagFirst = 0;
    int flagSecond = 0;

    for(int i = 1;i < intlengthFirst;i++)
    {
        if(intFirstArray[i-1] == 1)
        {
            if(intFirstArray[i] == 0)
            {
                FirstArray[i-(FirstIndex+1)] = 10;
                //cout << "okokokok" << endl;
                FirstIndex = FirstIndex + 1;
            }
            else
            {
                cout << -2 << endl;
                i = intlengthFirst;
                flagFirst = 1;
            }
        }
        else if(intFirstArray[i] == 0)
        {
            if(intFirstArray[i] == 1)
            {
                FirstArray[i-(FirstIndex+1)] = 10;
                //cout << "okokokok" << endl;
                FirstIndex = FirstIndex + 1;
            }
            else
            {
                cout << -2 << endl;
                i = intlengthFirst;
                flagFirst = 1;
            }
        }
        else
        {
            FirstArray[i-FirstIndex] = intFirstArray[i];
        }
    }

    for(int i = 1;i < intlengthSecond;i++)
    {
        if(intSecondArray[i-1] == 1)
        {
            if(intSecondArray[i] == 0)
            {
                SecondArray[i-(SecondIndex+1)] = 10;
                //cout << "okokokok" << endl;
                SecondIndex = SecondIndex + 1;
            }
            else
            {
                cout << -2 << endl;
                i = intlengthSecond;
                flagSecond = 1;
            }

        }
        else if(intSecondArray[i] == 0)
        {
            if(intSecondArray[i-1] == 1)
            {
                SecondArray[i-(SecondIndex+1)] = 10;
                //cout << "okokokok" << endl;
                SecondIndex = SecondIndex + 1;
            }
            else
            {
                cout << -2 << endl;
                i = intlengthSecond;
                flagSecond = 1;
            }
        }
        else
        {
            SecondArray[i-SecondIndex] = intSecondArray[i];
        }
    }
    int tempFisrt[100];
    int tempSecond[100];
    tempFisrt[0] = FirstArray[0];
    tempSecond[0]= SecondArray[0];
    if((intlengthFirst-FirstIndex) > 3 || (intlengthSecond-SecondIndex) > 3)
    {
        cout << -2 << endl;
        flagSecond = 1;
        flagSecond = 1;
    }
    for(int k = 0;k < (intlengthFirst-FirstIndex);k++)
    {
        for(int j = k+1;j < (intlengthFirst-FirstIndex);j++)
        {
            if(FirstArray[j] > FirstArray[k])
            {
                tempFisrt[k] = FirstArray[j];
                FirstArray[j] = FirstArray[k];
                FirstArray[k] = tempFisrt[k];
            }
        }

    }
    for(int k = 0;k < (intlengthSecond-SecondIndex);k++)
    {
        //cout << SecondArray[k] << endl;
        for(int j = k+1;j < (intlengthSecond-SecondIndex);j++)
        {
            if(SecondArray[j] > SecondArray[k])
            {
                tempSecond[k] = SecondArray[j];
                SecondArray[j] = SecondArray[k];
                SecondArray[k] = tempSecond[k];
            }
        }
        //cout << SecondArray[k] << endl;
    }
    if(flagFirst == 0 && flagSecond == 0)
    {
        int j = 0;
        int sameFirstNum = 1;
        int sameSecondNum = 1;//字符出现一样的次数
        int conFirstNum = 0;
        int conSecondNum = 0;//连续标志
        int tempFisrtInt;
        int tempSecondInt;

        int sameBetween1 = 0;
        int sameBetween2 = 0;
        //判断有几个一样的数字
        for(int i = 1;i < 3;i++)
        {
            if(FirstArray[i] == FirstArray[i-1])
            {
                sameFirstNum = sameFirstNum + 1;
            }
            if(SecondArray[i] == SecondArray[i-1])
            {
                sameSecondNum = sameSecondNum + 1;
            }
            if((FirstArray[i-1] - FirstArray[i]) == 1)
            {
                conFirstNum = conFirstNum + 1;
            }
            if((SecondArray[i-1] - SecondArray[i]) == 1)
            {
                conSecondNum = conSecondNum + 1;
            }
        }

        for(int i = 1;i < 3;i++)
        {
            if(FirstArray[i] == FirstArray[i-1])
            {
                tempFisrtInt = FirstArray[i];
            }
        }

        for(int i = 1;i < 3;i++)
        {
            if(SecondArray[i] == SecondArray[i-1])
            {
                tempSecondInt = SecondArray[i];
            }
        }
        int flagSame;
        if(sameFirstNum == sameSecondNum) flagSame = 1;
        else flagSame = 0;

        //cout << sameFirstNum << endl;
        //cout << sameSecondNum << endl;

        switch (flagSame)
        {
            //一样数字的个数相等
        case 1:
            if(sameFirstNum == 1 && sameSecondNum == 1)
            {
                for(int i = 0;i < 3;i++)
                {
                    if(FirstArray[i] > SecondArray[i])
                    {
                        cout << 1 << endl;
                        //cout << "OK" << endl;
                        i = 3;
                    }
                    else if(FirstArray[i] < SecondArray[i])
                    {
                        cout << -1 << endl;
                        i = 3;
                    }
                    else
                    {
                        sameBetween1 = sameBetween1 + 1;
                    }
                }
                if(sameBetween1 == 3) cout << 0 << endl;

            }
            else if(sameFirstNum == 2 && sameSecondNum == 2)
            {
                //cout << "ok" << endl;
                if(FirstArray[0] == FirstArray[1])
                {
                    if(SecondArray[0] == SecondArray[1] && SecondArray[0] == FirstArray[0])
                    {
                        if(FirstArray[2] == SecondArray[2]) cout << 0 << endl;
                        else if(FirstArray[2] > SecondArray[2]) cout << 1 << endl;
                        else cout << -1 << endl;
                    }
                    if(SecondArray[1] == SecondArray[2] && SecondArray[1] == FirstArray[0])
                    {
                        cout << -1 << endl;
                    }
                }
                if(FirstArray[2] == FirstArray[1])
                {
                    if(SecondArray[0] == SecondArray[1] && SecondArray[0] == FirstArray[1])
                    {
                        cout << 1 << endl;
                    }
                    if(SecondArray[1] == SecondArray[2] && SecondArray[1] == FirstArray[1])
                    {
                        if(FirstArray[0] > SecondArray[0]) cout << 1 << endl;
                        else cout << -1 << endl;
                    }
                    if(SecondArray[1] == SecondArray[2] && SecondArray[1] > FirstArray[1])
                    {
                        cout << -1 << endl;
                    }
                }

            }
            else
            {
                if(tempFisrtInt > tempSecondInt) cout << 1 << endl;
                else if(tempFisrtInt == tempSecondInt) cout << -2 << endl;
                else cout << -1 << endl;
            }
            break;
            //一样的个数不等
        case 0:
            //第一个人3张一样
            if(sameFirstNum == 3)
            {
                if(sameSecondNum == 2)
                {

                    if(tempSecondInt == FirstArray[0]) cout << -2 << endl;
                    else cout << 1 << endl;
                }
                else
                {
                    cout << 1 << endl;
                }
            }
            //第二个人三张一样
            else if(sameSecondNum == 3)
            {
                if(sameFirstNum == 2)
                {

                    if(tempFisrtInt == SecondArray[0]) cout << -2 << endl;
                    else cout << -1 << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }

            else
            {
                if(conFirstNum == 2 || conSecondNum == 2)
                {
                    //cout << conFirstNum << endl;
                    //cout << conSecondNum << endl;
                    if(conFirstNum > conSecondNum) cout << 1 << endl;
                    else if(conFirstNum < conSecondNum) cout << -1 << endl;
                    else
                    {
                        if(FirstArray[0] > SecondArray[0]) cout << 1 << endl;
                        else if(FirstArray[0] < SecondArray[0]) cout << -1 << endl;
                        else cout << 0 << endl;
                    }
                }
                else
                {
                    if(sameFirstNum > sameSecondNum) cout << 1 << endl;
                    else
                    {
                        cout << -1 << endl;
                    }
                }
            }
            break;
        default:
            break;
        }
    }

}

void StringtoChar(string strFirstInput,string strSecondInput)
{
    int lengthFirst;
    int lengthSecond;

    lengthFirst = strFirstInput.size();
    lengthSecond = strSecondInput.size();

    char chFirstInput[lengthFirst];
    char chSecondInput[lengthSecond];

    int intFirstInput[lengthFirst];
    int intSecondInput[lengthSecond];

    int flagOK = 0;

    if(lengthFirst <= 6 && lengthFirst >= 3 && lengthSecond <= 6 && lengthSecond >= 3)
    {
        for(int i = 0;i < lengthFirst;i++)
        {
            chFirstInput[i] = strFirstInput[i];

            switch (chFirstInput[i])
            {
                case 'J':
                    chFirstInput[i] = 11;
                    break;
                case 'Q':
                    chFirstInput[i] = 12;
                    break;
                case 'K':
                    chFirstInput[i] = 13;
                    break;
                case 'A':
                    chFirstInput[i] = 14;
                    break;
                default:
                    break;
            }

            if(chFirstInput[i] >= 48)
            {
                intFirstInput[i] = int(chFirstInput[i]-48);
            }
            else
            {
                intFirstInput[i] = int(chFirstInput[i]);
            }
            if(intFirstInput[i] < 0 || intFirstInput[i] > 14)
            {
                cout << -2 << endl;
                i = lengthFirst;
                flagOK = 1;
            }

            //cout << intFirstInput[i] << endl;
            //cout << lengthSecond << endl;
        }
        for(int i = 0;i < lengthSecond;i++)
        {
            chSecondInput[i] = strSecondInput[i];

            switch (chSecondInput[i])
            {
                case 'J':
                    chSecondInput[i] = 11;
                    break;
                case 'Q':
                    chSecondInput[i] = 12;
                    break;
                case 'K':
                    chSecondInput[i] = 13;
                    break;
                case 'A':
                    chSecondInput[i] = 14;
                    break;
                default:
                    break;
            }
            //cout << chSecondInput[i] << endl;
            if(chSecondInput[i] >= 48)
            {
                intSecondInput[i] = int(chSecondInput[i]-48);
            }
            else
            {
                intSecondInput[i] = int(chSecondInput[i]);
            }
            if(intSecondInput[i] < 0 || intSecondInput[i] > 14)
            {
                cout << -2 << endl;
                i = lengthSecond;
                flagOK = 1;
            }
            //cout << intSecondInput[i] << endl;
        }
        //进行比较
        if(flagOK == 0)
            intCompare(intFirstInput,intSecondInput,lengthFirst,lengthSecond);
    }
    //非法输入
    else
    {
        cout << -2 << endl;
    }
}

int main()
{
    string strFirstPerson;
    string strSecondPerson;

    while(cin >> strFirstPerson)
    {
        //将字符串转换为三个字符,并比较大小
        cin >> strSecondPerson;
        //cout << strFirstPerson.size() << endl;
        //cout << strSecondPerson.size() << endl;
        StringtoChar(strFirstPerson,strSecondPerson);
    }

    //cout << "Hello world!" << endl;
    return 0;
}
