//DP动态规划，时间复杂度o(n),空间复杂度o(2*n),这题还有将vec1的空间省去。
//先从左向右扫描，分别找到每个元素之前最大差值
//再从右向左扫描，找到每个元素之后最大差值
class Solution {
public:
     int calculateMax(vector<int> prices) {
        vector<int> vec1(prices.size(),0), vec2(prices.size(),0);
        //vec1[i]表示从第1天到第i+1天的最大收益
        //vec2[i]表示从第i+1天到最后一天的最大收益
        int min=prices[0];  // 用于保存数组中最小值
        for(int i=1;i<prices.size();i++){
            vec1[i]=vec1[i-1];
             
            if(prices[i]-min>vec1[i])
                vec1[i]=prices[i]-min;
             
            if(prices[i]<min)
                min=prices[i];                
        }
          
        int max=prices[prices.size()-1];  // 用于保存数组中最大值
        for(int i=prices.size()-2;i>=0;i--){
            vec2[i]=vec2[i+1];
             
            if(max-prices[i]>vec2[i])
                vec2[i]=max-prices[i];
             
            if(max<prices[i])
                max=prices[i];
        }
          
        int R=0;
        for(int i=0;i<prices.size();i++){
            if(vec1[i]+vec2[i]>R)
                R=vec1[i]+vec2[i];
        }  
          
        return R;
    }
};