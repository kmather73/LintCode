class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        std::set<char> leftParens {'(', '[', '{'};
        
        std::unordered_map<char, char> leftToRight;
        leftToRight.insert( std::make_pair('(', ')') );
        leftToRight.insert( std::make_pair('[', ']') );
        leftToRight.insert( std::make_pair('{', '}') );

        
        std::stack<char> myStack;
        for (char c : s) {
            if ( leftParens.count(c) ) {
                myStack.push(c);
            } else if( !myStack.size()){
                return false;    
            } else {
                char left = myStack.top(); myStack.pop();
                if(leftToRight[left] != c) 
                    return false;
            }
        }
        return myStack.empty();
    }
};