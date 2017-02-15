package p1107.p20170215;

import java.util.Arrays;

/**
 * Created by dezhonger on 2017/2/15.
 * 一些加热的东西。一些房子，求最小的半径，使所有房子都能被找到。
 * 排序+二分
 */
public class Leetcode475 {

	public boolean f(int[] houses, int[] heaters, int ra) {
//		System.out.println("redius = " + ra);
		int index = 0;
		int len = houses.length;
		for(int i = 0; i < heaters.length; i++) {
			int o = heaters[i];
			int l = o - ra;
			int r = o + ra;
//			System.out.println(i + " " + l + " " + r);
			while(index < len) {
				int h = houses[index];
				if(l <= h && h <= r) {
					index++;
				} else {
					break;
				}
			}
			if(index == len) break;
		}
		return index == len;
	}


	public int findRadius(int[] houses, int[] heaters) {
		Arrays.sort(houses);
		Arrays.sort(heaters);
		int len1 = houses.length;
		int L = 0;
		int R = houses[len1 - 1] - houses[0];
		R = Math.max(R, Math.abs(heaters[0] - houses[len1 - 1]));
		R = Math.max(R, Math.abs(heaters[0] - houses[0]));
//		System.out.println(L + " " + R);
		while(L < R) {
			int mid = (L + R) / 2;
			if(f(houses, heaters, mid)) {
				R = mid;
			} else {
				L = mid + 1;
			}
		}
//		System.out.println(L);
		return L;
	}

	public static void main(String[] args) {
		new Leetcode475().findRadius(new int[]{1, 2, 3}, new int[]{2});
		new Leetcode475().findRadius(new int[]{1, 2, 3, 4}, new int[]{1, 4});
		new Leetcode475().findRadius(new int[]{1}, new int[]{1, 2, 3, 4});
	}
}
