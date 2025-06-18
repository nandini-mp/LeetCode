class Solution {
public:
    bool checkLetter(vector<vector<char>>& board,int i,int j,int count,int n,string word) {
        int rows=board.size(),cols=board[0].size();
        if (count==n) return true;
        if (i<0 || j<0 || i>=rows || j>=cols || board[i][j]!=word[count])
            return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool found = 
        checkLetter(board, i + 1, j, count + 1, n, word) ||
        checkLetter(board, i - 1, j, count + 1, n, word) ||
        checkLetter(board, i, j + 1, count + 1, n, word) ||
        checkLetter(board, i, j - 1, count + 1, n, word);
        board[i][j]=temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0;i<board.size();i++)
            for (int j=0;j<board[0].size();j++)
                if (checkLetter(board,i,j,0,word.length(),word))
                    return true;
        return false;
    }
};