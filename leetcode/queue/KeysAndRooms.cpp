class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        //First room doesn't have any keys
        if(rooms[0].size() == 0){
            return false;
        }
        
        vector<bool> dp(rooms.size() , false);
        queue<int> roomQ;
        dp[0] = true;
        
        for(int i= 0 ; i<rooms[0].size() ; i++){
            roomQ.push(rooms[0][i]);
        }
        
        while(!roomQ.empty()){
            int currRoomKey = roomQ.front();
            roomQ.pop();
            dp[currRoomKey] = true;
            for(int i= 0 ; i<rooms[currRoomKey].size() ; i++){
                if(!dp[rooms[currRoomKey][i]]){
                    roomQ.push(rooms[currRoomKey][i]);
                }
            }            
        }
        
        for(int i=0 ; i< dp.size() ; i++){
            if(!dp[i]){
               return false; 
            }
        }

        return true;
    }
};
