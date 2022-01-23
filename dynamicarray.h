#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "Array.h"
#include "Exception.h"
namespace DTLib {
template <typename T>
class DynamicArray : public Array<T>{
protected:
    int m_length;
    T* copy(T* array, int len, int newLen){
        T* ret = new T[newLen];
        if(ret != NULL){
            int size = (len < newLen) ? len: newLen;
            for(int i = 0; i < size; i++){
                ret[i] = array[i];
            }
        }
        return ret;
    }
    void update(T* array, int len){
        if(array != NULL){
            T* temp = this->m_array;
            this->m_array = array;
            this->m_length = len;
            delete[] temp;
        }else{
            THROW_EXCEPTION(NoEnoughMemoryException, "No enough memeory to update DynamicArray Object");
        }

    }
    void init(T* array, int length){
        if( array != NULL){
            this->m_array = array;
            this->m_length = length;
        }else{
            THROW_EXCEPTION(NoEnoughMemoryException, "No enough memeory to create DynamicArray Object");
        }
    }
public:
    DynamicArray(int length = 0){
        init(new T[length], length);
//        this->m_array = new T[length];
//        if(this->m_array != NULL){
//            this->m_length = length;
//        }else{
//            THROW_EXCEPTION(NoEnoughMemoryException, "No enough memeory to create DynamicArray Object");
//        }
    }
    DynamicArray(const DynamicArray<T>& obj){
        init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
//        this->m_array = new T[obj.m_length];
//        if(this->m_array != NULL){
//            this->m_length = obj.m_length;
//            for(int i = 0; i < obj.m_length; i++){
//                this->m_array[i] = obj.m_array[i];
//            }
//        }else{
//            THROW_EXCEPTION(NoEnoughMemoryException, "No enough memeory to create DynamicArray Object");
//        }
    }
    DynamicArray<T>& operator= (const DynamicArray<T>& obj){
        update(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
//        if(this != &obj){
//            T* array = new T[obj.m_length];
//            if(array != NULL){
//                for(int i=0; i < obj.m_length;i++){
//                    array[i] = obj.m_array[i];
//                }
//                T* temp = this->m_array;
//                this->m_length = obj.m_length;
//                delete[] temp;
//            }else{
//                 THROW_EXCEPTION(NoEnoughMemoryException, "No enough memeory to create copy object");
//            }

//        }
    }
    int length() const{
        return this->m_length;
    }
    void resize(int length){
        if(length != this->m_length){
            update(copy(this->m_array, m_length, length),length);
//            T* array = new T[length];
//            if(array != NULL){
//                int size = (length < m_length) ? length : m_length;
//                for(int i = 0; i < size; i++){
//                    array[i] = this->m_array[i];
//                }
//                T* temp = this->m_array;
//                this->m_length = length;
//                this->m_array = array;
//                delete[] temp;
//            }else{
//                THROW_EXCEPTION(NoEnoughMemoryException,  "No enough memory to resize Array");
//            }
        }
    }
    ~DynamicArray(){
        delete[] this->m_array;
    }
};

}
#endif // DYNAMICARRAY_H
