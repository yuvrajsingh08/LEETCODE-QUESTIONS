class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 20; i >= 0; --i) {
            int mask = result | ((1 << i) - 1);
            bool possible = true;
            for (const auto& row : grid) {
                bool row_ok = false;
                for (int val : row) {
                    if ((val | mask) == mask) {
                        row_ok = true;
                        break;
                    }
                }
                if (!row_ok) {
                    possible = false;
                    break;
                }
            }  
            if (!possible) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};