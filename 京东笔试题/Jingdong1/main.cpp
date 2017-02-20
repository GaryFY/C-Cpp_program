/**********************************************/
/* Author:	GaryFY
/*   Date:	2017.2.20
/*
/*	动态规划问题：建立动态规划map
/**********************************************/
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int p[6][6]={0};
        p[0][0]=board[0][0];
        
        //初始化第一行和第一列
        for(int i=1;i<6;i++){
        	p[i][0]=p[i-1][0]+board[i][0];
        	p[0][i]=p[0][i-1]+board[0][i];
        }
        
        //动态规划当前状态：从当前格子的左侧或者上侧转移得来
        for(int i=1;i<6;i++){
        	for(int j=1;j<6;j++){
        		int a=p[i][j-1]>p[i-1][j]?p[i][j-1]:p[i-1][j];
            	p[i][j]=a+board[i][j];
        	}            
        }

        return p[5][5];
    }   
};