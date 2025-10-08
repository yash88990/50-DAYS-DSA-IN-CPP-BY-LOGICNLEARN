// User function Template for C++

class Solution {
  public:
    bool canplacedcows(vector<int> &stalls, int k , int mindist){
        int count = 1;
        int lastplaced = stalls[0];
        for(int i = 1 ; i < stalls.size() ; i++){
            if(stalls[i] - lastplaced >= mindist){
                count++;
                lastplaced = stalls[i];
            }
            if(count == k)return true;
        }
        return false;
        
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin() , stalls.end());
        int low = 1 , high = stalls.back() - stalls.front();
        int result = 0;
        
        while(low <= high){
            int mid = low + ( high - low) / 2;
            if(canplacedcows(stalls , k , mid)){
                result = mid ;
                low = mid + 1;
            }else{
                high = mid - 1;
                
            }
        }
        return result;
    }
};