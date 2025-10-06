class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());
        int platformneeded = 1;
        int maxi = 1;
        int arrindex = 1;
        int depindex = 0;
        while(arrindex < n && depindex < n){
            if(arr[arrindex] <= dep[depindex]){
                platformneeded++;
                maxi = max(maxi , platformneeded);
                arrindex++;
            }else{
                platformneeded--;
                depindex++;
                
            }
        }
        return maxi;
    }
};
