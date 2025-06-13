class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        return isSorted(arr, 0);
    }

  private:
    bool isSorted(vector<int>& arr, int i) {
        if (i >= arr.size() - 1) return true;              // base case
        if (arr[i] > arr[i + 1]) return false;             // not sorted
        return isSorted(arr, i + 1);                       // check next
    }
};
