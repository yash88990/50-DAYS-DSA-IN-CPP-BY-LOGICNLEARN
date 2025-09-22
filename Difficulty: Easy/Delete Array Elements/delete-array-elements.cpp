class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        // complete the function
        vector<int> res;
        int n = arr.size();
    res.resize(n);
    int ptr = -1;
    for (int i = 0; i < n; i++) {
        while (ptr >-1 &&  res[ptr] < arr[i] && k > 0) {
            ptr--;
            k--;
        }
        
        ptr++;
        res[ptr] = arr[i];
    }
    res.resize(ptr + 1);
    
    return res;
    }
};