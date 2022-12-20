#include "stdio.h"
#include "string.h"
#include "stdlib.h"


struct Student {
    char firstName[20];
    char surName[20];
    char gender[5];
    int id;
    int age;
};

//Stores all the student records on an AVL tree.
struct AVLTree {
    struct Student student;
    struct AVLTree *left;
    struct AVLTree *right;
    int height;
};

//Returns the height of the AVL tree.
int height(struct AVLTree *tree) {
    if (tree == NULL) {
        return 0;
    }
    return tree->height;
}

//Returns the maximum of two integers.
int max(int a, int b) {
    return (a > b) ? a : b;
}

//Returns the balance factor of the AVL tree.
int getBalance(struct AVLTree *tree) {
    if (tree == NULL) {
        return 0;
    }
    return height(tree->left) - height(tree->right);
}

//Returns the right rotated AVL tree.
struct AVLTree *rightRotate(struct AVLTree *tree) {
    struct AVLTree *left = tree->left;
    struct AVLTree *right = left->right;
    left->right = tree;
    tree->left = right;
    tree->height = max(height(tree->left), height(tree->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;
    return left;
}

//Returns the left rotated AVL tree.
struct AVLTree *leftRotate(struct AVLTree *tree) {
    struct AVLTree *right = tree->right;
    struct AVLTree *left = right->left;
    right->left = tree;
    tree->right = left;
    tree->height = max(height(tree->left), height(tree->right)) + 1;
    right->height = max(height(right->left), height(right->right)) + 1;
    return right;
}

//Returns the minimum value node in the AVL tree.
struct AVLTree *minValueNode(struct AVLTree *tree) {
    struct AVLTree *current = tree;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

//Returns the AVL tree after inserting the student record.
struct AVLTree *insert(struct AVLTree *tree, struct Student student) {
    if (tree == NULL) {
        struct AVLTree *newNode = (struct AVLTree *) malloc(sizeof(struct AVLTree));
        newNode->student = student;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    if (student.id < tree->student.id) {
        tree->left = insert(tree->left, student);
    } else if (student.id > tree->student.id) {
        tree->right = insert(tree->right, student);
    } else {
        return tree;
    }
    tree->height = 1 + max(height(tree->left), height(tree->right));
    int balance = getBalance(tree);
    if (balance > 1 && student.id < tree->left->student.id) {
        return rightRotate(tree);
    }
    if (balance < -1 && student.id > tree->right->student.id) {
        return leftRotate(tree);
    }
    if (balance > 1 && student.id > tree->left->student.id) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }
    if (balance < -1 && student.id < tree->right->student.id) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }
    return tree;
}

//Returns the AVL tree after deleting the student record.
struct AVLTree *delete(struct AVLTree *tree, int id) {
    if (tree == NULL) {
        return tree;
    }
    if (id < tree->student.id) {
        tree->left = delete(tree->left, id);
    } else if (id > tree->student.id) {
        tree->right = delete(tree->right, id);
    } else {
        if ((tree->left == NULL) || (tree->right == NULL)) {
            struct AVLTree *temp = tree->left ? tree->left : tree->right;
            if (temp == NULL) {
                temp = tree;
                tree = NULL;
            } else {
                *tree = *temp;
            }
            free(temp);
        } else {
            struct AVLTree *temp = minValueNode(tree->right);
            tree->student = temp->student;
            tree->right = delete(tree->right, temp->student.id);
        }
    }
    if (tree == NULL) {
        return tree;
    }
    tree->height = 1 + max(height(tree->left), height(tree->right));
    int balance = getBalance(tree);
    if (balance > 1 && getBalance(tree->left) >= 0) {
        return rightRotate(tree);
    }
    if (balance > 1 && getBalance(tree->left) < 0) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }
    if (balance < -1 && getBalance(tree->right) <= 0) {
        return leftRotate(tree);
    }
    if (balance < -1 && getBalance(tree->right) > 0) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }
    return tree;
}

//Returns the student record with the given id.
struct Student *search(struct AVLTree *tree, int id) {
    if (tree == NULL) {
        return NULL;
    }
    if (id < tree->student.id) {
        return search(tree->left, id);
    } else if (id > tree->student.id) {
        return search(tree->right, id);
    } else {
        return &tree->student;
    }
}

//Prints the student records in the AVL tree.
void print(struct AVLTree *tree) {
    if (tree != NULL) {
        print(tree->left);
        printf("firstName: %s;Surname: %s;", tree->student.firstName, tree->student.surName);
        printf("gender: %s;", tree->student.gender);
        printf("ID: %d;", tree->student.id);
        printf("Age: %d\n", tree->student.age);
        print(tree->right);
    }
}

//Returns the AVL tree after deleting all the student records.
struct AVLTree *deleteAll(struct AVLTree *tree) {
    if (tree != NULL) {
        deleteAll(tree->left);
        deleteAll(tree->right);
        free(tree);
    }
    return NULL;
}


void addStudent(struct AVLTree **tree) {
    struct Student student;
    printf("Enter the first name: ");
    scanf("%s", student.firstName);
    printf("Enter the surname: ");
    scanf("%s", student.surName);
    printf("Enter the gender");
    scanf("%s", student.gender);
    printf("Enter the id: ");
    scanf("%d", &student.id);
    printf("Enter the age: ");
    scanf("%d", &student.age);
    *tree = insert(*tree, student);
}

void deleteStudent(struct AVLTree **tree) {
    int id;
    printf("Enter the id: ");
    scanf("%d", &id);
    *tree = delete(*tree, id);
}

void searchStudent(struct AVLTree *tree) {
    int id;
    printf("Enter the id: ");
    scanf("%d", &id);
    struct Student *student = search(tree, id);
    if (student != NULL) {
        printf("firstName: %s;Surname: %s;", tree->student.firstName, tree->student.surName);
        printf("gender: %s;", tree->student.gender);
        printf("ID: %d;", tree->student.id);
        printf("Age: %d\n", tree->student.age);
    } else {
        printf("Student record not found.");
    }
}

void printStudents(struct AVLTree *tree) {
    print(tree);
}

//从文件中读取学生信息
void readFromFile(struct AVLTree **tree) {
    FILE *file = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-7-1\\studentList.txt", "r");
    if (file == NULL) {
        printf("File not found.");
        return;
    }
    struct Student student;
    while (fscanf(file, "%s, %s, %s, %d, %d", student.firstName, student.surName, student.gender, &student.id,
                  &student.age) != EOF) {
        *tree = insert(*tree, student);
    }
    fclose(file);
}

int main() {
    struct AVLTree *tree = NULL;
    int choice;
    do {
        printf("1. Add student record.\n");
        printf("2. Delete student record.\n");
        printf("3. Search student record.\n");
        printf("4. Print student records.\n");
        printf("5.read from file.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(&tree);
                break;
            case 2:
                deleteStudent(&tree);
                break;
            case 3:
                searchStudent(tree);
                break;
            case 4:
                printStudents(tree);
                break;
            case 5:
                readFromFile(&tree);
                break;
            case 6:
                printf("exiting...");
                return 0;
            default:
                printf("Invalid choice.");
        }
    } while (choice != 6);
    return 0;
}


