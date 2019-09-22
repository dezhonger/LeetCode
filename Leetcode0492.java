

/**
 * Created by dezhonger on 2017/2/14.
 * 给一个面积，求矩形，长宽差最小。
 */
public class Leetcode492 {
	public int[] constructRectangle(int area) {
		int maxL = (int)Math.sqrt(area);
		int[] ans = new int[2];
		for(int i = 1; i <= maxL; i++) {
			if(area % i == 0) {
				ans[0] = area / i;
				ans[1] = i;
			}
		}
		return ans;
	}
}
