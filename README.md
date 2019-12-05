# LinkedList
C++ Linked List Implementation

### Files: 
- main.cpp
- LinkedList.inl
- LinkedList.h
- UnitTest.h
- UnitTest.cpp
- Makefile
- README.md

### Compile : make

### Run : ./test

-------------------------

## Getting started

### The `List` class

#### To declare a List object
```c++
// Instantiate a LinkedList that will hold 'integer'
List<int,int> myList = List<int,int>();

// Or just this
List<int,int> myList;

// But if you are instantiating a pointer LinkedList...
List<int,int> *myList = new List<int,int>();

// If you want a List with any other type such as 'MyClass'
// Make sure you call delete(MyClass,YourClass) when you remove!
List<MyClass,YourClass> *myLinkedList = new List<MyClass,YourClass>();

```
#### Adding elements

```c++
// add(obj) method will insert at the END of the list
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
// insert(oldKey, otherValue) method will change the object matching key with otherValue

myList.insert(oldKey, otherValue);
```

#### Removing elements
```c++
// remove(key) will remove the element

// Remove the object
myList.remove(Key);
```

