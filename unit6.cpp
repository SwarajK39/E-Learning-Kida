#include <iostream>
#include <cstring>
#include<fstream>
using namespace std;

class student
{

    int roll;
    char name[10];
    char div;
    char address[10];

public:
    student()
    {
        roll = 0;

        div=' ';
        strcpy(name, "");
        strcpy(address, "");
    }
    void input();
    void display();
    int getroll(){
        return roll;
    }
};
class seqfile{

     fstream  file;
     student obj;

    public:
    void create();  //creat a new file
    void add ();
    void search();
    void del();
    void print ();
};
void seqfile::create(){
    char ch='y';
    file.open("student.txt",ios::out|ios::binary);
    while(ch=='y'||ch=='Y'){
        obj.input();
        file.write((char*)&obj,sizeof(obj));
        cout<<"\n Do you wanr continue";
        cin>>ch;
    } 
    file.close();
}
void seqfile::add()
{
    char ch='y';
    file.open("student2.txt",ios::app|ios::out|ios::binary);
    while(ch=='y'||ch=='Y'){
        obj.input();
        file.write((char*)&obj,sizeof(obj));
        cout<<"\n Do you wanr continue";
        cin>>ch;
    } 
    file.close();
}
void seqfile::print()
{
    
    file.open("student3.txt",ios::in|ios::binary);
    if(!file){
         cout<<"file not found";
         exit(0);
    }
    else{
        file.read((char*)&obj,sizeof(obj));
       while(!file. eof()){
       obj.display();
       file.read((char*)&obj,sizeof(obj));
    }
    } 
    file.close();
}  

void student::input(){
    cout<<"\n enter roll no";
    cin>>roll;
     cout<<"\n enter name";
    cin>>name;
     cout<<"\n enter div";
    cin>>div;
     cout<<"\n enter address";
    cin>>address;
}
void student::display(){
    cout<<"\n"<<roll<<"\t"<<div<<"\t"<<name<<"\t"<<address;
}

int main()
{
    // student obj;
    // obj.input();
    // obj.display();
    seqfile cre;
    cre.create();
    cre.add();
}