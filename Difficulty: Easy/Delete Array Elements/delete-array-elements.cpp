class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        // complete the function
        vector<int>res;
        int n = arr.size();
        res.resize(n);
        int prev = -1;
        for(int i = 0; i < n ; i++){
            while(prev > -1 && res[prev] < arr[i] && k > 0){
                k--;
                prev--;
            }
            prev++;
            res[prev] = arr[i];
        }
        res.resize(prev + 1);
        return res;
    }
};