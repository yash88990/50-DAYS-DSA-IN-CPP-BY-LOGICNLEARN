// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int count=0,c=0,res=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k){
                count++;
                c++;
                res=max(res,c);
            }
            else{c=0;}
        }
        return count-res;
    }
};
