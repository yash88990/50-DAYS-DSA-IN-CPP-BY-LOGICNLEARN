class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>merge;
        for(int num : a)merge.push_back(num);
        for(int num : b)merge.push_back(num);
        sort(merge.begin() , merge.end());
        vector<int>unique;
        unique.push_back(merge[0]);
        for(int i = 1 ; i < merge.size() ; i++){
            if(merge[i] != merge[i-1]){
                unique.push_back(merge[i]);
            }
        }
        return unique;
    }
};