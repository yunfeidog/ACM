#include "stdio.h"
#include "string.h"
#include "stdlib.h"

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


int bf(char *str, char *pattern);

int main() {
    while (1) {
        menu();
        printf("Option: ");
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
            //ιζΎεε­
            for (int i = 0; i < len; i++) {
                free(list[i].name);
                free(list[i].number);
                free(list[i].email);
                free(list[i].department);
            }
            break;
        } else {
            printf("Unknown option!\n");
        }

    }
    return 0;
}

void menu() {
    printf("1) Print contact list\n");
    printf("2) Add a contact\n");
    printf("3) Modify a contact\n");
    printf("4) Delete a contact\n");
    printf("5) Search a contact\n");
    printf("6) Quit\n");
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
    scanf("%[^\n]", list[len].name);
    getchar();
    printf("Please enter the phone number:");
    scanf("%[^\n]", list[len].number);
    getchar();
    printf("Please enter the email:");
    scanf("%[^\n]", list[len].email);
    getchar();
    printf("Please enter the department:");
    scanf("%[^\n]", list[len].department);
    getchar();
    len++;
    //Determine whether the phone number already exists
    for (int i = 0; i < len - 1; i++) {
        if (strcmp(list[i].number, list[len - 1].number) == 0) {
            printf("Entry already exists, ignoring duplicate entry\n");
            len--;
            return;
        }
    }
    //η΅θ―δΈΊη©Ί
    if (strcmp(list[len - 1].number, "") == 0) {
        printf("Phone number cannot be empty, ignoring entry\n");
        len--;
        return;
    }
    //δΈδΈͺζζηη΅θ―ε·η ε―θ½εε«β+βγβ-βγβοΌβεβοΌβηζ°ε­ειζ°ε­ε­η¬¦γδΈδΈͺη΅θ―ε·η δΈ­θ³ε°εΊθ―₯ζδΈδΈͺζ°ε­γ
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
    //ζζηη΅ε­ι?δ»Άε°εη±η΅ε­ι?δ»ΆεηΌεη΅ε­ι?δ»Άεη»ζοΌδΈ€θεδΈΊε―ζ₯εηζ ΌεΌγ
    //ε€ζ­η΅ε­ι?δ»Άζ―ε¦ζζ
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
    //ζεδΈδΈͺ.ει’θ³ε°ζ2δΈͺε­η¬¦
    int flag3 = 0;
    for (int i = 0; i < strlen(list[len - 1].email); i++) {
        if (list[len - 1].email[i] == '.') {
            if (strlen(list[len - 1].email) - i - 1 >= 2) {
                flag3 = 1;
                break;
            }
        }
    }
    if (strcmp(list[len - 1].email, "") == 0) {
        return;
    }
    if (flag1 == 0 || flag2 == 0 || flag3 == 0) {
        printf("Invalid email address\n");
        len--;
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
            scanf("%[^\n]", name);
            getchar();


            printf("Enter the number(return to keep[%s]):", list[i].number);
            char number1[100];
            scanf("%[^\n]", number1);
            getchar();
            if (strcmp(number1, "") != 0) {
                //δΈδΈͺζζηη΅θ―ε·η ε―θ½εε«β+βγβ-βγβοΌβεβοΌβηζ°ε­ειζ°ε­ε­η¬¦γδΈδΈͺη΅θ―ε·η δΈ­θ³ε°εΊθ―₯ζδΈδΈͺζ°ε­γ
                int flag1 = 0;
                for (int j = 0; j < strlen(number1); j++) {
                    if (number1[j] >= '0' && number1[j] <= '9'&&number1[j]!='+'&&number1[j]!='-'&&number1[j]!='('&&number1[j]!=')') {
                        flag1 = 1;
                    }
                }
                if (flag1 == 0) {
                    printf("Invalid phone number\n");
                    return;
                }
                //ε€ζ­η΅θ―ε·η ζ―ε¦ιε€
                for (int j = 0; j < len; j++) {
                    if (strcmp(list[j].number, number1) == 0) {
                        printf("Entry already exists, ignoring duplicate entry\n");
                        return;
                    }
                }
            }


            printf("Enter the email(return to keep[%s]):", list[i].email);
            char email[100];
            scanf("%[^\n]", email);
            getchar();
            if (strcmp(email, "") != 0) {
                //ιͺθ―ι?η?±ζ―ε¦ζζ
                int flag2 = 0;
                int flag3 = 0;
                for (int i = 0; i < strlen(email); i++) {
                    if (email[i] == '@') {
                        flag2 = 1;
                        break;
                    }
                }
                for (int i = 0; i < strlen(email); i++) {
                    if (email[i] == '.') {
                        flag3 = 1;
                        break;
                    }
                }
                //ζεδΈδΈͺ.ει’θ³ε°ζ2δΈͺε­η¬¦
                //ζεδΈδΈͺ.ει’θ³ε°ζ2δΈͺε­η¬¦
                int flag4 = 0;
                for (int i = 0; i < strlen(email); i++) {
                    if (email[i] == '.') {
                        if (strlen(email) - i - 1 >= 2) {
                            flag4 = 1;
                            break;
                        }
                    }
                }
                if (flag2 == 0 || flag3 == 0 || flag4 == 0) {
                    printf("Invalid email address\n");
                    return;
                }
            }
            printf("Enter the department(return to keep[%s]):", list[i].department);
            char department[100];
            scanf("%[^\n]", department);
            getchar();


            if (strcmp(department, "") != 0) {
                strcpy(list[i].department, department);
            }

            if (strcmp(name, "") != 0) {
                strcpy(list[i].name, name);
            }

            if (strcmp(number1, "") != 0) {
                strcpy(list[i].number, number1);
            }
            if (strcmp(email, "") != 0) {
                strcpy(list[i].email, email);
            }


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
    scanf("%[^\n]", number);
    getchar();

    if (strcmp(number, "") == 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        if (strcmp(list[i].number, number) == 0) {
            for (int j = i; j < len - 1; j++) {
                list[j] = list[j + 1];
            }
            printf("Successfully deleted the entry for %s\n", number);
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
    getchar();
    char cxk[100];
    //θ―»δΈθ‘εζ¬η©Ίζ Ό
    scanf("%[^\n]", cxk);
    getchar();
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

