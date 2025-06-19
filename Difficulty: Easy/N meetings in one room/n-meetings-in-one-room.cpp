
 bool cmp(pair<int,int> a , pair<int,int> b){
        return a.second < b.second;
    }

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
   
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        //for storing value as pair form
        vector<pair<int,int>> v;
        for(int i = 0 ; i < start.size() ; i++){
            pair<int,int> p = make_pair(start[i] , end[i]);
            v.push_back(p);
        }
        //sort by end time
        sort(v.begin() , v.end() , cmp);
        //aage ka process
        int count = 1;
        int ansEnd = v[0].second;
        for(int i = 1 ; i < v.size() ; i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
            
        }
        return count;
    }
};