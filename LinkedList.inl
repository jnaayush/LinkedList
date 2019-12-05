#include "LinkedList.h"
#include <functional>
using namespace std;

template <typename K,typename V, typename H>
List<K,V,H>::List (size_t capacity){
    head = NULL;
    this->capacity = capacity;
}

template <typename K,typename V, typename H>
List<K,V,H>::~List(){
    Node<K,V> *cur;
    while (head != NULL){
        cur = head;
        head = cur->next;
        delete(cur);
    }
    
}

template <typename K,typename V, typename H>
size_t List<K,V,H>::customHash(K key){
    H hashKey;
    size_t h1 = hashKey(key);
    return h1 % capacity;
}

template <typename K,typename V, typename H>
int List<K,V,H>::remove(K key){
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

template <typename K,typename V, typename H>
int List<K,V,H>::insert(K key, V value){
    customHash(key);
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

template <typename K,typename V, typename H>
void List<K,V,H>::printList(){
    Node<K,V> *cur = head;
    while (cur != NULL){
        cout << cur->key << ":" << cur->value << " -> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}

template <typename K,typename V, typename H>
Node<K,V> * List<K,V,H>::get(K key){
    Node<K,V> *cur = head;
    while (cur != NULL && cur->key != key){
        cur = cur->next;
    }
    return cur;
}
