#include "stdio.h"
#include "string.h"

struct entry {
    char name[100];
    char number[100];
    char email[100];
    char department[100];
} list[10010];

int len = 0;

void print();

void add();

void modify();

void delete();

void search();


int main() {
    printf("Welcome to the contact system\n");
    printf("1. Print contact list\n");
    printf("2. Add a contact\n");
    printf("3. Modify a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search a contact\n");
    printf("6. Quit\n");
    while (1) {
        printf("Please enter your choice(1-6): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            print();
        } else if (choice == 2) {
            add();
        } else if (choice == 3) {
            modify();
        } else if (choice == 4) {
            delete();
        } else if (choice == 5) {
            search();
        } else if (choice == 6) {
            printf("Quit\n");
            break;
        } else {
            printf("Unknown option!\n");
        }
    }
    return 0;
}

void print() {
    //You should first print the phone number, then the email id,
    // then the label, then the name, then the space, and then the department name in parentheses.
    if (len == 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        printf("the phone number is %s  ", list[i].number);
        printf("the email is %s  ", list[i].email);
        printf("the name is %s  ", list[i].name);
        printf("the department is %s\n", list[i].department);
    }
}

void add() {
    printf("Please enter the name: \n");
    scanf("%s", list[len].name);
    printf("Please enter the phone number: \n");
    scanf("%s", list[len].number);
    printf("Please enter the email: \n");
    scanf("%s", list[len].email);

    printf("Please enter the department: \n");
    scanf("%[^\n]", list[len].department);

//    len++;
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
    if (flag1 == 0 || flag2 == 0) {
        printf("Invalid email id\n");
        len--;
        len--;
        return;
    }
}

void modify() {
    printf("Please enter the phone number: ");
    char number[100];
    scanf("%s", number);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(list[i].number, number) == 0) {
            flag = 1;
//For each field, if the user presses the return key without entering any other characters, the program should retain the existing value of that field.
            printf("Please enter the new name[return to keep name]: ");
            char name[100];
            scanf("%s", name);
            if (strcmp(name, "") != 0) {
                strcpy(list[i].name, name);
            }
            printf("Please enter the new phone number[return to keep number]: ");
            char number[100];
            scanf("%s", number);
            if (strcmp(number, "") != 0) {
                //Determine whether the phone number is valid
                int flag1 = 0;
                for (int j = 0; j < strlen(number); j++) {
                    if (number[j] >= '0' && number[j] <= '9') {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0) {
                    printf("Invalid phone number\n");
                    printf("Phone number must contain at least one digit, ignoring entry\n");
                    return;
                }
                strcpy(list[i].number, number);
            }
            printf("Please enter the new email[return to keep email]: ");
            char email[100];
            scanf("%s", email);
            if (strcmp(email, "") != 0) {
                //Determine whether the email is valid
                int flag1 = 0;
                int flag2 = 0;
                for (int j = 0; j < strlen(email); j++) {
                    if (email[j] == '@') {
                        flag1 = 1;
                        break;
                    }
                }
                for (int j = 0; j < strlen(email); j++) {
                    if (email[j] == '.') {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag1 == 0 || flag2 == 0) {
                    printf("Invalid email id\n");
                    return;
                }
                strcpy(list[i].email, email);
            }
            printf("Please enter the new department[return to keep department]: ");
            char department[100];
            scanf("%s", department);
            if (strcmp(department, "") != 0) {
                strcpy(list[i].department, department);
            }
        }
    }
    if (flag == 0) {
        printf("Entry not found\n");
    }
}

void delete() {
    printf("Please enter the phone number[return to cancel]: ");
    char number[100];
    scanf("%s", number);
    if (strcmp(number, "") == 0) {
        return;
    }
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(list[i].number, number) == 0) {
            flag = 1;
            for (int j = i; j < len - 1; j++) {
                list[j] = list[j + 1];
            }
            len--;
        }
    }
    if (flag == 0) {
        printf("Entry not found\n");
    }
}

void search() {
    printf("Please enter the phone number[return to cancel]: ");
    char number[100];
    scanf("%s", number);
    if (strcmp(number, "") == 0) {
        return;
    }
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(list[i].number, number) == 0) {
            flag = 1;
            printf("Name: %s  ", list[i].name);
            printf("Phone number: %s  ", list[i].number);
            printf("Email: %s  ", list[i].email);
            printf("Department: %s  ", list[i].department);
        }
    }
    if (flag == 0) {
        printf("Entry not found\n");
    }
}