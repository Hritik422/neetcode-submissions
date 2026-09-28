class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>>pq;
        vector<vector<int>>ans;
        for(auto it:points){
            pq.push({sqrt(pow(it[0],2) + pow(it[1],2)), it[0], it[1]});
        }

        while(!pq.empty() && k>0){
            vector<double> c = pq.top();
            pq.pop();
            ans.push_back({c[1], c[2]});
            k--;
        }
        return ans;
    }
};
