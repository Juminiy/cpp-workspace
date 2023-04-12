#include <ostream>

namespace chisato{
    class cls_0 {
        private:
            int int32_0;
        public:
            cls_0(int int32_) :int32_0 (int32_){}
            cls_0(){
                cls_0(0);   
            }      
            int getInt32_0(){
                return this->int32_0;
            }
            int setInt32_0(int int32_1){
                int int32_0_old = this->int32_0;
                return this->int32_0 == int32_1 ? int32_1 : int32_0_old;  
            }
            friend std::ostream& operator << (std::ostream &os, cls_0 item){
                os << "[" << item.int32_0 << "]" << std::endl;
                return os;
            }
    };
}
