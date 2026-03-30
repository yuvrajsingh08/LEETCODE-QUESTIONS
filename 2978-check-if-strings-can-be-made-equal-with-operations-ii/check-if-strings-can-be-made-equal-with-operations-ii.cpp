class Solution {
public:
    bool checkStrings(string s1, string s2) {
    // if(s1.size() == 1) return s1 == s2;
    int n=s1.length();
    string t1;  //even
    string t2;
    string c1;  //odd
    string c2;
    int m=0;
     while(m<n){
       if(m%2==0){
          t1.push_back(s1[m]);
          t2.push_back(s2[m]);
       }
       else{ 
          c1.push_back(s1[m]);
          c2.push_back(s2[m]);
       }
       m++;
     }
     sort(t1.begin(),t1.end());
     sort(t2.begin(),t2.end());
     sort(c1.begin(),c1.end());
     sort(c2.begin(),c2.end());
    
    if(t1==t2 && c1==c2)
      return true;
    else
      return false;
    }
};