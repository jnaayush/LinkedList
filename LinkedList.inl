#include "LinkedList.h"
using namespace std;

template <typename K,typename V, typename H>
List<K,V,H>::List(){
    hashArr = new Node<K, V> *[arrSize]();
    for(int i=0 ; i < arrSize ; i++)
        hashArr[i] = NULL;
}

template <typename K,typename V, typename H>
List<K,V,H>::~List(){
    for (int i = 0; i < arrSize; ++i) {
        Node<K, V> *entry = hashArr[i];
        while (entry != NULL) {
            Node<K, V> *prev = entry;
            entry = entry->next;
            delete prev;
        }
        hashArr[i] = NULL;
    }
    delete [] hashArr;
    
}

template <typename K,typename V, typename H>
size_t List<K,V,H>::customHash(K key){
    H hashKey;
    size_t h1 = hashKey(key);
    return h1 % arrSize;
}

template <typename K,typename V, typename H>
int List<K,V,H>::remove(K key){
    size_t hashIndex = customHash(key);
    Node<K, V> *prev = NULL;
    Node<K, V> *cur = hashArr[hashIndex];
    
    while (cur != NULL && cur->key != key) {
        prev = cur;
        cur = cur->next;
    }
    
    if (cur == NULL)
        return KEY_NOT_FOUND;
    
    if (prev == NULL) {
        hashArr[hashIndex] = cur->next;
    } else {
        prev->next = cur->next;
    }
    delete cur;
    return REMOVE_SUCCESS;
}

template <typename K,typename V, typename H>
int List<K,V,H>::insert(K key, V value){
    size_t hashIndex = customHash(key);
    Node<K,V> *prev = NULL;
    Node<K,V> *cur = hashArr[hashIndex];
    while (cur != NULL && cur->key != key) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        cur = new Node<K, V>(key, value);
        if (prev == NULL) {
            hashArr[hashIndex] = cur;
        } else {
            prev->next = cur;
        }
        return INSERT_SUCCESS;
    }
    cur->value = value;
    return UPDATE_VALUE_SUCCESS;
}


template <typename K,typename V, typename H>
void List<K,V,H>::display(){
    for(int i=0 ; i < arrSize ; i++){
        if(hashArr[i] != NULL){
            Node<K,V> *cur = hashArr[i];
            while(cur != NULL){
                cout << "key = " << cur->key <<"  value = "<< cur->value << endl;
                cur = cur->next;
            }
        }
    }
}
