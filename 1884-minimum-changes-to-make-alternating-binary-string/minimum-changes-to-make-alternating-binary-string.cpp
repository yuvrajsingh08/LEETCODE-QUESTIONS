class Solution {
public:
    int minOperations(string s) {
        // lets start with 
        // s[0] -> 0

        int cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(i%2 == 0) {
                if(s[i] == '1') cnt++;
            } else {
                if(s[i] == '0') cnt++;
            }
        }
        int ans = cnt;
        cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(i%2 == 0) {
                if(s[i] == '0') cnt++;
            } else {
                if(s[i] == '1') cnt++;
            }
        }

        return min(ans, cnt);
    }
};