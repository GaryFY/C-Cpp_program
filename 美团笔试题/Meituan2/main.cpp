class Flip {
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
        // write code here
        for ( int i = 0; i < f.size(); ++ i ) {
            int x = f[i][0] - 1 ;
            int y = f[i][1] - 1;

            if ( x - 1 >= 0 ) {
                int color = A[x - 1][y] ;
                if ( color == 0 ) color = 1 ;
                else if ( color == 1 ) color = 0 ;
                    A[x - 1][y] = color ;
            }
            if ( x + 1 <= 3 ) {
                int color = A[x + 1][y] ;
                if ( color == 0 ) color = 1 ;
                else if ( color == 1 ) color = 0 ;
                    A[x + 1][y] = color ;
            }

            if ( y - 1 >= 0 ) {
                int color = A[x][y - 1] ;
                if ( color == 0 ) color = 1 ;
                else if ( color == 1 ) color = 0 ;
                    A[x][y - 1] = color ;
            }
            if ( y + 1 <= 3 ) {
                int color = A[x][y + 1] ;
                if ( color == 0 ) color = 1 ;
                else if ( color == 1 ) color = 0 ;
                    A[x][y + 1] = color ;
            }
        }
        return A;
    }
};
