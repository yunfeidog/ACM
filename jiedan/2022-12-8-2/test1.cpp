#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct student{
    int id;
    string xuehao;
    string name;
    string className;
}students[100];

//读取xlc文件中学生信息,第一行不要
void readXlc(string fileName){
    ifstream in(fileName);
    string line;
    int i=0;
    while(getline(in,line)){
        if(i==0){
            i++;
            continue;
        }
        stringstream ss(line);
        string field;
        int j=0;
        while(getline(ss,field,',')){
            if(j==0){
                students[i].id=stoi(field);
            }else if(j==1){
                students[i].xuehao=field;
            }else if(j==2){
                students[i].name=field;
            }else if(j==3){
                students[i].className=field;
            }
            j++;
        }
        i++;
    }
}


//创建哈希表
vector<student> hashTable[100];

//哈希函数,除留余数法
int hashFunc(string xuehao){
    int sum = 0;
    for(int i = 0; i < xuehao.size(); i++){
        sum += xuehao[i];
    }
    return sum % 100;
}

//插入哈希表
void insertHashTable(){
    for(int i = 0; i < 100; i++){
        int index = hashFunc(students[i].xuehao);
        hashTable[index].push_back(students[i]);
    }
}


int main()
{

    return 0;
}
