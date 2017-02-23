package p1107.p20170223.le;

/**
 * Created by dezhonger on 2017/2/23.
 * 按照字符出现的频率逆序排列单词
 * 做法：
 * 把出现次数频率相同的字符组成一个字符串，再连接它们
 * https://leetcode.com/problems/sort-characters-by-frequency/?tab=Solutions
 */
public class Leetcode451 {
	public String frequencySort(String s) {
		int len = s.length();
		if(len < 3) {
			return s;
		}
		int[] map = new int[256];
		int maxFre = 0;
		for(char c : s.toCharArray()) {
			map[c]++;
			maxFre = Math.max(maxFre, map[c]);
		}
		String[] buckets = new String[maxFre + 1];

		for(int i = 0; i < 256; i++) {
			String str = buckets[map[i]]; //枚举每个字符出现的字数，把相同的组合在一起
			if(map[i] > 0) {
				buckets[map[i]] = str == null ? "" + (char)i : (str + (char)i);
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i = maxFre; i >= 0; i--) {
			if(buckets[i] != null) {
				for(char c : buckets[i].toCharArray()) {
					for(int k = 0; k < i; k++) {
						sb.append(c);
					}
				}
			}
		}
		return sb.toString();
	}
}
