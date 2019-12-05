#include "LinkedList.h"
using namespace std;

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
int List<K,V>::insert(K key, V value){
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
void List<K,V>::printList(){
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
