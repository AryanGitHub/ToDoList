#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#define p printf
#define s scanf
#define and &&
#define or ||
#define equ ==
#define not_equ !=
#define greater >
#define less <
#define great_equ >=
#define less_equ <=


void change_color(char* color);
void color_animation(char color_list[][3], int* time_list, int n);
void wlcScreen();
void seeTodo(int do_pause);
void CreateOrUpdateTodo();
void fixcount();
void DeleteTodo();
int listExists();
void chooseColor();
int mainMenu();


struct todo{
    int count;
    char data[50];
    struct todo* next;
};

static struct todo *start= NULL;

void main(){
    int choice;
    wlcScreen();
    system("cls");
    

    while(1){
        choice = mainMenu();
        switch(choice){
        case 1:
            seeTodo(1);
            break;
        case 2:
            CreateOrUpdateTodo();
            break;
        case 3:
            DeleteTodo();
            break;
        case 4:
            chooseColor();
            break;    
        case 5:
            system("cls");
            exit(0);
        }

    }
}
int listExists(){
    /*
    returns 1 if list already exist
    otherwise it returns 0
    */
    return (start not_equ NULL);
}

void change_color(char* color){
    char finalcommand[100]="color ";
    strcat(finalcommand,color);
    system(finalcommand);
}


void color_animation(char color_list[][3], int* time_list, int n){
int i =0;
for (;i<n;i++){
//char color[3] = *(color_list+i);
change_color(color_list[i]);
//delay(*(time_list+i));
Sleep(*(time_list+i));
}
}

void wlcScreen(){
    system("color f0");
    char c;
    system("cls");
    printf("\n\n\n\n      ");

    c=215;
    printf("\n\t\t\t\t\t         /-+-+-+-+-+-+-+-+-+-\\");
    printf("\n\t\t\t\t\t        /                     \\");
    printf("\n\t\t\t\t\t       /                       \\");
    printf("\n\t\t\t\t\t      /                         \\");
    printf("\n\n");


    // first line
    printf("\t\t\t\t\t%c%c%c%c%c%c",c=176,c=176,c=177,c=177,c=178,c=178);
    printf("\t\t\t\t %c%c%c%c%c%c",c=178,c=178,c=177,c=177,c=176,c=176);
    printf("\n\n\t       ");


    // second line
    // diamonds
    c=4;
    for(int i=0; i<10; i++){
        printf("-%c",c);
    }
    // heart
    c=3;
    for(int i=0; i<5; i++){
        printf("--%c",c);
    }

    printf("    %cl %c  l l %c    ",c=195,c=137,c=153);




    // heart
    c=3;
    for(int i=0; i<4; i++){
        printf("%c--",c);
    }

    printf("%c-",c);
   // diamonds
    c=4;
    for(int i=0; i<10; i++){
        printf("-%c",c);
    }
    printf("-\n");

    // third line
    c=157;
    printf("\n\t\t\t   ------ %c ------\t\t\t\t    ------ %c ------",c,c);


    // fourth line
    c=153;
    printf("\n\t\t\t\t\t\t\t   %c",c);


    // fifth line
    c=240;
    printf("\n\t\t\t\t\t\t\t ");
    for(int i=0; i<5; i++){
        printf("%c",c);
    }

    // sixth line
    c=194;
    printf("\n\t\t\t\t\t\t\t   %c",c);

    // seventh line
    printf("\n\t\t\t\t\t\t\t   |");

    // eighth line
    printf("\n\t\t\t\t\t\t\t   |");

    // ninth line
    printf("\n\t\t\t\t\t\t\t   |");

    // tenth line
    printf("\n\t\t\t\t\t\t\t   |");

    char color_list[8][3]= {"f1","f2","f4","f0","f4","f3","f2","f1"};
    int time_list[8]={100,100,100,100,100,100,100,100};

    color_animation(color_list,time_list, 8);



    //printf("\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\t      ");

    system("pause");
}
void chooseColor(){
    system("cls");
    int colorNumber;
  printf("\n\n\n\n\n\n\n\n\n\n\n                                            WHICH FONT COLOR FONT YOU WANT TO BE YOUR MAIN\n                                              1-BLUE 2-GREEN 3-RED 4-PURPLE : ");
    scanf("%d",&colorNumber);
    if(colorNumber==1){
        change_color("f1");
    }
    else if(colorNumber==2)
    {
        change_color("f2");
    }
    else if(colorNumber==3)
    {
        change_color("f4");
    }
    else if(colorNumber==4)
    {
        change_color("f5");
    }
    else {
        printf("\n\n\n\n\n\n\n\n\n\n\n                                            Invalid Response.\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n                                            Try Again in 3 seconds.\n");
        Sleep(3000);
        chooseColor();
 }


}

int mainMenu(){
    int choice;


    system("cls");
    //
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    printf("\n\n\n\n                                                 %s", asctime(ptr));
    //
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t 1. See your ToDo List. \n");
    if (listExists()){
        printf("\n\t\t\t\t\t\t 2. Update your ToDo List. \n");
    }
    else {
        printf("\n\t\t\t\t\t\t 2. Create your ToDo List. \n");
    }
    printf("\n\t\t\t\t\t\t 3. Delete your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 4. Change Font Color \n");
    printf("\n\t\t\t\t\t\t 5. Exit ");
    printf("\n\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t Enter your choice \n\t\t\t\t\t\t --> ");

    scanf("%d",&choice);
    return choice;
}

void seeTodo(int do_pause){
    system("cls");
    struct todo *temp;
    temp = start;
    if(start equ NULL)
    {
        printf("\n\t\t\t\t\t\t Empty list");
    }
    else
    {
        while(temp not_equ NULL)
        {
            printf("\n\t\t\t\t\t\t %d . ",temp->count);
            puts(temp->data);
            fflush(stdin);
            temp = (temp->next);
        }
    }
    printf("\n\t\t\t\t\t\t");
    if (do_pause)
    system("pause");

}

struct todo* todoNodeCpy (struct todo* todoNode1 , struct todo* todoNode2){

    strcpy (todoNode1->data, todoNode2->data);
    return todoNode1;
}

struct todo* creatNewNode(){
    struct todo* newNode = (struct todo*) malloc(1*sizeof(struct todo));
    newNode->next = NULL;
    return newNode;
}

struct todo* addNode(struct todo* todoNode){
    struct todo* creatNewNode();

    todoNode->next = creatNewNode();
    return todoNode->next;
}

struct todo* addNextNode (struct todo* todoNode, struct todo element){
    struct todo* getLastNode(struct todo* todoNode);
    struct todo* addNode(struct todo* todoNode);
    struct todo* todoNodeCpy (struct todo* todoNode1 , struct todo* todoNode2);

    struct todo* lastNode = getLastNode(todoNode);
    int lastNodeCountValue = lastNode->count;
    lastNode = addNode(lastNode);
    todoNodeCpy(lastNode,&element);
    lastNode->count = ++lastNodeCountValue;
    return lastNode;
}

struct todo* getNextNode(struct todo* todoNode) {
    return todoNode->next;
}

struct todo* getLastNode(struct todo* todoNode){
    struct todo* getNextNode(struct todo* todoNode);
    struct todo* nextNode = getNextNode(todoNode);
    if (nextNode == NULL) return todoNode;
    else return getLastNode(nextNode);
}


void CreateOrUpdateTodo(){
    struct todo* creatNewNode();
    struct todo* addNextNode (struct todo* todoNode, struct todo element);

    char a[500];
    system("cls");

    while(1){
        printf("\n\t\t\t\t\t\t Want to add? y/n \n\t\t\t\t\t\t -->");
        fflush(stdin);
        s("%s",a);

        if(a[0] equ'y' && a[1] equ '\0')
        {
            if(start equ NULL)
            {
                start = creatNewNode();
                start->count = 1;
                printf("\n\t\t\t\t\t\t Write 1st list here \n\t\t\t\t\t\t --> ");
                fflush(stdin);
                gets(start->data);
                
                
            }
            else
            {

               
                printf("\n\t\t\t\t\t\t Write another list here \n\t\t\t\t\t\t --> ");
                fflush(stdin);
                struct todo tempNode;
                gets(tempNode.data);
                addNextNode (start,tempNode);
            }
        }
        if(a[0]=='n'&& a[1]=='\0')
        {
            break;
        }
    }


}

void fixcount(){
    struct todo *ptr;
    int i=1;
    ptr = start;
    while(ptr not_equ NULL)
    {
        ptr->count = i;
        i++;
        ptr= ptr->next;
    }
}

void DeleteTodo(){
    system("cls");
    if(start not_equ NULL){
    seeTodo(0);
    int a;
    struct todo *ptr,*ptr1;   // points to starting list
     // points to next list for tracing
    printf("\n\t\t\t\t\t\t Enter the number you want to delete \n\t\t\t\t\t\t --> ");
    s("%d",&a);

    ptr = start;
    ptr1 = start->next;
    while(1)
    {
        // first condition
        // if we want to delete fist node
        if(ptr->count equ a)
        {
            start=start->next;
            free(ptr);
            fixcount();
            break;
        }
        // second condition
        // if we want to delete other node
        if(ptr1->count equ a)
        {
            ptr->next=ptr1->next;
            free(ptr1);
            fixcount();
            break;
        }
        else
        {
            ptr = ptr1;
            ptr1 = ptr1->next;
        }

    }
}
    else {
            printf("\n\t\t\t\t\t\t Cannot delete as list is empty.\n\t\t\t\t\t\t");
            system ("pause");
    }
}

