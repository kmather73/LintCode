class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.size() == 0) return true;
        
        
        int n = s.size();
        int left = 0;
        int length = 0;
        string subStr = "";
        stack< pair<int,int> > myStack;
        
        
        while(left < n){
            
            do{
                ++length;
                subStr = s.substr(left, length);
            } while(dict.count(subStr) == 0 && left + length <= n);
        
        
            if( left + length <= n ){
                myStack.push( pair<int,int>(left, length) );
                left += length;
                length = 0;
                
            } else if( myStack.size() > 0 ){
                pair<int,int> lastPair = myStack.top();
                myStack.pop();
                
                left = lastPair.first;
                length = lastPair.second;
                
            } else {
                left += length;
            }
        }
        
        return dict.count(subStr);
    }
};
