class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        DisjoinSet=n;

        // init value
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=1;
        }

        for(auto node: edges){
            int p=find(node[0]);
            int q=find(node[1]);

            if(p!=q){
                union_rank(p,q);
                DisjoinSet--;
            }
            else{
                // has a cycle
                return false;
            }
        }

        return (DisjoinSet==1)?true:false;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int DisjoinSet;

    int find(int node){
        if(node==parent[node])
            return node;
        
        return parent[node]=find(parent[node]);
    }
    
    void union_rank(int p, int q){
        if(rank[p]>rank[q]){
            parent[q]=p;
        }
        else if(rank[q]>rank[p]){
            parent[p]=q;
        }
        else{
            parent[q]=p;
            rank[p]++;
        }
    }
};