package p1107.p20170214;

/**
 * Created by dezhonger on 2017/2/14.
 */
public class Leetcode400 {

	public long[] calWeishu(long[] cnt, long t) {
		long weishu = -1;
		long[] ans = new long[2];
		for(int i = 1; i < 20; i++) {
			t -= cnt[i];
			if(t <= 0) {
				weishu = i;
				t += cnt[i];
				ans[0] = weishu; ans[1] = t;
				return ans;
			}
		}
		return null;
	}

	public int findNthDigit(int n) {
		long[] cnt = new long[20];
		cnt[1] = 9L;
		//各位数分别占了多少位，比如1位数9位，两位数90个，占了180位
		for(int i = 2; i < 20; i++) cnt[i] = cnt[i - 1] * 10;
		for(int i = 2; i < 20; i++) cnt[i] = cnt[i] * i;
		//用于计算n位数中第k个数的辅助数组
		long[] q = new long[20];
		q[1] = 0; q[2] = 9;
		for(int i = 3; i < 20; i++) q[i] = q[i - 1] * 10L + 9;
		//几位数
		long[] temp = calWeishu(cnt, n);
		long weishu = temp[0];
		long t = temp[1];
		long p = (t + weishu - 1) / weishu; //第几个数
		int ans = (int) (q[(int)weishu] + p); //那个数是?
		long mod = t % weishu == 0 ? weishu - 1 : t % weishu - 1; //那个数的第几位
		System.out.println((ans+"").toString().charAt((int)mod));
		return (ans+"").toString().charAt((int)mod) - '0';
	}

}
