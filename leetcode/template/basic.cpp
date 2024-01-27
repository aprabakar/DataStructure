int val = stoi(tokens[i]);

vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

bool isNotValid(int i, int j, int m, int n){
    return (i <0 || j<0 || i>=m || j>=n);
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
