//leet -> https://leetcode.com/problems/open-the-lock/
class Solution {
    string nextKey(string key , int pos, bool isForward){
        vector<int> list(4);
        string returnString;
        
        for(int i=0;i<key.length();i++){
           list[i] = key[i] - '0';
        }
        
        if(isForward){
           list[pos] = (list[pos] == 9) ? 0 : (list[pos]+1); 
        }else{
           list[pos] = (list[pos] == 0) ? 9 : (list[pos]-1);
        }
        for(int i=0;i<4;i++){
           returnString += to_string(list[i]);
        }
        return returnString;
    }
    
public:
    int openLock(vector<string>& deadends, string target) {
        
        map<string,int> deadEndMap;
        map<string,int> visitedLockkeyMap;
        int noOfTurns = INT_MAX;
        string startKey = "0000";
        int count = 0;
        
        //Look up for deadEndkeys
        for(int i= 0; i< deadends.size() ; i++){
            deadEndMap[deadends[i]] = 1;
        }
        
        // Edge case
        if(deadEndMap.find(startKey) != deadEndMap.end()){
            return -1;
        }

        //start the queue with start key
        deque<string> bfsQueueForLock;
        bfsQueueForLock.push_back(startKey);
        visitedLockkeyMap["0000"] = count;
        while(!bfsQueueForLock.empty()){
            string currKey = bfsQueueForLock.front();
            count = visitedLockkeyMap[currKey];
            
            if(currKey == target){
                noOfTurns = visitedLockkeyMap[currKey];
                break;
            }
           
            bfsQueueForLock.pop_front();
    
            // from this key , there are 4 forward possible and 4 reverse paths
            // for Ex: 0000 -> [0001,0010,0100,1000] [9000,0900,0090,0009] since one rotation at one                  lock at a time
            
            int code = 0;
            bool isForward = true;
            bool firstTime = true;
            
            for (int i= 0 ; i< 8; i++){
                
                //Reverse flows
                if( i == 4){
                    code = 0;
                    isForward = false;
                }
                
                string next_key = nextKey(currKey , code , isForward);
            
                if(deadEndMap.find(next_key) == deadEndMap.end() && 
                   visitedLockkeyMap.find(next_key) == visitedLockkeyMap.end()){
                   if(firstTime || isForward){
                        visitedLockkeyMap[next_key] = count+1;
                   }else{
                        visitedLockkeyMap[next_key] = count; 
                   }
                   
                   // Return as soon as you find the target
                   if(next_key == target){
                        noOfTurns = visitedLockkeyMap[next_key];
                        return noOfTurns;
                   }
                    
                    bfsQueueForLock.push_back(next_key);
                }
                code +=1;
            }   
            firstTime = false;
        }
        
        return (noOfTurns != INT_MAX) ? noOfTurns : -1;
        
    }
};
