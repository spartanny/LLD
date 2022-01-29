#include<iostream>
using namespace std;

enum Sex {Male,Female,Other};
// class that will be used inside another file
class Person{
    int age;
    string name;
    Sex sex;
public:
    Person(int age,string name,Sex sex){
        this->age = age;
        this->name = name;
        this->sex = sex;
    }
    void walk(){
        cout<<name<<" walked\n";
    }
    void sleep(){
        cout<<name<<" slept\n";
    }
};