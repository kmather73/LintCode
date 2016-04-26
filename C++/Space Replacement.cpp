class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        std::string str;
        for(int i = 0; i < length; ++i ){
            if(string[i] != ' ')
                str += string[i];
            else 
                str += "%20";
        }
        
        for(int i = 0; i < str.size(); ++i)
            string[i] = str[i];
        
        return str.size();
    }
};