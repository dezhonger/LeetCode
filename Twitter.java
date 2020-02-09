package com.dezhonger.y2020.m02.d10;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

/**
 * Created by dezhonger on 2020/02/10
 *
 * @author dezhonger
 * @since 2020/02/10
 * Leetcode0355
 */
public class Twitter {

    Map<Integer, Set<Integer>> follow;
    Map<Integer, PriorityQueue<Post>> post;
    int t = 0;

    /**
     * Initialize your data structure here.
     */
    public Twitter() {
        follow = new HashMap<>();
        post = new HashMap<>();
    }

    /**
     * Compose a new tweet.
     */
    public void postTweet(int userId, int tweetId) {
        PriorityQueue<Post> s = post.getOrDefault(userId, new PriorityQueue<>());
        if (s.size() == 10) s.poll();
        s.add(new Post(tweetId, t++));
        post.put(userId, s);
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        Set<Integer> us = new HashSet<>();
        us.add(userId);
        us.addAll(follow.getOrDefault(userId, new HashSet<>()));

        PriorityQueue<Post> res = new PriorityQueue<>();
        PriorityQueue<Post> result = new PriorityQueue<>();
        for (int u : us) {
            PriorityQueue<Post> pq = post.getOrDefault(u, new PriorityQueue<>());
            res.addAll(pq);
            while (pq.size() > 10) pq.poll();
        }
        for (int i = 0; i < 10 && !res.isEmpty(); i++) {
            result.add(res.poll());
        }
        List<Integer> k = new ArrayList<>();
        while (!result.isEmpty()) {
            k.add(result.poll().tweetId);
        }
        Collections.reverse(k);
        return k;
    }

    /**
     * Follower follows a followee. If the operation is invalid, it should be a no-op.
     */
    public void follow(int followerId, int followeeId) {
        Set<Integer> s = follow.getOrDefault(followerId, new HashSet<>());
        s.add(followeeId);
        follow.put(followerId, s);
    }

    /**
     * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
     */
    public void unfollow(int followerId, int followeeId) {
        Set<Integer> s = follow.getOrDefault(followerId, new HashSet<>());
        s.remove(followeeId);
        follow.put(followerId, s);

    }

    class Post implements Comparable<Post> {
        int tweetId;
        int time;

        public Post(int tweetId, int time) {
            this.tweetId = tweetId;
            this.time = time;
        }

        @Override
        public int compareTo(Post o) {
            return Integer.compare(time, o.time);
        }
    }
}
