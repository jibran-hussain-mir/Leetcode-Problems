class Solution {
public:
    bool isValid(char ch)
    {
         if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch >= '0' && ch <= '9'))
            {
             return true;
            }
         return false;
    }
    
    char toLowerCase(char ch)
        {
            if((ch>='a' && ch<='z') || (ch>= '0' && ch <= '9'))
                return ch;
            else 
                return ch-'A'+'a';
        }
    
    bool checkPalindrome(string s)
    {
        int i=0;
        int j=s.length()-1;
        
        while(i <= j)
        {
            if(s[i] == s[j])
                {
                    i++;
                    j--;
                }
            else
                {
                    return false;
                }
        }
        return true;            
    }
    
    bool isPalindrome(string s) 
    {
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(isValid(s[i]))
                {
                    str.push_back(toLowerCase(s[i]));
                }
        }
        cout<<str;
        return checkPalindrome(str);
        
        
    }
};