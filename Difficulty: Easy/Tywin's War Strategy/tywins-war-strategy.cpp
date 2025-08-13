class Solution {
  public:
    int helper(vector<int> arr, int k){
        int n = arr.size();
        for(int i=0;i<n;i++){
            arr[i]%=k;
            if(arr[i]!=0)
              arr[i] = k-arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        int req = n/2;
        if(n&1)
          req++;
        
        int ans = 0;
        for(int i=0;i<req;i++){
            ans += arr[i];
        }
        
        return ans;
    }
  
    int minSoldiers(vector<int>& arr, int k) {
     
        return helper(arr, k);
    }
};