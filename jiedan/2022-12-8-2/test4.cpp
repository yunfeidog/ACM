#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct student{
    int id;
    LL xuehao;
    string name;
    string className;
}students[100];

//读取xls文件中学生信息,保存到结构体数组中2-31行
void readXls(string fileName){
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
                students[i].xuehao=stoll(field);
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

int main() {





    return 0;
}
