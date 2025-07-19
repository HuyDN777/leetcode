class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mark;
        for(int i = 0; i < arr.size(); i++) 
            mark[arr[i]]++;
        for(auto it = --mark.end(); true; --it) {
            if(it->first == it->second) return it->first;
            if(it == mark.begin()) break;
        }

        return -1;
    }
};