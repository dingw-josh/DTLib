#include <iostream>
#include "exception.h"
#include "smartpointer.h"
#include "Object.h"
#include "List.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "StaticLinkedlist.h"
#include "SmartPointer.h"
#include "SharedPointer.h"
#include "CircleList.h"
using namespace std;
using namespace DTLib;

void Josephus(int num){
    CircleList<int> list;
    for(int i = 0; i < num; i++ ){
        list.append(i+1);
    }

    list.move(0,2);
    while(list.length() > 0){
        list.next();
        cout << list.current() << endl;
        list.remove(list.find(list.current()));
    }
    cout << "end" << endl;
//    //cout << list.length() << endl;
//    for(int i = 0; i < list.length(); i++){
//        cout << list.get(i) << endl;
//    }
}
class Test : public Object{
public:
    int value;
    Test():value(0){
       cout << "creating Test Object" <<endl;
    }
//    bool operator ==(const Test& obj){
//        if(i == obj.i){
//            return true;
//        }
//        return false;
//    }
    ~Test(){
        cout << "deleting Test Object" << endl;
    }
};

int main()
{
//    LinkedList<int> list;
//    for(int i = 0; i < 5; i++){
//        list.insert(0,i);
//    }
//    list.insert(0,6);
//    //cout << list.length() << endl;
//    for(list.move(0); !list.end(); list.next()){
//        cout << list.current() << endl;
//        //cout << ":" << endl;
//    }
//    SharedPointer<Test> sp = new Test();
//    cout << (*sp).value << endl;
//    SharedPointer<Test> spn = sp;
//    spn->value = 100;
//    cout << (*spn).value << endl;
//    cout << (*sp).value << endl;
//    cout << (sp == spn) << endl;
    Josephus(41);
    return 0;
}
