#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H
#include "LinkedList.h"

namespace DTLib {
template<typename T, int N>
class StaticLinkedList : public LinkedList<T>{
protected:
    typedef typename LinkedList<T>::Node Node;
    struct SNode : public Node
    {
        void* operator new(unsigned int size, void* loc){
            (void)size;
            return loc;
        }

   };
    unsigned char m_space[sizeof(SNode) * N];
    int m_used[N];

    Node* create(){
        SNode* ret = NULL;
        for(int i = 0; i < N; i++){
            if( !m_used[i]){
                ret = reinterpret_cast<SNode*>(m_space) + i;
                ret = new(ret) SNode();
                m_used[i] = 1;
                break;
            }
        }
        return ret;
    }
    void destroy(Node* pn){
        SNode* space = reinterpret_cast<SNode*>(m_space);
        SNode* psn = dynamic_cast<SNode*>(pn);
        for(int i = 0; i < N; i++){
            if(pn == (space + i)){
                m_used[i] = 0;
                psn->~SNode();
            break;
            }
        }
    }
public:
    StaticLinkedList(){
        for(int i = 0; i < N; i++){
            m_used[i] = 0;
        }
    }
    int capacity(){
        return N;
    }
    ~StaticLinkedList(){
        this->clear();
    }
}
;

}
#endif // STATICLINKEDLIST_H
