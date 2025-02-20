class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> Pacific(m, vector<bool>(n, false));
        vector<vector<bool>> Atlantic(m, vector<bool>(n, false));

        // left and right bound connecting to the ocean
        for(int i=0; i<m; i++){
            dfs(heights, Pacific, i, 0);
            dfs(heights, Atlantic, i, n-1);
        }

        // top and bottom bound connecting to the ocean
        for(int j=0; j<n; j++){
            dfs(heights, Pacific, 0, j);
            dfs(heights, Atlantic, m-1, j);
        }

        // find the node which can achieve both ocean
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(Pacific[i][j] && Atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j){
        int m=heights.size();
        int n=heights[0].size();

        ocean[i][j]=true;

        // Go Left
        if(j-1>=0 && heights[i][j]<=heights[i][j-1] && !ocean[i][j-1]){
            dfs(heights, ocean, i, j-1);
        }

        // Go Right
        if(j+1<n && heights[i][j]<=heights[i][j+1] && !ocean[i][j+1]){
            dfs(heights, ocean, i, j+1);
        }

        // Go Up
        if(i-1>=0 && heights[i][j]<=heights[i-1][j] && !ocean[i-1][j]){
            dfs(heights, ocean, i-1, j);
        }

        // Go Down
        if(i+1<m && heights[i][j]<=heights[i+1][j] && !ocean[i+1][j]){
            dfs(heights, ocean, i+1, j);
        }
    }
};