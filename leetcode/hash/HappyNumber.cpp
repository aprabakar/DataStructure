// HashSet
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        long curr_number = n;
        while(true){
            count++;
            
            set.insert(curr_number);
            long new_number = 0;
            while(curr_number > 0){
                new_number += (curr_number % 10) * (curr_number % 10);
                curr_number /= 10;
            }
            
            if(new_number == 1){
                break;
            }
            
            if(set.count(new_number) > 0){
                return false;
            }
            curr_number = new_number;
        }
        return true;
    }
};

//Floyd's Cycle-Finding Algorithm
class Solution {
public:
     int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        while (fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }
};
