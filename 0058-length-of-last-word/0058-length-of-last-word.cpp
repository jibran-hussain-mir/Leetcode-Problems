class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] != ' ' && i == 0 || s[i] != ' ' && s[i-1] == ' ')
                return count+1;
            
           if(s[i]!= ' '){
                count++;
            }
        }
        return count;
    }
};