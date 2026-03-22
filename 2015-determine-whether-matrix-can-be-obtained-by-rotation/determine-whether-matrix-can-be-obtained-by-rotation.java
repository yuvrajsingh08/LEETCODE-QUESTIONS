class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        
        boolean isPos = true;
        int n = mat.length;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j]) {
                    isPos = false;
                    break;
                }
            }
        }
        if(isPos) return true;
        for(int k=0; k<3; k++) {
            // turn 90*
            for(int i=0; i<n; i++) {
                for(int j=0; j<i; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }

            // reverse by colum
            for(int i=0; i<n; i++) {
                int s = 0;
                int r = n-1;
                while(s < r) {
                    int temp = mat[i][s];
                    mat[i][s] = mat[i][r];
                    mat[i][r] = temp;
                    s++;
                    r--;
                }
            }

            boolean isTemp = true;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        isTemp = false;
                        break;
                    }
                }
            }

            isPos |= isTemp;
            if(isPos) return true;
        }
        return false;
    }
}