package com.dezhonger.le;

/**
 * Created by dezhonger on 2019/12/06
 *
 * @author dezhonger
 * @since 2019/12/06
 */
public class Leetcode0721 {
    public int maxProfit(int[] prices, int fee) {
        int[] have = new int[prices.length];
        int[] notHave = new int[prices.length];
        have[0] = -prices[0];
        notHave[0] = 0;
        for (int i = 1; i < prices.length; i++) {
            have[i] = Math.max(notHave[i - 1] - prices[i], have[i-1]);
            notHave[i] = Math.max(notHave[i - 1], have[i - 1] - fee + prices[i]);
        }
        return notHave[prices.length - 1];
    }
}
