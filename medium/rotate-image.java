// Without allocating new matrix
class Solution {
    public void rotate(int[][] matrix) {
        // inverse matrix (row -> column, column -> row)
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i; j < matrix[i].length; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // swap column (left -> right, right -> left)
        for (int i = 0; i < matrix.length; i++) {
            int left = 0;
            int right = matrix.length - 1;
            while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    }
}