/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int numIslands(vector<vector<char>> &grid){
        int count = 0;
        for(auto i(0); i < grid.size(); ++i){
            for(auto j(0); j < grid[0].size(); ++j){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
    private:
    static bool dfs(vector<vector<char>> &grid, int i, int j){
        int N = grid.size();
        int M = grid[0].size();
        if(i < 0 || i >= N || j < 0 || j >= M || grid[i][j]=='0'){
            return false;
        }
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            for(auto &dir : directions){
                int new_row = i+dir.first;
                int new_col = j+dir.second;
                if(dfs(grid,new_row,new_col)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << Solution::numIslands(grid) << "\n";
    return 0;
}
