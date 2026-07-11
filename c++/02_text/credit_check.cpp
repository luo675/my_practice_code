#include<iostream>
#include<string>

using namespace std;

class CCLass{
    private:
        string id;
        string name;
        int credit;
        int grade;
    public:
        CCLass(){}
        CCLass(string i,string n,int c,int g):id(i),name(n),credit(c),grade(g){}
        ~CCLass(){}
        void set(){
            cin>>id>>name>>credit>>grade;
        }

};

class Student{
    private:
        string id;
        string name;
        int age;
        string major;
        string grade;
        int type;
        int class_count;
        int all_credits;
        CCLass* cla;

    public:
        Student(){}
        Student(string i,string n,int a,string m,string g):id(i),name(n),age(a),major(m),grade(g){
            type=0;
        }
        ~Student(){
            delete[] cla;
        }
        void record(int n){
            cla=new CCLass[n];
            class_count=n;

            for(int i=0;i<n;++i){
                cla[i].set();
            }
        }

        Student(const Student&obj){
            id="2100"+obj.id;
            type=1;
            name=obj.name;
            grade=1;
            major=obj.major;
            age=obj.age;
            
        }


};

int main(){
    int t;
    if(!(cin>>t))
        return 0;
    
    while(t--){

    }

    return 0;
}