package p1107.p20170215;

/**
 * Created by dezhonger on 2017/2/15.
 * 先判断第一列和第一行有没有零。
 * 然后用第一列和第一行来辅助记录数据.
 */
public class Leetcode073 {
	public void setZeroes(int[][] matrix) {
		int m = matrix.length;
		int n = matrix[0].length;

		int col = 1;
		int row = 1;
		for(int i = 0; i < m; i++) {
			if(matrix[i][0] == 0) {
				col = 0;
			}
		}

		for(int j = 0; j < n; j++) {
			if(matrix[0][j] == 0) {
				row = 0;
			}
		}



		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				int x = matrix[i][j];
				if(x == 0) {
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}

		for(int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if(matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		for(int i = 1; i < m; i++) {
			if(matrix[i][0] == 0) {
				for(int j = 1; j < n; j++) matrix[i][j] = 0;
			}
		}

		for(int j = 1; j < n; j++) {
			if(matrix[0][j] == 0) {
				for(int i = 1; i < m; i++) matrix[i][j] = 0;
			}
		}


		if(col == 0) {
			for(int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}

		if(row == 0) {
			for(int j = 0; j < n; j++) {
				matrix[0][j] = 0;
			}
		}
	}
}
