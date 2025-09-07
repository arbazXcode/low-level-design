#include<iostream>
#include<string>

using namespace std;

//-- BAD Example

class Student{
    private:
        string name;
        int age;
    public: 
        Student(string n, int age ) : name(n), age(age){}

        void showDetails(){
            cout<< "Name: " << name <<" age: " <<age<<endl;
        }

        void saveFile(){
            cout<<"Saving the data to file"<<endl;
        }

        void sendEmail(){
            cout<<"Sending email to: "<<name <<endl;
        }
};

//Problem is ->
//01. Student is handling data + persistence + communication
//if in future we need to change email logic or database logic, we'll have to touch the class
//which violates the Single Responsibility Principle




///------------- GOOD EXAMPLE

class Student{
    private: 
        string name;
        int age;
    public:
        Student(string name, int age) : name(name), age(age) {}

        string getName(){
            return name;
        }

        int age(){
            return age;
        }
};

//separate class for persistence

class StudentRepository{
    public:
        void save(Student &s){
            cout<<"Saving " <<s.getName() <<" to file...."<<endl;
        }
};


//separate class for communication
class EmailService{
    public:
        void sendEmail(Student &s){
            cout<<"sending email to " << s.getName() <<endl;
        }
};

//Now student only shares data
//StudentRepository -> saving logic
//EmailService -> sends email to students