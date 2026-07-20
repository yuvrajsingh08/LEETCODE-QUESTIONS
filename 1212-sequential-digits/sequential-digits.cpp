class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n = 0;
        int temp = low;
        while(temp != 0) {
            temp /= 10;
            n++;
        }
        int st = 0;
        int curr = 0;
        for(int i=0; i<n; i++) {
            st = st*10 + (curr+1);
            curr += 1;
        }
        string a(n,'1');
        int s = stoi(a); 
        while(st < low) {
            if(st%10 == 9) {
                // need to increase digit
                n+=1;
                st = 0;
                curr = 0;
                for(int i=0; i<n; i++) {
                    st = st*10 + (curr+1);
                    curr += 1;
                }
                s = s*10 + 1;
                // check 
            }
            else st = st + (s);
        }
        if(st == 0 || st > high) return {};
        vector<int> ans;
        while(st <= high) {
            ans.push_back(st);
            if(st%10 == 9) {
                // need to increase digit
                n+=1;
                st = 0;
                curr = 0;
                for(int i=0; i<n; i++) {
                    st = st*10 + (curr+1);
                    curr += 1;
                }
                 s = s*10 + 1;
                // check 
                if(st > high) break;
            }
            else st = st + (s);
        }
        return ans;
    }
};