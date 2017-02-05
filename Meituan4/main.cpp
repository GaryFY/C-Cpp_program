class MaxInnerRec {
public:
    int countArea(vector<int> A, int n) {
        // write code here
        int max_area = 0;//初始化最大面积

        for(int i=0;i<n;++i){
            int h = A[i];  //长方形高
            int j=i+1;
            int len = 1; //长方形宽
            while(j<n && A[j]>=A[i]){ //向后搜索
                j++;
                len++;
            }
            int k=i-1;
            while(k>=0 && A[k]>=A[i]){ //向前搜索
                k--;
                len++;
            }
            if(max_area < h*len){
                max_area = h*len;
            }
        }

        return max_area;
    }
};

