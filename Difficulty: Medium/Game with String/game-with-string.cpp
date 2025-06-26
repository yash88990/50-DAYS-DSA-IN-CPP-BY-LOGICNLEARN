class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
         // code here
        // unordered_map<char,int>mp;
        // for(char ch:s)
        // {
        //     mp[ch]++;
        // }
        // vector<int>v;
        // for(auto it:mp)
        // {
        //     v.push_back(it.second);
        // }
        // sort(v.begin(),v.end(),greater<int>());
        // while(k>0)
        // {
        //     for(int i=0;i<v.size();i++)
        //     {
        //         if(v[i]>1)
        //         {
        //             v[i]--;
        //             k--;
        //         }
        //     }
        //     sort(v.begin(),v.end());
        // }
        // int ans=0;
        // for(int freq:v)
        // {
        //     ans+=freq*freq;
        // }
        // return ans;
        unordered_map<char,int>mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        priority_queue<int>pq;
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        while(k>0 && !pq.empty())
        {
            int top=pq.top();
            pq.pop();
            k--;
            top--;
            if(top>0)
            {
                pq.push(top);
            }
        }
        int ans=0;
        while(!pq.empty())
        {
            int freq=pq.top();
            pq.pop();
            ans+=freq*freq;
        }
        return ans;
        
    }
};