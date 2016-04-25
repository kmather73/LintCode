class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        std::vector<std::string> words;
        int size = 0;
        
        for(std::string word: dictionary){
            if ( size < word.size() ){
                words.clear();
                words.push_back( word );
                size = word.size();
                
            } else if ( size == word.size())
                words.push_back( word );
        }
        
        return words;
    }
};
