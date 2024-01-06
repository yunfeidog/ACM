package content.leetcode_375;

public class Main01 {
    class Solution {
        public int countTestedDevices(int[] batteryPercentages) {
            int cnt = 0;
            for (int i = 0; i < batteryPercentages.length; i++) {
                if (batteryPercentages[i] - cnt > 0) {
                    cnt++;
                }
            }
            return cnt;
        }
    }
}
