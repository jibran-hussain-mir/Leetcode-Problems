class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st="";
        
        string str0=strs[0];
        
         for(int i=1;i<strs.size();i++)
            {
                int flag=0;
                int size=str0.size()<strs[i].size()?str0.size():strs[i].size();
                string newstring=strs[i];
                for(int j=0;j<size;j++)
                {
                    
                    if(str0[j] == newstring[j])
                    {
                        st=st+str0[j];
                        flag=1;
                    }
                    else break;
                    if(flag!=1)
                        return "";
                }
             str0=st;
             st="";
            }
            return str0;
    }
};