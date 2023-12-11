#include<iostream>
using namespace std;
class Student{
    int id;
    int age;
    bool present;
    string name;
    int nos;
       private:
       string gfname;
       public:
    Student(){
        cout<<"Default constructor called"<<endl;
    }
    Student(int _id,string _name,int _age,bool _present,int _nos){
        cout<<"Parameterized constructor called"<<endl;
        id=_id;
        name=_name;
        age=_age;
        present=_present;
        nos=_nos;

        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Present: "<<present<<endl;
        cout<<"Number of subjects: "<<nos<<endl;
    }
    void study(){
        cout<<"Studying"<<endl;
    }
};
int main(){
    Student s1;
    Student s2(1,"Rahul",20,true,5);
    return 0;
}