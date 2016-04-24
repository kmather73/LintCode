class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        if(size <= originalStr.size())
            return originalStr;
            
        std::string left = "";
        
        for(int i=0; i < size - originalStr.size(); ++i)
            left += padChar;
            
        return left + originalStr;
    }
};
