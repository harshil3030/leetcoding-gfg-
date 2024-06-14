/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,int> idWithImportance;
        vector<int> joints;
        map<int, vector<int>> currjoints;
        int len = employees.size();
        for(int i = 0; i < len; i++) {
            idWithImportance[employees[i] -> id] = employees[i] -> importance;
            currjoints[employees[i] -> id] = employees[i] -> subordinates;
        }
        
        joints.push_back(id);
        queue<int> q;
        q.push(id);
        
        while (!q.empty()) {
            id = q.front();
            q.pop();
            for(int i = 0; i < currjoints[id].size(); i++) {
                joints.push_back(currjoints[id][i]);
                q.push(currjoints[id][i]);
            }
            
        }
        
        int ans = 0;
        for(int i = 0; i < joints.size(); i++) {
            ans += idWithImportance[joints[i]];
        } 
        return ans;
    }
    
};