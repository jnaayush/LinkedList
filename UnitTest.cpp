#include<iostream>
#include"UnitTest.h"
#include"LinkedList.h"
#include"LinkedList.inl"
using namespace std;

void UnitTest::TestInsertRemoveFunction(){
    try{
        cout <<"\nTesting insert function with List<char,char> \n";
        List<char,char> *l = new List<char,char>(100);
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

void UnitTest::TestKeyValue(){
    try{
        cout<< "\nTesting key, value assignment\n";
        Node<string,string> *sNode = new Node<string,string>("MATHWORKS","SIMULINK");
        
        //Test Key assignment
        assert(sNode->getKey() == "MATHWORKS");
        
        //Test Value assignment
        assert(sNode->getValue() == "SIMULINK");
        
        cout << "node assignment test Passed \n";
    } catch(...){
        cout << "Node assignment test failed\n";
    }
}

void UnitTest::TestNodeUpdationOnInsert(){
    try{
        cout << "\nTesting Node update\n";
        List<int,int> *lI = new List<int,int>(100);
        assert(INSERT_SUCCESS == lI->insert(1,10));
        assert(INSERT_SUCCESS == lI->insert(2,20));
        assert(INSERT_SUCCESS == lI->insert(3,30));
        lI->display();
        cout << "After Update\n";
        assert(UPDATE_VALUE_SUCCESS == lI->insert(1,100));
        assert(100 == lI->get(1)->getValue());
        assert(UPDATE_VALUE_SUCCESS == lI->insert(2,200));
        assert(200 == lI->get(2)->getValue());
        assert(UPDATE_VALUE_SUCCESS == lI->insert(3,300));
        assert(300 == lI->get(3)->getValue());
        lI->display();
        cout << "Node update Passed\n";
    } catch(...) {
        cout << "Node update failed\n";
    }
}

void UnitTest::TestListOfClass(){
    try{
        cout << "\nTesting List of Custom Class\n";
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
                return p.firstName.length() + p.lastName.length();
            }
        };
            
        List<string, Person > *lSP = new List<string, Person >(100);
            
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
        
        List<Person, string, PersonHash> *lPP = new List<Person, string, PersonHash >(100);
        assert(INSERT_SUCCESS == lPP->insert(p1,"Golf"));
        string sport = lPP->get(p1)->getValue();
        assert("Golf" ==  sport);
        assert(INSERT_SUCCESS == lPP->insert(p2,"Cricket"));
        assert(UPDATE_VALUE_SUCCESS == lPP->insert(p1,"BasketBall"));
        sport = lPP->get(p1)->getValue();
        assert("BasketBall" ==  sport);
        
        cout << "Custom Class Key Value Passed\n";
    } catch(...) {
        cout << "Custom Class Key Value failed\n";
    }
}
