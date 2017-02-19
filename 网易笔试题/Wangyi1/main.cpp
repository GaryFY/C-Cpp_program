/**********************************************/
/* Author:	GaryFY
/*   Date:	2017.2.19
/*   思路:	本题的重点在于求取两个数的最大公约数（首先将较大的数放在第一位，然后进行求余运算，直到余数为0）
/**********************************************/
#include <iostream>
 
using namespace std;
 
//求取最大公约数
int getMaxSame(int firstValue,int secValue){
    if(firstValue == 0 || secValue == 0){
        return 0;
    }
     
    if(firstValue < secValue){
        int temp = firstValue;
        firstValue = secValue;
        secValue = temp;
    }
     
    while(secValue != 0){
        int temp2 = firstValue % secValue;
        firstValue = secValue;
        secValue = temp2;
    }
     
    return firstValue;
     
}
 
int main(){
    int monNum;  //怪物数量
    int iniValue;  //初始能力值
    int monValue[100000];  //怪物能力值
     
    while(cin >> monNum >> iniValue){
        for(int i = 0;i < monNum;i++){
            cin >> monValue[i];
        }
         
        for(int j = 0;j < monNum;j++){
            if(iniValue >= monValue[j]){
                iniValue += monValue[j];
            }
            else{
                iniValue += getMaxSame(iniValue,monValue[j]);
            }
        }
         
        cout << iniValue << endl;  
    }
     
    return 0;
}
