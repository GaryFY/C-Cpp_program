/**********************************************/
/* Author:	GaryFY
/*   Date:	2017.2.19
/**********************************************/
#include <iostream>
 
using namespace std;
//判断距离是否够
int getResult(int value,int x,int y,int targetx,int targety){
    if(value*value >= ((x-targetx)*(x-targetx)+(y-targety)*(y-targety))){
        return 1;
    }
    else{
        return 0;
    }
}
 
int main(){
    int R;
    int firstx,firsty;
    int secx,secy;
    int thirdx,thirdy;
    int X,Y;
    int result;
     
    while(cin >> R >> firstx >> firsty >> secx >> secy >> thirdx >> thirdy >> X >> Y){
        result = getResult(R,firstx,firsty,X,Y)+getResult(R,secx,secy,X,Y)+getResult(R,thirdx,thirdy,X,Y);
        cout << result << "x" << endl;
    }
     
    return 0;
}