class Solution {
public:
    void letters(string digits,int index,string& path,vector<string>& ans,unordered_map<char,string>& phoneMap)
    {
        if (index==digits.size())
        {
            ans.push_back(path);
            return;
        }
       for (char ch:phoneMap[digits[index]])
        {
            path.push_back(ch);
            letters(digits,index+1,path,ans,phoneMap); //to choose next chr to replace the digit chr
            path.pop_back(); //case where ch is not the chosen character
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char,string> phoneMap={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
            };
        vector<string> ans;
        string path;
        letters(digits,0,path,ans,phoneMap);
        return ans;
    }
};