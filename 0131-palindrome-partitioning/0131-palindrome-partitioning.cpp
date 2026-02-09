class Solution {
public:
    bool ispalin(string part){
        string s2=part;
        reverse(s2.begin(),s2.end());
        return s2==part;
    }
    void gap(string s, vector<string> &partition, vector<vector<string>> &ans){
        if (s.size()==0){
            ans.push_back(partition);
            return;
        }
        for (int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);

            if (ispalin(part)){
                partition.push_back(part);
                gap(s.substr(i+1),partition,ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> ans;

        gap(s,partition,ans);
        return ans;
        
    }
};