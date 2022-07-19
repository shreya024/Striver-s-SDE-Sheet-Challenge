bool isValidParenthesis(string expression)
{
    stack<char> s;
    
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else{
            if(s.empty())
                return false;
            else if(ch==')' && s.top()=='('){
                    s.pop();
            }
            else if(ch=='}' && s.top()=='{'){
                    s.pop();
            }
            else if(ch==']' && s.top()=='['){
                    s.pop();
            }
            else
                return false;
            
        }
    }
    if(s.empty())
        return true;
    return false;
}
