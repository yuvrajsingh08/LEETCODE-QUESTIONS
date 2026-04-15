class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;
        for(int i=0; i<n; i++) {
            if(words[i] == target) {
                // means ok
                cout<<i<<" "<<startIndex<<endl;
                ans = min({ans,abs(i-startIndex), abs(n - abs(i-startIndex))});
            }
        }
        if(ans == n) return -1;
        return ans;
    }
};