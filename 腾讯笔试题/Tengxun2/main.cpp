//利用本题的特性 一个数出现的次数超过总数一半，意味着这个数出现的次数要比剩下的数出现次数总和还要多
//思想：假设每个数字都有可能是最多的，编历的时候遇到一样的就加1，遇到不一样的就减1，则最后剩下的一定是最多的
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        //特殊情况
        if(gifts.size() < n) return 0;
        if(gifts.size() == 0) return 0;
        
        int count = 0,temp;
        for(int i = 0;i < n;i++){
            //第一个数字
            if(count == 0){
                temp = gifts[i];
                count = 1;
            }
            //后面的数字
            else{
                if(temp == gifts[i])
                    count++;
                else
                    count--;
            }
        }
        int size = 0;
        for(int i = 0;i < n;i++){         
            if(temp == gifts[i])
                size++;
        }
        return (size>n/2)?temp:0;
    }
};