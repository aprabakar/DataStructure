HASH TABLE on C++ is unordered_map<> and the implementation of map on C++ is map<>.

In unordered_map<> keys are not sorted and insertion of particular key takes O(1).
In map<> keys are in sorted order and the insertion of particular key will take O(logn).

unordered_map<int, int> q;

//1st way:
q.insert(make_pair(3, 7));

//2nd way:
q[3]=7;

//3rd way:
q.emplace(3, 7);

if(q.find(3) == q.end()){
   cout<<"This key does not exists"<<endl; 
}

//1st way:
q.erase(ourkey);   // deletion by key

//2nd way:
q.erase(z);      // deletion by iterator

for(auto z=q.begin();z!=q.end();z++){   //traversing from beginning till end
     cout<<"key is "<<z->first<<" and the value is "<<z->second<<endl; 
}

for(auto &it: mp){
    ans.push_back(it.second);
}

for(auto z=q.rbegin();z!=q.rend();z++){   //traversing from end till beginning
     cout<<"key is "<<z->first<<" and the value is "<<z->second<<endl; 
}

// set implementation

unordered_set<int> set;
unordered_set<int> result;
for(int i=0 ;i < nums1.size(); i++){
    set.insert(nums1[i]);
}

for(int i=0 ;i < nums2.size(); i++){
    if(set.count(nums2[i]) > 0){
        result.insert(nums2[i]);
    }
}

return vector<int>(result.begin() , result.end()); 




// https://leetcode.com/problems/4sum/description/?envType=list&envId=504wrexe

int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
return output;



// Problems:

https://leetcode.com/list/?selectedList=p307wzce
https://leetcode.com/problems/majority-element/submissions/1157557127/
https://leetcode.com/problems/contiguous-array/?envType=list&envId=p307wzce
https://leetcode.com/problems/longest-palindrome/submissions/1157463566/?envType=list&envId=p307wzce
https://leetcode.com/problems/4sum-ii/
https://leetcode.com/problems/k-diff-pairs-in-an-array/
https://leetcode.com/problems/contiguous-array/description/
https://leetcode.com/problems/longest-palindrome/description/
https://leetcode.com/problems/longest-substring-without-repeating-characters/
https://leetcode.com/problems/4sum/
https://leetcode.com/problems/two-sum/description/
