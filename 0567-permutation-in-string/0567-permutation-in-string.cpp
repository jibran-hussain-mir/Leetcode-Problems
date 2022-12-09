class Solution {
public:
    bool check(int count1[],int count2[])
    {
        for(int i=0;i<26;i++)
        {
            if(count1[i] != count2[i])
                return 0;
        }
        return 1;
    }
    
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            int index=s1[i]- 'a';
            count1[index]++;
        }
        
        int i=0;
        int windowSize=s1.length();
        int count2[26]={0};
        while(i < windowSize && i < s2.length())
        {
            int index=s2[i]-'a';
            count2[index]++;
            i++;
            
            if(check(count1,count2))
                return 1;
        }
        
        while(i<s2.length())
        {
            int index=s2[i] - 'a';
            count2[index]++;
            
           int oldCharIndex=i-windowSize;
            index=s2[oldCharIndex]-'a';
            count2[index]--; 
            
            i++;
            
            if(check(count1,count2))
                return 1;
        }
        return 0;
    }
};