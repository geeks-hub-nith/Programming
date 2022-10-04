class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> p;
    for(int i = 0;i<nums.size();i++){
        if(p.find(nums[i])!= p.end()) return true;
        p.insert(nums[i]);
    }        
        return false;
    }    
};
