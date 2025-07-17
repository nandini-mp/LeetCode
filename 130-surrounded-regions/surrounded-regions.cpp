class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& board,int drow[],int dcol[])
    {
        int m=board.size(),n=board[0].size();
        visited[i][j]=1;
        //check top, bottom, left, right Os and mark them visited
        for (int k=0;k<4;k++)
        {
            int newRow=i+drow[k];
            int newCol=j+dcol[k];
            if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && !visited[newRow][newCol] && board[newRow][newCol]=='O')
                dfs(newRow,newCol,visited,board,drow,dcol);          
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        //traverse boundary rows
        for (int j=0;j<n;j++)
        {
            if (!visited[0][j] && board[0][j]=='O')
                dfs(0,j,visited,board,drow,dcol);
            if (!visited[m-1][j] && board[m-1][j]=='O')
                dfs(m-1,j,visited,board,drow,dcol);
        }

        for (int i=0;i<m;i++)
        {
            if (!visited[i][0] && board[i][0]=='O')
                dfs(i,0,visited,board,drow,dcol);
            if (!visited[i][n-1] && board[i][n-1]=='O')
                dfs(i,n-1,visited,board,drow,dcol);
        }

        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
            {
                if (board[i][j]=='O' && !visited[i][j])
                    board[i][j]='X';
            }
    }
};