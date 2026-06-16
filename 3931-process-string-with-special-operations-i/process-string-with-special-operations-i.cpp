class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i=0; i<s.size(); i++) {
            string temp = result;
            if(s[i] == '*') {
                if(temp.size() > 0) temp.pop_back();
            } else if(s[i] == '#') {
                if(temp.size() > 0)
                    temp = temp + temp;
            } else if(s[i] == '%') {
                if(temp.size() > 0)
                    reverse(temp.begin(), temp.end());
            } else {
                temp.push_back(s[i]);
            }
            result = temp;
        }
        // cout<<result<<" ";
        return result;
    }
};