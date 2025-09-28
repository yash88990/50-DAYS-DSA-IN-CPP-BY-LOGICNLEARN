
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size() , l = 0 , maxlen = 0 , startindex = 0;
        multiset<int> window;
        for(int i = 0 ; i < n ; i++){
            window.insert(arr[i]);
            while(*window.rbegin() - *window.begin() > x){
                window.erase(window.find(arr[l]));
                l++;
            }
            if(i - l + 1 > maxlen){
                maxlen =  i - l + 1;
                startindex = l;
            }
        }
        return vector<int>(arr.begin() + startindex , arr.begin() + startindex + maxlen);
    }
};

