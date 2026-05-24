class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
       int n = arr.size();
       vector<bool> vis(n, false);
       queue<int> q;
       q.push(start);
       vis[start] = true;
       while(!q.empty()) {
        int front = q.front(); q.pop();
        int currVal = arr[front];
        if(currVal == 0) return true;
        int op = front - currVal;
        if(op >= 0 && op < arr.size() && !vis[op]) {
            if(arr[op] == 0) return true;
            vis[op] = true;
            q.push(op);
        }
        op = front + currVal;
        if(op >= 0 && op < arr.size() && !vis[op]) {
            if(arr[op] == 0) return true;
            vis[op] = true;
            q.push(op);
        }
       }
       return false;
    }
};