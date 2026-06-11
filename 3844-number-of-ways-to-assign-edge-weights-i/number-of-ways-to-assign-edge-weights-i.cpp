class Solution {
public:
    const long long mod = 1e9 + 7;

    int modPow(long long a, long long b) {
        int res = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // remember that 1 is the root node and at max-distance is node x
        // so count edge distance btw them then 
        int maxDepth = 0;
        for(auto &c: edges) {
            sort(c.begin(), c.end());
        }
        sort(edges.begin(), edges.end());
        unordered_map<int,int> mp;
        for(auto c: edges) {
            int u = c[0];
            int v = c[1];
            int x = 0;
            if(u == 1) {
                mp[v] = 1;
                x = mp[v];
            } else if(v == 1) {
                mp[u] = 1;
                x = mp[u];
            } else {
                if(mp.count(u)) {
                    mp[v] = mp[u]+1;
                    x = mp[v];
                } else {
                    mp[u] = mp[v]+1;
                    x = mp[u];
                }
            }
            maxDepth = max(maxDepth, x);
        }
        if (maxDepth == 0) return 0; 
        return modPow(2, maxDepth - 1);
    }
};