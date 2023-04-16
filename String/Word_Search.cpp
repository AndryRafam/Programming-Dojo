/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static vector<string> find(vector<vector<char>> &board, string word) {
		for(auto i(0); i!=(int)board.size(); ++i) {
			for(auto j(0); j!=(int)board[i].size(); ++j) {
				if(dfs(board,word,i,j,0)){
					return word;
				}
			}
		}
		return "NOT FOUND";
	}
	static bool dfs(vector<vector<char>> &board, string word, int i, int j, int k) {
		if(k==(int)word.size()) {
			return true;
		}
		if(i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[i].size() || board[i][j]!=word[k]) {
			return false;
		}
		else {
			char temp = board[i][j];
			board[i][j] = '$'; // mark as visited
			bool found = dfs(board,word,i+1,j,k+1) || 
				     dfs(board,word,i-1,j,k+1) || 
			 	     dfs(board,word,i,j+1,k+1) || 
			 	     dfs(board,word,i,j-1,k+1);
			board[i][j]=temp;
			return found;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<char>> board = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
	string word = "escc";
	cout << Solution::find(board,word);
	return 0;
}
