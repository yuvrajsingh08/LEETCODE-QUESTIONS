class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp,copy,curr;
        for(auto c: t) {
            mp[c]++;
            copy[c]++;
        }

        int i=0;
        int j=0;
        int l=-1;
        int r=-1;
        int n=s.size();
        int len = n+1;
        while(j<n) {
            curr[s[j]]++;
            if(copy.count(s[j])) {
                copy[s[j]]--;
                
                if(copy[s[j]] == 0) copy.erase(s[j]);
            }

            while(i<=j && copy.size() == 0) {
                //means valid
                // cout<<j<<" "<<i<<" "<<len<<endl;
                if(j-i+1 < len) {
                    r = j;
                    l = i;
                    len = j-i+1;
                }

                if(mp.count(s[i]) && curr[s[i]] <= mp[s[i]]) {
                    copy[s[i]]++;
                }
                curr[s[i]]--;
                i++;
            }
            // cout<<endl;
            j++;
        }
        if(l == -1) return "";
        return s.substr(l, r-l+1); 
    }
};