class Solution {
    public boolean check(int[] nums) {
        int cnt = 0;
        for(int i=1; i<nums.length; i++) {
            if(nums[i-1] > nums[i]) cnt++; // means here it rotates
        }

        // if not rotate then also // means cnt can be increase only one time
        if(nums[0] < nums[nums.length-1]) cnt++;
        return cnt <= 1;
    }
}