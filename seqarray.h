#ifndef SEQARRAY_H
#define SEQARRAY_H
#include "Array.h"
#include "Exception.h"

namespace DTLib{
template <typename T>
class SeqArray: public Array<T>{
  protected:
   T* m_array;
   int m_length;
public:
   bool append(const T &e){
       return insert(m_length. e);
   }
   bool insert(int i, const T& e){
       bool ret = ((i >= 0) && ( i <= m_length));
       ret = ret && (m_length < capacity());
       if(ret){
           for(int p = m_length - 1; p >= 0; p--){
               m_array[p+1] = m_array[p];
           }
           m_array[i] = e;
           m_length++;
       }
       return ret;
   }
   bool remove(int i){
       bool ret = ((0 <= i)&&(i < m_length));
       if(ret){
           for(int p = i; p < m_length-1; p++){
               m_array[p] = m_array[p+1];
           }
           m_length--;
       }
       return ret;

   }
   bool set(int i, const T& e){
       bool ret = ((0 <= i)&&(i < m_length));
       if(ret){
           m_array[i] = e;
       }
       return ret;
   }

   bool get(int i, T& e) const {
       bool ret = ((0 <= i)&&(i < m_length));
       if(ret){
           e = m_array[i];
       }
       return ret;
   }
   int length() const{
       return m_length;
   }
   void clear(){
       m_length = 0;
   }

   T& operator[] (int i){
       if((0 <= i) && (i < m_length)){
           return m_array[i];
       }else{
           THROW_EXCEPTION(InvalidParameterException, "Parameter i is invalid");
       }
   }
   T operator[] (int i) const{
       return (const_cast<SeqArray<T>&>(*this))[i];
   }
   virtual int capacity() const = 0;
};
}
#endif // SEQARRAY_H
