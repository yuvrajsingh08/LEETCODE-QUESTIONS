class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> a;
        int n = s.size();
        int one = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') one++;
            else {
                // check if one is not zero
                if(one != 0) {
                    a.push_back(one);
                    one = 0;
                }
                a.push_back(0);
            }
        }
        if(one != 0) {
            a.push_back(one);
        }
        // for(auto c: a) {
        //     cout<<c<<" ";
        // } cout<<endl;
        n = a.size();
        int i=0,j=0;
        int ans = 0;
        int maxPos = 0;
        int cntZero = 0;
        bool isPos = false;
        int howMany = 0;
        while(j<n && a[j] != 0) {
            // means one
            ans += a[j];
            j++; i++;
        }
        while(j<n) {
            if(a[j] != 0) {
                ans += a[j];
                // means it is extra okay
                howMany++;
            } else {
                // zero h
                cntZero++;
                if(howMany != 0) isPos = true;
                while(howMany > 1 && i < j) {
                    if(a[i] != 0) howMany--;
                    else cntZero--;
                    i++;
                    
                }
                if(isPos && howMany == 1) {
                    // means only one segment
                    maxPos = max(maxPos, j-i);
                }
            }
            j++;
        }
        return ans+maxPos;

    }
};