class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int maxSum) {
        int count = 1, currentSum = 0;
        for (int num : arr) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
                if (count > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(arr, k, mid)) {
                answer = mid;
                right = mid - 1; // try to minimize max sum
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
