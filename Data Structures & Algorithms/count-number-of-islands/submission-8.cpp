class Solution {
private:
    void bfs(int i, int j,set<vector<int>>& visited,vector<vector<char>>& grid){
        deque<vector<int>> q;
        q.push_back({i, j});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> curr;
        visited.insert({i, j});

        int dx, dy;
        while(q.size() != 0){
            curr = q.back();
            q.pop_back();
            for(auto d : directions){
                dx = curr[0] + d[0];
                dy = curr[1] + d[1];
                if(!visited.contains({dx,dy})
                && dx < grid.size()
                && dx >= 0
                && dy >= 0
                && dy < grid[0].size()
                && grid[dx][dy] == '1'){
                    q.push_back({dx,dy});
                    visited.insert({dx,dy});
                }
            }
        }

    }
public:

    
    int numIslands(vector<vector<char>>& grid) {
        set<vector<int>> visited;
        int result = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1' && !visited.contains({i, j})){
                    bfs(i, j, visited, grid);
                    result++;
                }
            }
        }
        return result;
    }
};
