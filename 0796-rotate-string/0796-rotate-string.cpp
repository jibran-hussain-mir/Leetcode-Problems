class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        bool result=false;
        for(int i=0;i<=s.size()-2;i++){
            int j=0;
            char start=s[0];
            while(j < s.size()-1){
                s[j]=s[j+1];
                j++;
            }
            s[s.size()-1]=start;
            if(s == goal) result=true;
            if(result == true) break;
        }
        if(result == true) return true;
        return false;
    }
};