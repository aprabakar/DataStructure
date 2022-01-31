//Josephus Problem
class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; ++i){
            res = (res + k) % i;
           // cout << "res = "<<res<<endl;
        }
            
        return res + 1;
    }
};

// 1,2,3,4,5 k=2. We know that the winner is #3, so let's check how winner's index was changing from round to round:

// 1, (2), 3, 4, 5 - we start with player_1, player_2 got eliminated.
// 3, (4), 5, 1. - we start with player_3, player_4 got eliminated.
// 5, (1), 3 - we start with player_5, player_1 got eliminated.
// 3, (5) - we start with player_3, player_5 got eliminated.
// 3 - found the winner

// Now let's look at the same example but bottom up and let's keep track of the winner's index by using the formula (prev + k)%number_of_current_players_in_game
// 3 - index 0
// 3, 5 - index = (0 + 2)%2 = 0. (prev = 0, k = 2, currently playing 2)
// 5, 1, 3. - index = (0 + 2) %3 = 2 (prev = 0, k = 2, currently playing 3)
// 3, 4, 5, 1 - index = (2 + 2)%4 = 0 (prev = 2, k = 2, currently playing 4)
// 1, 2, 3, 4, 5. - index = (0 + 2)%5 = 2 (prev = 0, k = 2, currently playing 5) It is 0-based, so we've correctly identified the winner!

// That's how the recurrence worked! We've found the winner by knowing his previous location.
// Hope this helps!
