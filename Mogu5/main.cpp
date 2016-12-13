#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int palindrome(string strPa,int num)
{
    string strPaOutput = strPa;

    reverse(strPaOutput.begin(),strPaOutput.end());//reverse the string

    if(strPa == strPaOutput)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//insert a char and be sure palindrome
int surePalindrome(string str)
{
    int length;
    int pFlag;
    int returnFlag = 0;
    string strOutput;
    string strTemp;
    length = str.size();//length of input string

    for(char ch = 'a';ch <= 'z';ch++)
    {
        strOutput = ch;
        for(int i = 0;i <= length;i++)
        {
            strTemp = str;
            strTemp.insert(i,strOutput);//new string after inserting a char
            //cout << strTemp << endl;
            pFlag = palindrome(strTemp,length+1);//be sure palindrome

            if(pFlag == 1)
            {
                returnFlag = 1;
            }
        }

    }
    return returnFlag;
}

int main()
{
    string strInput;
    int flag;
    while(cin >> strInput)//input a string
    {
        if(strInput.size() < 10)//the length of string < 10
        {
            flag = surePalindrome(strInput);
            if(flag == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    //cout << "Hello world!" << endl;
    return 0;
}
