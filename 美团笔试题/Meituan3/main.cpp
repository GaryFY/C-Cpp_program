class Visit {
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        // write code here
        int flag=0;
        int st_x,st_y,end_x,end_y;
        for(int i=0;i<n;++i)//寻找经理和商家位置
            for(int j=0;j<m;++j){
                if(2==flag)//找到即退出
                    break;
                else if(1==map[i][j]){
                    st_x=i;
                    st_y=j;
                    flag++;
                }else if(2==map[i][j]){
                    end_x=i;
                    end_y=j;
                    flag++;
                }
        }
        int x_way=st_x>end_x? -1:1;//判断寻找方向
        int y_way=st_y>end_y? -1:1;
        int deep[n][m];//构造动态图
        deep[st_x][st_y]=1;
        for(int i=st_x+x_way;i!=end_x+x_way;i+=x_way)
            deep[i][st_y]=map[i][st_y]==-1? 0:deep[i-x_way][st_y];
        for(int j=st_y+y_way;j!=end_y+y_way;j+=y_way)
            deep[st_x][j]=map[st_x][j]==-1? 0:deep[st_x][j-y_way];
        for(int i=st_x+x_way;i!=end_x+x_way;i+=x_way)
            for(int j=st_y+y_way;j!=end_y+y_way;j+=y_way)
                deep[i][j]=deep[i-x_way][j]+deep[i][j-y_way];
        return deep[end_x][end_y];
    }
};
