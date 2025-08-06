class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if(parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }
    
    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // Step 1: Sort all edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        DisjointSet ds(V);
        int mst_weight = 0;
        
        // Step 2: Traverse sorted edges
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(ds.find(u) != ds.find(v)) {
                ds.unionByRank(u, v);
                mst_weight += wt;
            }
        }
        
        return mst_weight;
    }
};
