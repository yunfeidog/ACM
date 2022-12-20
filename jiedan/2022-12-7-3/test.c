#include "stdio.h"
#include "string.h"

struct entry {
    char name[100];
    char number[100];
    char email[100];
    char department[100];
} list[1010];

int len = 0;

void print();

void add();

void modify();

void delete();

void search();

void menu();

int bf( char*str,  char *pattern);

int main() {
    while (1) {
        menu();
        printf("Please enter your choice(1-6): ");
        char choice[100];
        scanf("%s", choice);
        if (strcmp(choice, "1") == 0) {
            print();
        } else if (strcmp(choice, "2") == 0) {
            add();
        } else if (strcmp(choice, "3") == 0) {
            modify();
        } else if (strcmp(choice, "4") == 0) {
            delete();
        } else if (strcmp(choice, "5") == 0) {
            search();
        } else if (strcmp(choice, "6") == 0) {
            printf("Quit\n");
            break;
        } else {
            printf("Unknown option!\n");
        }

    }
    return 0;
}

void menu(){
    printf("1. Print contact list\n");
    printf("2. Add a contact\n");
    printf("3. Modify a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search a contact\n");
    printf("6. Quit\n");
}

void print() {
    if (len == 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        printf("%s    ", list[i].number);
        printf("%s    ", list[i].email);
        printf("%s    ", list[i].name);
        printf("(%s)\n", list[i].department);
    }
}

void add() {
    getchar();
    printf("Please enter the name:");
//    scanf("%s", list[len].name);
    scanf("%[^\n]", list[len].name);
    getchar();
//    fgets(list[len].name,sizeof list[len].name,stdin);
    printf("Please enter the phone number:");
//    scanf("%s", list[len].number);
    scanf("%[^\n]", list[len].number);
    getchar();
//    fgets(list[len].number,sizeof list[len].number,stdin);
    printf("Please enter the email:");
//    scanf("%s", list[len].email);
    scanf("%[^\n]", list[len].email);
    getchar();
//    fgets(list[len].email,sizeof list[len].email,stdin);
    printf("Please enter the department:");
//    scanf("%s", list[len].department);
    scanf("%[^\n]", list[len].department);
    getchar();
//    fgets(list[len].department,sizeof list[len].department,stdin);
    len++;
    //Determine whether the phone number already exists
    for (int i = 0; i < len - 1; i++) {
        if (strcmp(list[i].number, list[len - 1].number) == 0) {
            printf("Entry already exists, ignoring duplicate entry\n");
            len--;
            return;
        }
    }
    //电话为空
    if (strcmp(list[len - 1].number, "") == 0) {
        printf("Phone number cannot be empty, ignoring entry\n");
        len--;
        return;
    }
    //一个有效的电话号码可能包含“+”、“-”、“（”和“）”的数字和非数字字符。一个电话号码中至少应该有一个数字。
    int flag = 0;
    for (int i = 0; i < strlen(list[len - 1].number); i++) {
        if (list[len - 1].number[i] >= '0' && list[len - 1].number[i] <= '9') {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Invalid phone number");
        len--;
        return;
    }
    //有效的电子邮件地址由电子邮件前缀和电子邮件域组成，两者均为可接受的格式。
    //判断电子邮件是否有效
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < strlen(list[len - 1].email); i++) {
        if (list[len - 1].email[i] == '@') {
            flag1 = 1;
            break;
        }
    }
    for (int i = 0; i < strlen(list[len - 1].email); i++) {
        if (list[len - 1].email[i] == '.') {
            flag2 = 1;
            break;
        }
    }

    if(strcmp(list[len-1].email,"")==0){

        return;
    }
    if (flag1 == 0 || flag2 == 0) {
        return;
    }
}


void modify() {
    printf("Enter the phone number to modify:");
    char number[100];
    scanf("%s", number);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(list[i].number, number) == 0) {
            flag = 1;
            getchar();
            printf("Enter the name(return to keep[%s]):", list[i].name);
            char name[100];
            fgets(name,sizeof name,stdin);
            if (strcmp(name, "") != 0) {
                strcpy(list[i].name, name);
            }
//            scanf("%s", list[i].name);
            printf("Enter the number(return to keep[%s]):", list[i].number);
//            scanf("%s", list[i].number);
            char number1[100];
            fgets(number1,sizeof number1,stdin);
            if (strcmp(number1, "") != 0) {
                strcpy(list[i].number, number1);
            }
            printf("Enter the email(return to keep[%s]):", list[i].email);
            char email[100];
            fgets(email,sizeof email,stdin);
            if (strcmp(email, "") != 0) {
                strcpy(list[i].email, email);
            }
//            scanf("%s", list[i].email);
            printf("Enter the department(return to keep[%s]):", list[i].department);
            char department[100];
            fgets(department,sizeof department,stdin);
            if (strcmp(department, "") != 0) {
                strcpy(list[i].department, department);
            }
//            scanf("%s", list[i].department);
            break;
        }
    }
    if (flag == 0) {
        printf("Entry doed not exist.\n");
    }


}

void delete() {
    printf("Enter the phone number to delete (return to cancel): ");
    getchar();
    char number[100];
//    scanf("%s", number);
    fgets(number,sizeof number,stdin);
    if (strcmp(number, "") == 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        if (strcmp(list[i].number, number) == 0) {
            for (int j = i; j < len - 1; j++) {
                list[j] = list[j + 1];
            }
            printf("Successfully deleted the entry for %s\n",number);
            len--;
        }
    }

}

int bf(char *str, char *pattern) {
    int i = 0;
    int j = 0;
    int len1 = strlen(str);
    int len2 = strlen(pattern);
    while (i < len1 && j < len2) {
        if (str[i] == pattern[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == len2) {
        return i - j;
    } else {
        return -1;
    }
}

void search() {
    printf("Search: ");
    char cxk[100];
    scanf("%s", cxk);
    if (strcmp(cxk, "") == 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        if (bf(list[i].number, cxk) != -1) {
            printf("%s    ", list[i].name);
            printf("%s    ", list[i].number);
            printf("%s    ", list[i].email);
            printf("%s    ", list[i].department);
            printf("\n");
            continue;
        }
        if (bf(list[i].name, cxk) != -1) {
            printf("%s    ", list[i].name);
            printf("%s    ", list[i].number);
            printf("%s    ", list[i].email);
            printf("%s    ", list[i].department);
            printf("\n");
            continue;
        }
        if (bf(list[i].email, cxk) != -1) {
            printf("%s    ", list[i].name);
            printf("%s    ", list[i].number);
            printf("%s    ", list[i].email);
            printf("%s    ", list[i].department);
            printf("\n");
            continue;
        }
        if (bf(list[i].department, cxk) != -1) {
            printf("%s    ", list[i].name);
            printf("%s    ", list[i].number);
            printf("%s    ", list[i].email);
            printf("%s    ", list[i].department);
            printf("\n");
            continue;
        }
    }
}

