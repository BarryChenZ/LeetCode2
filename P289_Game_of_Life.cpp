class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //2:0->1 3:1->0
        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        int count(0);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                count = 0;
                for(int k = 0; k < dir.size(); k++) {
                    int ni = i + dir[k].first, nj = j + dir[k].second;
                    if(ni < board.size() && ni >= 0 && nj < board[0].size() && nj >= 0) {
                        if(board[ni][nj] == 1 || board[ni][nj] == 3) count++;
                    }
                }
                if(count < 2) board[i][j] = board[i][j] == 0 ? 0 : 3;
                if(count == 3) board[i][j] = board[i][j] == 0 ? 2 : 1;
                if(count > 3) board[i][j] = board[i][j] == 0 ? 0 : 3;
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 2 || board[i][j] == 3) {
                    board[i][j] = board[i][j] == 2 ? 1 : 0;
                }
            }
        }
    }
};
