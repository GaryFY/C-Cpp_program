class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
        int diff;
        diff = m ^ n;  // 异或操作，得到1即为不同的位
        int i = 0;
        for(i = 0;diff;i++){
            diff &= (diff-1);  // 将最右面的1清零
        }
         
        return i;
 
    }
};
