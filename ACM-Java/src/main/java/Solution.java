class Solution {
    public long countSubarrays(int[] nums, int k) {
        int mx = nums[0], cnt = 0;
        for (int x : nums) mx = Math.max(x, mx);
        for (int x : nums) {
            if (x == mx) cnt++;
        }



    }
}
