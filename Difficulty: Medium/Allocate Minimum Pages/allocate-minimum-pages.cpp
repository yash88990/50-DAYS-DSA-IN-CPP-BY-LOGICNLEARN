class Solution {
  public:
   
bool isFeasible(const vector<int>& arr, int k, int maxPages) {
    int students = 1; // At least one student is needed
    int pagesSum = 0;

    for (int pages : arr) {
        if (pages > maxPages) return false; // Single book exceeds maxPages
        if (pagesSum + pages > maxPages) {
            students++;     // Assign to next student
            pagesSum = pages;
            if (students > k) return false; // More students required than available
        } else {
            pagesSum += pages;
        }
    }
    return true;
}

int findPages(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1; // Not enough books for each student

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(arr, k, mid)) {
            result = mid;  // Update result to the current feasible value
            high = mid - 1; // Try for a smaller maximum
        } else {
            low = mid + 1; // Increase the maximum allowed pages
        }
    }

    return result;
}

};
