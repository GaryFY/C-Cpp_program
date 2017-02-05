class MaxInnerRec {
public:
    int countArea(vector<int> A, int n) {
        // write code here
        int max_area = 0;//��ʼ��������

        for(int i=0;i<n;++i){
            int h = A[i];  //�����θ�
            int j=i+1;
            int len = 1; //�����ο�
            while(j<n && A[j]>=A[i]){ //�������
                j++;
                len++;
            }
            int k=i-1;
            while(k>=0 && A[k]>=A[i]){ //��ǰ����
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

