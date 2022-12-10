class Solution {
public:
    string removeDuplicates(string s) {
//         int flag=1;
//         string str,temp;
//         temp=s;
//         while(flag == 1)
//         {
            
//             str=temp;
//             temp="";
//             int i=0;
//             while(str[i] != '\0')
//             {
                
//                 if(str[i] == str[i+1])
//                 {
//                     i=i+2;
//                     flag=0;
//                 }
//                 else
//                 {
//                     temp.push_back(str[i]);
//                     i++;
//                 }
//             }
//             if(flag == 1)
//                 return temp;
//             flag=1;
//         }
//         return s;
        
        stack<char> st;
        string res="";
        int i=0;
        while(s[i] != '\0')
        {
            if(!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else
                st.push(s[i]);
            i++;
        }
        while(!st.empty())
        {
           res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};