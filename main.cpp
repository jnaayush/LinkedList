// List - key and value
#include<string>
#include<assert.h>
#include<iostream>
#define UPDATE_VALUE_SUCCESS 1
#define REMOVE_SUCCESS 1
#define INSERT_SUCCESS 1
#define KEY_NOT_FOUND 0


using namespace std;

class UnitTest;
template <typename K,typename V> class List;

template <typename K,typename V>
class Node
{
    friend class List<K,V>;
    
private:
    K key;
    V value;
    Node<K,V> *next;
public:
    Node (K key, V value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    
    K getKey(){
        return this->key;
    }
    
    V getValue(){
        return this->value;
    }
};

template <typename K,typename V>
class List
{
private:
    Node<K,V> *head;
public:
    List();
    ~List();
    int insert(K key, V value);
    int remove(K key);
    void printList ();
    Node<K,V> * get(K key);
};

template <typename K,typename V>
List<K,V>::List (){
    head = NULL;
}

template <typename K,typename V>
List<K,V>::~List(){
    Node<K,V> *cur;
    while (head != NULL){
        cur = head;
        head = cur->next;
        delete(cur);
    }
    
}

template <typename K,typename V>
int List<K,V>::remove(K key){
    Node<K,V> *cur = head;
    Node<K,V> *prev = NULL;
    while (cur != NULL && cur->key != key){
        prev = cur;
        cur = cur->next;
    }
    if(cur == NULL)
        return KEY_NOT_FOUND;
    if(prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;
    delete (cur);
    return REMOVE_SUCCESS;
}

template <typename K,typename V>
int List<K,V>::insert (K key, V value){
    Node<K,V> *cur = head;
    while (cur != NULL){
        if (cur->key == key){
            cur->value = value;
            return UPDATE_VALUE_SUCCESS;
        }
        cur = cur->next;
    }
    cur = new Node<K,V>(key, value);
    cur->next = head;
    head = cur;
    return INSERT_SUCCESS;
}

template <typename K,typename V>
void List<K,V>::printList (){
    Node<K,V> *cur = head;
    while (cur != NULL){
        cout << cur->key << ":" << cur->value << " -> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}

template <typename K,typename V>
Node<K,V> * List<K,V>::get(K key){
    Node<K,V> *cur = head;
    while (cur != NULL && cur->key != key){
        cur = cur->next;
    }
    return cur;
}


class UnitTest{
public:
    void static TestInsertRemoveFunction(){
        try{
            cout <<"\nTesting insert function with List<char,char> \n";
            List<char,char> *l = new List<char,char>();
            // Deleting non existant key
            assert(KEY_NOT_FOUND == l->remove('a'));
            for(char c = 'a'; c <= 'z'; c++){
                assert(KEY_NOT_FOUND == l->remove(c));
            }
            
            //Inserting key,values
            for(char c = 'a'; c <= 'z'; c++){
                assert(INSERT_SUCCESS == l->insert(c,c));
                Node<char,char> *n = l->get(c);
                assert(c == n->getKey());
                assert(c == n->getValue());
            }
            
            //removing in same order
            for(char c = 'a'; c <= 'z'; c++){
                assert(REMOVE_SUCCESS == l->remove(c));
                assert(NULL == l->get(c));
            }
            delete(l);
            cout << "Insert and Remove Test Passed\n";
        } catch (...){
            cout << "Insert Test Failed\n";
        }
    }
    
    void static TestKeyValue(){
        try{
            cout<< "\nTesting key, value and next assignment\n";
            Node<string,string> *sNode = new Node<string,string>("MATHWORKS","SIMULINK");
            
            //Test Key assignment
            assert(sNode->getKey() == "MATHWORKS");
            
            //Test Value assignment
            assert(sNode->getValue() == "SIMULINK");
            
            cout << "Passed node assignment test\n";
        } catch(...){
            cout << "Node assignment failed\n";
        }
    }
    
    
    void static TestNodeUpdationOnInsert(){
        try{
            cout << "\nTesting Node update\n";
            List<int,int> *lI = new List<int,int>();
            assert(INSERT_SUCCESS == lI->insert(1,10));
            assert(INSERT_SUCCESS == lI->insert(2,20));
            assert(INSERT_SUCCESS == lI->insert(3,30));
            
            assert(UPDATE_VALUE_SUCCESS == lI->insert(1,100));
            assert(100 == lI->get(1)->getValue());
            assert(UPDATE_VALUE_SUCCESS == lI->insert(2,200));
            assert(200 == lI->get(2)->getValue());
            assert(UPDATE_VALUE_SUCCESS == lI->insert(3,300));
            assert(300 == lI->get(3)->getValue());
            cout << "Node update Passed\n";
        } catch(...) {
            cout << "Node update failed\n";
        }
    }
    
};

int main (){
    UnitTest::TestInsertRemoveFunction();
    UnitTest::TestKeyValue();
    UnitTest::TestNodeUpdationOnInsert();
    return 0;
    
}
