// User function Template for C++
 bool cmp(pair<int , pair<int,int>> a , pair<int,pair<int,int>> b){
        return a.second.second < b.second.second;
    }

class Solution {
  public:
   
    vector<int> maxMeetings(int N, vector<int> &start, vector<int> &end) {
         vector<pair<int,pair<int,int>>> v;
         vector<int>ans;
        for(int i = 0 ; i < start.size() ; i++){
            v.push_back({i+1 , {start[i] , end[i]}});
        }
        //sort by end time
        sort(v.begin() , v.end() , cmp);
        //aage ka process
        int ansEnd =-1;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i].second.first > ansEnd){
                ans.push_back(v[i].first );
                ansEnd = v[i].second.second;
            }
            
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};