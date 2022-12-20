#include <iostream>

using namespace std;

struct student{
    int id;
    string name;
    int score;
}students[100];

int len=0;



void print(){
    //打印成绩高于平均分的学生信息
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=students[i].score;
    }
    double avg=sum/len;
    cout<<"成绩高于平均分的学生信息如下："<<endl;
    cout<<"姓名\t学号\t成绩"<<endl;
    for(int i=0;i<len;i++){
        if(students[i].score>avg){
            cout<<students[i].id<<"     "<<students[i].name<<"     "<<students[i].score<<endl;
        }
    }
}

int main() {
    cout<<"请输入10个学生的信息"<<endl;
    for (int i = 0; i < 10; ++i) {
        cin>>students[len].id>>students[len].name>>students[len].score;
        len++;
    }
    print();

    return 0;
}
//
//1 cxk 100
//2 cxk1 20
//3 cxk2 30
//4 cxk3 40
//5 cxk4 50
//6 cxk5 10
//7 cxk6 20
//8 cxk7 100
//9 cxk8 90
//10 cx9k 100
