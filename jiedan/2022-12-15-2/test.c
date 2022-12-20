#include "stdio.h"

typedef struct mstu{
    int id; //学号
    char nme[10];
}mstu;

mstu mlist[9]={{1,"a"},{7,"b"},{8,"c"},{6,"e"},{9,"f"},{12,"g"},{5,"h"}};

int len=7;

void print(){
    for(int i=0;i<len;i++) {
        printf("%d %s\n", mlist[i].id, mlist[i].nme);
    }
}

//使用插入排序对mlist进行排序
void sort(){
    int i,j;
    mstu temp;
    for(i=1;i<len;i++){
        temp=mlist[i];
        for(j=i-1;j>=0;j--){
            if(mlist[j].id>temp.id){
                mlist[j+1]=mlist[j];
            }else{
                break;
            }
        }
        mlist[j+1]=temp;
    }
    print();


}

//删除学号为id的学生
void delete(){
    int id;
    printf("请输入要删除的学生学号：");
    scanf("%d",&id);
    int i;
    for(i=0;i<len;i++){
        if(mlist[i].id==id){
            break;
        }
    }
    if(i==len) {
        printf("没有找到学号为%d的学生,删除失败", id);
    }else{
        for(int j=i;j<len-1;j++){
            mlist[j]=mlist[j+1];
        }
        len--;
        printf("删除成功\n");
        print();
    }
}


int main() {
    sort();
    for(int i=1;i<=3;i++){
        delete();
    }

    return 0;
}
