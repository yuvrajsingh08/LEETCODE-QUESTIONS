class Solution {
    public int mirrorDistance(int n) {
        String s = String.valueOf(n); 
        String reversed = new StringBuilder(s).reverse().toString();
        int y = Integer.parseInt(reversed);
        return Math.abs(n - y); 
    }
}