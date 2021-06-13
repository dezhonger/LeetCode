package p1107.p463;

/**
 * Created by dezhonger on 2017/2/14.
 * 求周长
 * 计算每个箱子周围有x个箱子，则提供的周长为4 - x
 */
public class Leetcode463 {

	public int check(int[][] a, int b, int c) {
		int m = a.length;
		int n = a[0].length;
		if(b < 0 || b >= m || c < 0 || c >= n) return 0;
		return a[b][c] == 1 ? 1 : 0;
	}

	public int solve(int[][] a, int b, int c) {
		int ans = 0;
		ans += check(a, b - 1, c);
		ans += check(a, b + 1, c);
		ans += check(a, b, c - 1);
		ans += check(a, b, c + 1);
		return ans;
	}


	public int islandPerimeter(int[][] grid) {
		int ans = 0;
		int m = grid.length;
		int n = grid[0].length;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == 1) {
					ans += 4 - solve(grid, i, j);
				}

			}
		}
		return ans;
	}
}
