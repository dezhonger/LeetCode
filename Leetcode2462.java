class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        long ans = 0;
        int len = costs.length;
        if (candidates * 2 >= len) {
            Arrays.sort(costs);
            for (int i = 0; i < k; i++)
                ans += costs[i];
            return ans;
        }

        PriorityQueue<Integer> q = new PriorityQueue<>((o1, o2) -> {
            return costs[o1] != costs[o2] ?
                    costs[o1] - costs[o2] :
                    o1 - o2;
        });

        for (int i = 0; i < candidates; i++) {
            q.offer(i);
            q.offer(len - 1 - i);
        }

        for (int l = candidates, r = len - 1 - candidates; k > 0; k--) {
            Integer poll = q.poll();
            ans += costs[poll];
            if (l <= r)
                q.offer(poll < l ? l++ : r--);
        }

        return ans;
    }
}
