class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int start = 0, end = 0;
        map<char, int> position;
        
        while(end < s.size()){
            ans = max(ans, end-start+1);
            position[s[end]] = end;
            // cout << start << " " << end << endl;
            // for(auto it = position.begin(); it != position.end(); it++){
            //     cout << it->first << " " << it->second << " | ";
            // }
            // cout << endl;
            if(end+1 < s.size()){
                if(position.find(s[end+1]) == position.end()){
                    end++;
                }else{
                    int newStart = position[s[end+1]]+1;
                    for(int i = start; i < newStart; i++){
                        position.erase(s[i]);
                    }
                    start = newStart;
                    end++;
                    // position.clear();
                }
            }else{
                break;
            }
        }
        
        return ans;
    }
};

//Brute Force
//TLE
//894 / 987 test cases passed.
//time: O(N^3), space: O(min(size_of_string, size_of_charset))
class Solution {
public:
    bool allUnique(string& s, int start, int end){
        set<char> chars;
        
        for(int i = start; i <= end; i++){
            auto res = chars.insert(s[i]);
            if(res.second == false) return false;
        }
        
        return true;
    };
    
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(allUnique(s, i, j)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
