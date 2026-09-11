class Solution {
public:
    bool check_coord_conditions(int ni, int nj, int row, int col){
        if(ni >= 0 && ni < row && nj >= 0 && nj < col){
            return true;
        }
        return false;
    }
    int bfs(vector<vector<int>>& grid, set<pair<int,int>>& fresh_fruits, deque<pair<int,int>>& curr_rotten){
        int min = 0;
        deque<pair<int,int>> next_rotten;
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int row_size = grid.size();
        int col_size = grid[0].size();
        while(curr_rotten.size() != 0){
            auto [i, j] = curr_rotten.front();
            curr_rotten.pop_front();
            //bfs
            for(const auto d : directions){
                int ni = i + d.first;
                int nj = j + d.second;
                if(check_coord_conditions(ni, nj, row_size, col_size)){
                    if(grid[ni][nj] == 1){
                        next_rotten.push_back({ni,nj});
                        grid[ni][nj] = 2;
                        fresh_fruits.erase({ni, nj});
                        if(fresh_fruits.size() == 0){
                            return min+1;
                        }
                    }
                }
            }
            if(curr_rotten.size() == 0){
                min++;
                curr_rotten = next_rotten;
                next_rotten.clear();
            }
        }
        if(fresh_fruits.size() != 0){
            return -1;
        }
        return min;
    }   

    int orangesRotting(vector<vector<int>>& grid) {
        /*
        set of fresh fruit coordinates
        queue of rotten fruit
        queue of new rotten fruit
        do bfs on rotten fruit
        each fruit we encounter starting from a rotten fruit is added 
        to queue of new rotten fruit
        after current queue is empty
        we do queue = new_rotten_fruit
        each fruit we turn rotten we remove its coordinates from fresh fruit set
        each time we empty a queue we add 1 minute
        reutrn num min
        if set is not empty by the time the queue is empty (after adding new rotten queue)
        then it's not possible to reach those coords and we return false


        using bfs ensures we reach each fruit optimally (shortest path alg)
        */
        set<pair<int,int>> fresh_fruits;
        deque<pair<int,int>> curr_rotten;
        for(int i =0; i < grid.size(); i++){
            for(int j =0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    fresh_fruits.insert({i,j});
                }
                if(grid[i][j] == 2){
                    curr_rotten.push_back({i, j});
                }
            }
        }
        if(fresh_fruits.size() == 0){
            return 0;
        }
        return bfs(grid, fresh_fruits, curr_rotten);
    }
};
