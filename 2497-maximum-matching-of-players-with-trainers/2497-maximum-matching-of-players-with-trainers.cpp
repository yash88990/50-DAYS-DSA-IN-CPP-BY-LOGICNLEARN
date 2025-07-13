class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());
        int count = 0;
        int startp = 0 , startt = 0 , endp = players.size()-1 , endt = trainers.size()-1;
        while(startp <= endp && startt <= endt){
            if(players[startp] <= trainers[startt]){
                count++;
                startp++;
                startt++;
            }else if(players[startp] > trainers[startt])startt++;
            
        }
        return count;

    }
};