#include "stdio.h"

struct student{
    int classId;
    char name[10];
    int score1,score2,score3;
}students[110];
int len=0;

void print(){
    printf("年级编号\t姓名\t语文\t数学\t英语\n");
    for(int i=0;i<len;i++){
        printf("%d  %s %d %d %d\n",students[i].classId,students[i].name,students[i].score1,students[i].score2,students[i].score3);
    }
}

void add(){
    printf("请输入%d个学生的年级编号\n",len+1);
    scanf("%d",&students[len].classId);
    printf("请输入%d个学生的姓名\n",len+1);
    scanf("%s",students[len].name);
    int idx=1;
    printf("请输入%d个学生第%d门科目成绩\n",len+1,idx++);
    scanf("%d",&students[len].score1);
    printf("请输入%d个学生第%d门科目成绩\n",len+1,idx++);
    scanf("%d",&students[len].score2);
    printf("请输入%d个学生第%d门科目成绩\n",len+1,idx);
    scanf("%d",&students[len].score3);
    len++;
}

void queryByClassId(){
    int classId;
    printf("请输入要查询的年级编号\n");
    scanf("%d",&classId);
    printf("年级编号\t姓名\t语文\t数学\t英语\n");
    for(int i=0;i<len;i++){
        if(students[i].classId==classId){
            printf("%d       %s     %d     %d     %d\n",students[i].classId,students[i].name,students[i].score1,students[i].score2,students[i].score3);
        }
    }
}

int main() {
    for(int i=1;i<=3;i++) add();
    print();
    queryByClassId();

    return 0;
}
