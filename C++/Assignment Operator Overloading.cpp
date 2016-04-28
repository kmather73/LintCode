class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if ( this != &object ) {
            char* temp = nullptr;
            
            //Copy 
            if ( object.m_pData != nullptr ){
                int len = strlen( object.m_pData );
                temp = new char[len];
                strcpy( temp, object.m_pData );
            }
            
            //Free
            if( this->m_pData != nullptr )
                delete[] this->m_pData;
            
            //Move
            this->m_pData = temp;
            
        }
        
        return *this;
    }
};