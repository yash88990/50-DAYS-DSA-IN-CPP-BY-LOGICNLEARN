class Solution {
  public:
    bool check(int d, vector<int>&arr, int k){
        int ans=0;
        for(int &i:arr){
            ans+=((i+d-1)/d);
            if(ans>k) return false;
        }
        return true;
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int maxi=arr[0];
        for(int i=1; i<n; i++) maxi=max(maxi, arr[i]);
        
        int lo=1, hi=maxi, ans=-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid, arr, k)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        
        return ans;
    }
};
