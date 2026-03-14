class Solution {
public:
    void solve(vector<char>& a, string& ans, string sample, int len, int& pos, int k) {
        if(len == 0) {
            if(pos == k) {
                ans = sample;
            } else if(pos > k) return;
            pos++;
            return;
        }

        for(int i=0; i<3; i++) {
            int c = a[i];
            if(sample.length() == 0 || sample[sample.length()-1] != c) {
                sample.push_back(c);
                solve(a, ans, sample, len-1, pos, k);
                sample.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        vector<char> a = {'a', 'b', 'c'};
        string ans = "";
        string sample = "";
        int pos = 1;
        solve(a,ans,sample,n,pos,k);
        return ans;
    }
};