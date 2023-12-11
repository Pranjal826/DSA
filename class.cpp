#include<iostream>
using namespace std;
class Student{
    int id;
    string name;
    int age;
    int nos;
    void study(){
        cout<<"Studying";
    }
    void sleep(){
        cout<<"Sleeping";
    }
    void bunk(){
        cout<<"Bunking";
    }

};
int main(){
    Student s1;
    Student s2;
    return 0;

}