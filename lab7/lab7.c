#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _student{
    char rollNo[10];
    char name[100];
    char email[40];
    struct _student *next;
    struct _student *rnext;
    struct _student *nnext;
    struct _student *enext;
};

typedef struct _student student;
typedef student *studentPointer;
 
studentPointer createNode(char rollNo[], char name[], char email[]){
    studentPointer new_node = (studentPointer) malloc(sizeof(studentPointer));
    strcpy(new_node->rollNo, rollNo);
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    new_node->rnext = NULL;
    new_node->nnext = NULL;
    new_node->enext = NULL;
    return new_node;
}

void InsertNode(studentPointer *head, studentPointer node){
    studentPointer last = *head;
    if(*head == NULL){
        *head = node;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = node;
}

void print(student *node){
    while(node != NULL){
        printf("%s %s %s", node->rollNo, node->name, node->email);
        node = node->next;
    }
}

int main(){
    FILE *in_file = fopen("ass1.in", "r");
    if(in_file == NULL){
        printf("Error! File does not open\n");
        exit(-1);
    }
    else{
        student *head = NULL;
        char line[150];
        while(fgets(line,150, in_file)){
            char rollno[10];
            char name[100];
            char email[40];
            scanf(line, "%[,],\"%[^\"]\",%s", rollno, name, email);
            studentPointer node = createNode(rollno, name, email);

        }
        print(head);
    }
    return 0;
}