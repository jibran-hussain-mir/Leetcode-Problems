class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int count=0;
        int ansIndex=0;
        
        while(i < chars.size())
        {
            int j=i+1;
            while(j < chars.size() && chars[i]==chars[j])
            {
                j++;
            }
            count=j-i;
            if(count==1)
            {
                chars[ansIndex++]=chars[i];
            }
            if(count > 1)
            {
                string newCount=to_string(count);
                chars[ansIndex++]=chars[i];
                for(char ch:newCount)
                {
                    chars[ansIndex++]=ch;
                }
            }
            count=0;
            i=j;
        }
        return ansIndex;
    }
};