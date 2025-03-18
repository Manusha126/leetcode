class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]=='(') || (s[i]=='{') || (s[i]=='['))
            {
                st.push(s[i]);
            }
            else
            {
                // when there is no opening bracket stack will be empty
                if(st.empty())
                {
                    return false;
                }
                char brac=st.top();
            
                if((brac=='(' && s[i]==')')|| (brac=='{' && s[i]=='}') || (brac=='[' && s[i]==']'))
                {
                        st.pop();
                }
                else
                {
                    return false;
                }

            }

        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }

        
    }
};