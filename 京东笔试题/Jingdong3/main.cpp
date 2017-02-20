//设苹果总数x, 由题意知（x+n-1） 可被n 整除，  第一只熊分到 （x+n-1)/n只苹果（分到的+扔掉的）。 
//此时还剩下（n-1)(x+n-1)/n 只苹果。 第二只熊分得 （n-1)(x+n-1)/n^2 只苹果(分到的+扔掉的），    
//依次类推   ……    最后一只熊（分到+扔掉）K= (n-1)^(n-1)(x+n-1)/n^n  只苹果。
//K 为自然数，故分子必须是n^n的倍数。  由于(n-1)^(n-1) 与 n^n 互质， 则必有 (x+n-1) = t * n^n 。显然 t 取 1 时x 最小， x= n^n -n+1。
class Apples {
public:
    int getInitial(int n) {
        int N = n;
        // write code here
        for(int i = 1;i < n;i++){
            N = N * n;
        }
        return (N - n + 1);
    }
};