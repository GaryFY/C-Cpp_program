/**********************************************/
/* Author:	GaryFY
/*   Date:	2017.2.19
/**********************************************/

//此题很巧妙，即等比数列求和，Sum = a0 * (1-q^n)/(1-q)
class Balls {
public:
    int calcDistance(int A, int B, int C, int D) {
       return 3*(A+B+C+D);
    }
};