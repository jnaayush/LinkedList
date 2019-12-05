#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define UPDATE_VALUE_SUCCESS 1
#define REMOVE_SUCCESS 2
#define INSERT_SUCCESS 3
#define KEY_NOT_FOUND 0


using namespace std;
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

#endif
