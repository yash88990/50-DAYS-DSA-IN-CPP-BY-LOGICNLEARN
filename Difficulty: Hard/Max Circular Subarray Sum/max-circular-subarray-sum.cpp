class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
         int n=arr.size();
        vector<int>temp(n,0);
        int curr=0, maxi=0;
        for(int i=n-1;i>=0;i--){
            curr+=arr[i];
            maxi=max(maxi, curr);
            temp[i]=maxi;
        }
        
        int ans=arr[0], pre=0;
        curr=0;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            ans=max(ans, curr);
            curr=max(0, curr);
            
            ans=max(ans, pre+temp[i]);
            pre+=arr[i];
        }
        if(ans == 0)return -1 ;
        else
        return ans;
    }
};