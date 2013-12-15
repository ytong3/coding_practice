class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<bool> temp(board[0].size(),false);
        vector<vector<bool> > visited(board.size(),temp);
        
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++)
                if(board[row][col]==word[0])
                    if(dfs(board,visited,word,1,row,col))
                        return true;
        }
        return false;
    }
    
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, string word, int idx, int row0, int col0){
        if(idx==word.length()){
            return true;
        }
        visited[row0][col0]=true;
        bool up(false),down(false),left(false),right(false);
        if(row0>0&&board[row0-1][col0]==word[idx]&&visited[row0-1][col0]==false)
            if(dfs(board,visited,word,idx+1,row0-1,col0))
				return true;
        if(row0<board.size()-1 && board[row0+1][col0]==word[idx]&&visited[row0+1][col0]==false)
			if(dfs(board,visited,word,idx+1,row0+1,col0))
				return true;
        if(col0>0&&board[row0][col0-1]==word[idx]&&visited[row0][col0-1]==false)
            if(dfs(board,visited,word,idx+1,row0,col0-1))
				return true;
        if(col0<board[0].size()-1&&board[row0][col0+1]==word[idx]&&visited[row0][col0+1]==false){
            if(dfs(board,visited,word,idx+1,row0,col0+1))
				return true;
        
        
        visited[row0][col0]=false;//code works(meets the time limits) right after I move this line from before #32 to after it. What's the major difference?
        return false;
    }
};
