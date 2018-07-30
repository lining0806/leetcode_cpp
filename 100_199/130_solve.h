//
//  130_solve.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _30_solve_h
#define _30_solve_h

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[i].size(); ++j){
                if((i==0 || i==board.size()-1 || j==0 || j==board[i].size()-1) && board[i][j]=='O' ){
                    solveDFS(board, i, j);
                }
            }
        }
        
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[i].size(); ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
        
    }
    
private:
    void solveDFS(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'O')
            board[i][j] = '$';
        
        if(i>0 && board[i-1][j]=='O')
            solveDFS(board, i-1, j);
        if(j<board[i].size()-1 && board[i][j+1]=='O')
            solveDFS(board, i, j+1);
        if(i<board.size()-1 && board[i+1][j]=='O')
            solveDFS(board, i+1, j);
        if(j>0 && board[i][j-1]=='O')
            solveDFS(board, i, j-1);
        
    }
};

#endif /* _30_solve_h */
