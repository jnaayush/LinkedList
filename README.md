# LinkedList
C++ Linked List Implementation

### Files: 
- main.cpp
- LinkedList.inl - contains the implementaion of LinkedList
- LinkedList.h
- UnitTest.h
- UnitTest.cpp - UnitTest to test the implementation
- Makefile
- README.md

### Compile : make

### Run : ./test

-------------------------

## Getting started

### The `List` class

#### To declare a List object
```c++
// Instantiate a List that will hold 'integer'
List<int,int> myList = List<int,int>();

// Or just this
List<int,int> myList;

// But if you are instantiating a pointer List...
List<int,int> *myList = new List<int,int>();

// If you want a List with any other type such as 'MyClass'
// Make sure you call delete(MyClass,YourClass) when you remove!
List<MyClass,YourClass> *myList = new List<MyClass,YourClass>();

```
#### Adding elements

```c++
// insert(key, value) method will insert in list or update the value if key already exists
myList.insert(key,value);
```

#### Getting elements

```c++
// get(key) will return the Node matching that key

// Get the element with key
myNode = myList.get(key);
```

#### Changing elements
```c++
// insert(Key, otherValue) method will change the object's value if matching key is present in the list

myList.insert(key, otherValue);
```

#### Removing elements
```c++
// remove(key) will remove the element

// Remove the object
myList.remove(key);
```
-------------------------
## Implementation Idea
A naive approach of creating a linked list is by chaining nodes one after the other and keeping track of the first node as a handle to the list. This method is simple to implement and insertion of a new node  is very efficient (we could just insert at the beginning). But when it comes to retrieving a node, we have to check each node to see if its key matches the search key. If that node happened to be the very first one to be inserted, we would have to look through the complete list before finding it. Exactly similar is the case for removing a node. For these two operations we get a complexity of O(n). Leaving a room for a lot of improvement in efficiency.

Our efficiency is badly affected when list gets longer and longer. Efficiency would improve drastically, if we could figure out a way to shorten the list and somehow  keep track of those shorter list.
Since, we have a key, value pair, we can leverage the key and come up with a mechanism to keep record of shorter lists. We would use an idea called hashing to achieve this.

To maintain location of these lists, we will use an array to store heads of these shorter lists. To leverage random access of the arrays, the best solution would be calculate hash(key) % arr.size(). We shall place the head at the calculated array index and grow a list at this index for all key that hash to hash(key) % arr.size(). 
This approach greatly increase the efficiency. Although it still is not a constant time O(1) but still is far better than O(n). A detailed analysis for complexity gives an amortized O(1) efficiency. Which is almost O(1) for practical real time uses. This amortized analysis would again lean towards O(n) if the lists gets longer again i.e. data much more the arr.size() is inserted into the list. When that happens (generally at load factor = 0.5, load factor = size/capacity), we would have to increase the array size (generally twice the existing size) and re-hash all the key of the heads to give them a new location new array. 

The current implementation is fixed at arr.size() = 128. For future work, what is still to be done is: changing the array size dynamically at certain threshold size/capacity ratio, re-hashing the entries and coping the entries to the new array. These updates would make the implementation more robust and keep it efficient at increasing loads.

