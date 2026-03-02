class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> a;
        int n = grid.size();
        for(int i=0; i<n; i++) {
            // go from last
            int cnt = 0;
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] != 0) {
                    break;
                }
                cnt++;
            }
            a.push_back(cnt);
        }
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && a[j] < needed) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(a[j], a[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;

        return 0;
    }
};