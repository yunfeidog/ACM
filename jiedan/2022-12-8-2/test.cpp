#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

struct student {
    int id;
    LL xuehao;
    string name;
    string className;
    int val;//用于存储姓名的hash值
} students[30];

struct hashs {
    student s;
    int key;
    int sum;//哈希表中的链表长度
} Hash[50];

//创建学生数组
void createStudent() {
    LL xuehao = 2021150401;
    for (int i = 0; i < 30; i++) {
        students[i].id = i;
        students[i].xuehao = xuehao++;
        students[i].className = "计算机3213";
        students[i].val = 0;
    }
    int idx = 0;
    students[idx++].name = "chenjinhu";
    students[idx++].name = "chenzichao";
    students[idx++].name = "chengtianhao";
    students[idx++].name = "fengwang";
    students[idx++].name = "gaomengyang";
    students[idx++].name = "huangjing";
    students[idx++].name = "liwenjie";
    students[idx++].name = "liujiatao";
    students[idx++].name = "liujinyu";
    students[idx++].name = "liulufeng";
    students[idx++].name = "liurui";
    students[idx++].name = "liushenyang";
    students[idx++].name = "liuzhisha";
    students[idx++].name = "liuziye";
    students[idx++].name = "panruen";
    students[idx++].name = "shenyang";
    students[idx++].name = "shuxinru";
    students[idx++].name = "sonyifan";
    students[idx++].name = "sunhaiyang";
    students[idx++].name = "tianyirong";
    students[idx++].name = "wanghaibao";
    students[idx++].name = "wangjingyi";
    students[idx++].name = "wangmengyang";
    students[idx++].name = "wangqingzhu";
    students[idx++].name = "wangxiaoye";
    students[idx++].name = "wangzhuoya";
    students[idx++].name = "xuhuanran";
    students[idx++].name = "xuziyun";
    students[idx++].name = "chuomengyan";
    students[idx++].name = "zhangjie";

    //计算姓名的ascii值
    for (auto &student: students) {
        int val = 0;
        for (int j = 0; j < student.name.size(); j++) {
            val += student.name[j] - 'a';
        }
        student.val = val;
    }
}

//构建哈希表,使用除留余数法
void createHashTable() {
    for (int i = 0; i < 50; i++) {
        Hash[i].key = -1;
        Hash[i].sum = 0;
        Hash[i].s.name = "NULL";
    }
    //除留余数法
    for (int i = 0; i < 30; i++) {
        int index = students[i].val % 50;
        if (Hash[index].key == -1) {//没有产生冲突
            Hash[index].key = index;
            Hash[index].s = students[i];
            Hash[index].sum = 1;
        } else {
            int j = index;
            while (Hash[j].key != -1) {
                j = (j + 1) % 50;
            }
            Hash[j].key = j;
            Hash[j].s = students[i];
            Hash[j].sum++;
        }
    }
}

//查找学生，顺序查找，并输出查找长度
void findStudent() {
    string name;
    cout << "请输入要查找的学生姓名:";
    cin >> name;
    int val = 0;
    for (int j = 0; j < name.size(); j++) {
        val += name[j] - 'a';
    }
    int index = val % 50;
    int j = index;
    int sum = 0;
    while (Hash[j].key != -1) {
        sum++;
        if (Hash[j].s.name == name) {
            cout << "学号：" << Hash[j].s.xuehao << endl;
            cout << "姓名：" << Hash[j].s.name << endl;
            cout << "班级：" << Hash[j].s.className << endl;
            cout << "查找长度：" << sum << endl;
            return;
        }
        j = (j + 1) % 50;
    }
    cout << "查找失败" << endl;
}


//使用哈希表+二分查找，输出查找长度
void findStudent2() {
    string name;
    cout << "请输入要查找的学生姓名:";
    cin >> name;

    int val = 0;
    for (int j = 0; j < name.size(); j++) {
        val += name[j] - 'a';
    }
    int index = val % 50;
    int j = index;
    int sum = 0;
    while (Hash[j].key != -1) {
        //二分查找,并输出查找次数
        int left = j;
        int right = j + Hash[j].sum - 1;
        while (left < right) {
            sum++;
            int mid = (left + right) / 2;
            if (Hash[mid].s.name == name) {
                cout << "学号：" << Hash[mid].s.xuehao << endl;
                cout << "姓名：" << Hash[mid].s.name << endl;
                cout << "班级：" << Hash[mid].s.className << endl;
                cout << "查找长度：" << sum << endl;
                return;
            } else if (Hash[mid].s.name > name) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    cout << "查找失败" << endl;
}



//打印哈希表
void printHashTable() {
    for (int i = 0; i < 50; i++) {
        cout << "下标:" << i << " 姓名:" << Hash[i].s.name << " 链表长度:" << Hash[i].sum << endl;
    }
}


int main() {
    createStudent();
    createHashTable();
    printHashTable();
//    findStudent();
    findStudent2();

    return 0;

}
