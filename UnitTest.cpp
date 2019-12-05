#include<iostream>
#include"UnitTest.h"
#include"LinkedList.h"
#include"LinkedList.inl"
using namespace std;

void UnitTest::TestInsertRemoveFunction(){
    try{
        cout <<"\nTesting Insert and Remove functions with List<char,char>... \n";
        List<char,char> *l = new List<char,char>();
        
        // Deleting non existant key
        assert(KEY_NOT_FOUND == l->remove('a'));
        for(char c = 'a'; c <= 'p'; c++){
            assert(KEY_NOT_FOUND == l->remove(c));
        }
        
        //Inserting key,values
        for(char c = 'a'; c <= 'p'; c++){
            assert(INSERT_SUCCESS == l->insert(c,c));
        }
        l->display();
        //removing in same order
        for(char c = 'a'; c <= 'p'; c++){
            assert(REMOVE_SUCCESS == l->remove(c));
        }
        
        //Inserting key,values
        for(char c = 'a'; c <= 'p'; c++){
            assert(INSERT_SUCCESS == l->insert(c,c));
        }
        //removing in reverse order
        for(char c = 'p'; c >= 'a'; c--){
            assert(REMOVE_SUCCESS == l->remove(c));
        }
        delete(l);
        cout << "Insert and Remove Test Passed\n";
    } catch (...){
        cout << "Insert and Remove Test failed\n";
    }
}

void UnitTest::TestKeyValue(){
    try{
        cout<< "\nTesting node assignment...\n";
        Node<string,string> *sNode = new Node<string,string>("MATHWORKS","SIMULINK");
        
        //Test Key assignment
        assert(sNode->getKey() == "MATHWORKS");
        cout << sNode->getKey() << "\n";
        //Test Value assignment
        assert(sNode->getValue() == "SIMULINK");
        cout << sNode->getValue() << "\n";
        
        cout << "Node assignment test Passed \n";
    } catch(...){
        cout << "Node assignment test failed\n";
    }
}

void UnitTest::TestNodeUpdationOnInsert(){
    try{
        cout << "\nTesting Node on inserting same key...\n";
        List<int,int> *lI = new List<int,int>();
        assert(INSERT_SUCCESS == lI->insert(1,10));
        assert(INSERT_SUCCESS == lI->insert(2,20));
        assert(INSERT_SUCCESS == lI->insert(3,30));
        lI->display();
        cout << "After Update\n";
        assert(UPDATE_VALUE_SUCCESS == lI->insert(1,100));
        assert(UPDATE_VALUE_SUCCESS == lI->insert(2,200));
        assert(UPDATE_VALUE_SUCCESS == lI->insert(3,300));
        lI->display();
        cout << "Node update Passed\n";
    } catch(...) {
        cout << "Node update failed\n";
    }
}

void UnitTest::TestListOfClass(){
    try{
        cout << "\nTesting List of Custom Class...\n";
        class Person{
        public:
            string firstName;
            string lastName;
            bool operator == (struct Person p2){
                return this->firstName == p2.firstName && this->lastName == p2.lastName;
            }
            bool operator != (struct Person p2){
                return this->firstName != p2.firstName || this->lastName != p2.lastName;
            }
        };
        class PersonHash {
        public:
            size_t operator()(const Person& p) const
            {
                return hash<string>{}(p.firstName) ^ hash<string>{}(p.lastName);
            }
        };
            
        List<string, Person > *lSP = new List<string, Person >();
            
        Person p1;
        p1.firstName = "Micheal";
        p1.lastName = "Jordan";
        
        Person p2;
        p2.firstName = "Sachin";
        p2.lastName = "Tendulkar";
        
        Person p3;
        p3.firstName = "P.";
        p3.lastName = "Gopichand";
        
        assert(INSERT_SUCCESS == lSP->insert("Basketball",p1));
        assert(INSERT_SUCCESS == lSP->insert("Cricket",p2));
        assert(INSERT_SUCCESS == lSP->insert("Badminton",p3));
        
        List<Person, string, PersonHash> *lPP = new List<Person, string, PersonHash >();
        assert(INSERT_SUCCESS == lPP->insert(p1,"Golf"));
        assert(INSERT_SUCCESS == lPP->insert(p2,"Cricket"));
        assert(UPDATE_VALUE_SUCCESS == lPP->insert(p1,"BasketBall"));
        
        cout << "Custom Class Key Value Passed\n";
    } catch(...) {
        cout << "Custom Class Key Value failed\n";
    }
}
