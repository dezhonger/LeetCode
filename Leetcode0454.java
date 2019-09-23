

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2017/2/23.
 */
public class Leetcode0454 {
	public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
		Map<Integer, Integer> m1 = new HashMap<>();
		Map<Integer, Integer> m2 = new HashMap<>();
		int len = A.length;
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				int sum = A[i] + B[j];
				if(m1.containsKey(sum)) {
					m1.put(sum, m1.get(sum) + 1);
				} else {
					m1.put(sum, 1);
				}
			}
		}

		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				int sum = C[i] + D[j];
				if(m2.containsKey(sum)) {
					m2.put(sum, m2.get(sum) + 1);
				} else {
					m2.put(sum, 1);
				}
			}
		}

		int ans = 0;
		for(Map.Entry<Integer, Integer> entry : m1.entrySet()) {
			int key = entry.getKey();
			int value = entry.getValue();
			if(m2.containsKey(-key)) {
				int value2 = m2.get(-key);
				ans += value * value2;
			}

		}
		return ans;
	}
}
