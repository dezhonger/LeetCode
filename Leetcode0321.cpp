#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//6 4
//6 4 5
//
//6 6 4 5 4
//
//6 5
//6 5 4
//
//6 6 5 5 4


class Solution {
public:
    vector<int> findK(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        int s = nums.size() - k + 1;
        int index = 0, cur = -1, xiabiao = -1;
        for(int i = 1; i <= k; i++) {
            while(index < s) {
                if(nums[index] > cur) {
                    cur = nums[index];
                    xiabiao = index;
                }
                index++;
            }
            ans.push_back(cur);
            cur = -1;
            s++;
            index = xiabiao + 1;
        }
//        for(int i = 0; i < ans.size(); i++) cout << ans[i];
        return ans;
    }
    void print(vector<int>& ans) {
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";cout << endl;
    }
    vector<int> hebing(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) return nums2;
        if(nums2.size() == 0) return nums1;
        vector<int> ans;
        int p1 = 0, p2 = 0, len1 = nums1.size(), len2 = nums2.size();
        while(p1 <  len1 && p2 < len2) {
            if(nums1[p1] < nums2[p2]) {
                ans.push_back(nums2[p2]);
                p2++;
            }
            else if(nums1[p1] > nums2[p2]) {
                ans.push_back(nums1[p1]);
                p1++;
            }
            else {
                int k1 = p1, k2 = p2;
                while(k1 < len1 && k2 < len2 && nums1[k1] == nums2[k2]) {
                    k1++;
                    k2++;
                }
                cout << k1 <<k2 << endl;
                if(k1 == len1 && k2 != len2) {ans.push_back(nums2[p2]); p2++;}
                else if(k2 == len2 && k1 != len1) {ans.push_back(nums1[p1]); p1++;}
                else if(k2 == len2 && k1 == len1) {ans.push_back(nums1[p1]); p1++;} //¶¼¿ÉÒÔ
                else if(nums1[k1] > nums2[k2]) {ans.push_back(nums1[p1]); p1++;}
                else {ans.push_back(nums2[p2]); p2++;}
            }
        }
        while(p1 < len1) { ans.push_back(nums1[p1++]);}
        while(p2 < len2) { ans.push_back(nums2[p2++]);}
        return ans;

    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> ans;
//        vector<int> ans1 = findK(nums1, 2);
//        vector<int> ans2 = findK(nums2, 3);
        for(int i = 0; i <= k; i++) {
            if(i > len1 || k - i > len2) continue;
//            cout << i << k - i << endl;
            vector<int> ans1 = findK(nums1, i);
            vector<int> ans2 = findK(nums2, k - i);
            vector<int> ans3 = hebing(ans1, ans2);
//            for(int i = 0; i < ans3.size(); i++) {
//                cout << ans3[i] << " ";
//            }
//            cout << endl;
            ans = max(ans, ans3);
        }
        return ans;
    }
};

int main()
{
    Solution s;
//    vector<int> v1{3, 4, 6, 5};
//    vector<int> v2{9, 1, 2, 5, 8, 3};
////    s.findK(v1, 2);
////    s.findK(v2, 3);
//    vector<int> ans = s.maxNumber(v1, v2, 5);
//    for(int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << " ";
//    }
//    cout << endl;
//[2,5,6,4,4,0]
//[7,3,8,0,6,5,7,6,2]
//15

    vector<int> v3{0};
    vector<int> v4{0,6,5,7,6,2};
//    s.findK(v3, 2);
//    s.findK(v4, 3);
//    vector<int> ans2 = s.maxNumber(v3, v4, 5);
//    for(int i = 0; i < ans2.size(); i++) {
//        cout << ans2[i] << " ";
//    }
//    cout << endl;
       vector<int> ans =  s.maxNumber(v3, v4, 7);
       for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
    return 0;
}
