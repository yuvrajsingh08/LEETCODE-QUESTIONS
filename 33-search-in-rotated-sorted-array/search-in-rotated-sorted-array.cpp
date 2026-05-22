class Solution {
public:
    int mid(vector<int>& nums,int n){
      int s=0;
        int e=n-1;
        while(s<e){
        int m=s+(e-s)/2;
        if(nums[m]>=nums[0]){
            s=m+1;
        }
        else{
           e=m;
        }
        }
        return s;
    }
    int binary(vector<int>& nums,int s,int e,int key){
     while(s<=e){
    int m=s+(e-s)/2;
      if(nums[m]==key){
          return m;
      }
     else if(nums[m]<key){
       s=m+1;
      }
      else{
        e=m-1;
      }
     }
    return -1;
    }
    int search(vector<int>& nums, int target) {
    int n=nums.size();
    int pivot=mid(nums,n);
    if(nums[pivot]<=target && nums[n-1]>=target){
     return binary(nums,pivot,n-1,target);
    }
    else{
    return binary(nums,0,pivot-1,target);
    }
    }
};