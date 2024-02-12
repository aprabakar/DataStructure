int val = stoi(tokens[i]);

vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

bool isNotValid(int i, int j, int m, int n){
    return (i <0 || j<0 || i>=m || j>=n);
}

//copy from set to vector:
set<vector<int>> ans;
vector<vector<int>> result(ans.begin(), ans.end());
//second way
for (it = myset.begin(); it != myset.end(); ++it) {
    result.push_back(*it);
}

// Tuples
stack<tuple<int,int, int>> st;
vector<int> ans(temperatures.size());

for(int i=0; i < temperatures.size() ; i++){
    if(st.empty()){
        st.push(make_tuple(temperatures[i],i,1)); 
    }else{
        
        int count = 0, rot = 0;
        while(!st.empty() && get<0>(st.top()) < temperatures[i]){
            count += get<2>(st.top());
            ans[get<1>(st.top())] = count;
            ++rot;
            st.pop();
        }
        st.push(make_tuple(temperatures[i],i, max(rot,1)));
    }
}

return ans;

class Car{
public:
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    int pos;
    int speed;
};

// sort based on field
vector<Car> cars;
int N = position.size();
for(int i = 0; i<N; i++){
    cars.emplace_back(position.at(i), speed.at(i));
}

sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
    return a.pos<b.pos;
});

//binary search:
int insertIndex = 0;
beginSearch = lower_bound(products.begin();, products.end(), prefix);
insertIndex = beginSearch - products.begin();

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

