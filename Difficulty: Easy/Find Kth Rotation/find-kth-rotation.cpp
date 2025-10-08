class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int s = 0 , e = arr.size()-1;
        while(s < e){
            int m = s + ( e - s )/2;
            if(arr[m] < arr[e])e = m;
            else s = m + 1 ;
        }
        return e;
    }
};
