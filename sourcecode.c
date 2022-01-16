#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>


void changeColor(char* color);
void color_animation(char color_list[][3], int* time_list, int n);
void wlcScreen();
void seeTodo(int do_pause);
void CreateOrUpdateTodo();
void fixcount();
void DeleteTodo();
int listExists();
void chooseColor();
int mainMenu();
void inputPassword( char* password);
void login();


struct todo{
    int count;                          // Used to index one task of the ToDo List
    char data[50];                      // Used to store the task
    struct todo* next;                  // Used to link next node of task
};

static struct todo *start= NULL;        // Used to create the head node of the Linked List (First Node)

void main(){
    int choice;
    login();  
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
    return (start != NULL);
}

void changeColor(char* color){              // This function is used to change the color of the terminal
    char finalcommand[100]="color ";        // Initial command string  
    strcat(finalcommand,color);             // Concatenating color command string to the arguments
    system(finalcommand);                   // Sending the final command to the Terminal to change the color
}


void color_animation(char color_list[][3], int* time_list, int n){    // This function is used for color transition animation in welcome screen
int i =0;                                                              
for (;i<n;i++){
changeColor(color_list[i]);                                           // Used for changing color from the color list given in the code
Sleep(*(time_list+i));                                                // Used for setting time delay between two color transition
}
}

void inputPassword( char* password){
/*
    Author: Sai Kalyan Raju

    Function Decryption: This function is used to hide the password with "*".
*/


 int p=0;
    do{
        password[p]=getch();
        if(password[p]!='\r')	      //"\r" is used to check when enter key is pressed.
	     printf("*");	      //It hides actual password with "*".
        p++;
    }while(password[p-1]!='\r');     //End of do while.
    password[p-1]='\0';		     //To end the password string by null "\0" charecter.

}

void login(){                      // Function used for entering username, password and providing access to ToDo List
    system("color f0");  
	int a=0,i=0;                   // here "a" is used for counting the unsucessful attempts 
    char uname[10];
    char pword[10];
    char user[10]="live";          // Username used in ToDoList
    char pass[10]="evil";          // Password used in ToDoList
    do
    {
        system("color f0");
        printf("\n  #--------------------------  LOGIN  --------------------------#  ");
        printf("\n\n                          Enter Username: ");
        scanf("%s", uname);
        printf("\n                          Enter Password: ");
		inputPassword(pword);                                              // Function used for hiding the user inputted password
        if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
        {
            printf("\n\n\n  >>                     Login successful                      <<");
            system("color f0");
            Sleep(700);
            system("cls");
            system("color f0");
            printf("\n  ---------------------------------------------------------  ");
            printf("\n  >>>>>>>>>>>>  WELCOME TO EMPLOYEE DIRECTORY  <<<<<<<<<<<<  ");
            printf("\n  ---------------------------------------------------------  ");
 
            printf("\n\n                Initializing, please wait ");          // this is a cosmetic part to show a loading screen for some seconds
            for(i=1; i<=9; i++)
            {
                printf(".");
                Sleep(300);
            }
            printf("\n\n                Press any key to continue ...");
            getch();
            break;
        }
        else
        {
            system("color 0f");
            printf("\n\n\n  !!                     Login unsuccessful                    !!");
            printf("\n                     Press any key to try again                  ");
            a++;                                 
            //getch();
            system("pause");
            system("cls");                       // clears the screen
        }
    }
	while(a<=2);
	{
        if (a>2)
        {
            system("color 0f");
            printf("\n  #--------------------------  ERROR  --------------------------# ");
            printf("\n  !!!                                                         !!! ");
            printf("\n  !!!        Directory Locked, too many wrong attempts        !!! ");
            printf("\n  !!!                 Please read info.txt and                !!! ");
            printf("\n  !!!                  re-execute the program                 !!! ");
            printf("\n  !!!                                                         !!! ");
            printf("\n  #-------------------------------------------------------------# \n");
 
            printf("\n\n  Press any key to EXIT...");
            getch();
            exit(1); // unsuccessful exit
        }
	}
    system("cls");
}

void wlcScreen(){
  /* prints the UI of the welcome screen*/
    system("color f0");          // changes the colour to black and white.
    char c;
    system("cls");          // clears the screen.
    printf("\n\n\n\n      ");

    c=215;
    printf("\n\t\t\t\t\t         /-+-+-+-+-+-+-+-+-+-\\");          // all these printf statments are being used to make the UI for the welcome screen.
    printf("\n\t\t\t\t\t        /                     \\");          //the values which are being assigned to "char c" are ascii values.
    printf("\n\t\t\t\t\t       /                       \\");           // which are used to achieve certain symbols and designs for the welcome screen.
    printf("\n\t\t\t\t\t      /                         \\");
    printf("\n\n");


    // first line
    printf("\t\t\t\t\t%c%c%c%c%c%c",c=176,c=176,c=177,c=177,c=178,c=178);
    printf("\t\t\t\t %c%c%c%c%c%c",c=178,c=178,c=177,c=177,c=176,c=176);
    printf("\n\n\t       ");


    // second line

    c=4;
    for(int i=0; i<10; i++){
        printf("-%c",c);          // this prints diamonds
    }

    c=3;
    for(int i=0; i<5; i++){
        printf("--%c",c);          //this prints a heart
    }

    printf(" Welcome to ToDo List ");




    // heart
    c=3;
    for(int i=0; i<4; i++){
        printf("%c--",c);          //this prints a heart
    }

    printf("%c-",c);
                              // this also prints diamonds
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

    system("pause");          //this will pause the program and say "Press any key to continue . . .", after pressing any key.
}                             //the control exits the wlcScreen function and comes to void choosecolor().
void chooseColor(){
  /* chooseColor function let's  us deside in which color do we want the
  UI to be in.
  */
    system("cls");          // clears the screen.
    char colorInput[3];
    printf("\n\n\n\n\n\n\n\n\n\n\n                                            WHICH COLOR YOU WANT?\n");
    printf("%80s","Type Background letter folowed by Font letter.\n");
    printf("%s","                                            0 = Black       8 = Gray\n");
    printf("%s","                                            1 = Blue        9 = Light Blue\n");          //printing all the possible color's we can use in C language cmd.
    printf("%s","                                            2 = Green       A = Light Green\n");
    printf("%s","                                            3 = Aqua        B = Light Aqua\n");
    printf("%s","                                            4 = Red         C = Light Red\n");
    printf("%s","                                            5 = Purple      D = Light Purple\n");
    printf("%s","                                            6 = Yellow      E = Light Yellow\n");
    printf("%s","                                            7 = White       F = Bright White\n");
    printf("%s","                                                           ");
    scanf("%s",colorInput);                                                                                //taking input from the user.

    if ( (colorInput[0] >= '0' && colorInput[0] <= '9') || (colorInput[0] >= 'A' && colorInput[0] <= 'F') || (colorInput[0] >= 'a' && colorInput[0] <= 'f')){
    if ( (colorInput[1] >= '0' && colorInput[1] <= '9') || (colorInput[1] >= 'A' && colorInput[1] <= 'F') || (colorInput[1] >= 'a' && colorInput[1] <= 'f')){
                changeColor(colorInput);
        }                                                  //cheching if the user has given a valid Input.
    }
    else {
        printf("                                            Invalid Response.\n");           //if the given input is not in the specified format, this else statment gets executed.
        printf("                                            Try Again in 3 seconds.\n");    // and prints Invalid Response, and Try again in 3 Seconds.
        Sleep(3000);                                                                       //this sleep(3000); function stops the program for 3000 milliseconds.
        chooseColor();                                                                    //Again the chooseColor(); function is called so the user can have another try.
     }


}

int mainMenu(){
    int choice;


    system("cls");          //clears the screen.
    //
    struct tm* ptr;
    time_t t;
    t = time(NULL);          //these five lines of code take the time as an input from windows.h(header file).
    ptr = localtime(&t);    //And prints it on the main menu.
    printf("\n\n\n\n                                                 %s", asctime(ptr));
    //
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t 1. See your ToDo List. \n");             //printing all the contents of the main menu.
    if (listExists()){                                             // here in this if else stament if we have alredy created a todolist.
        printf("\n\t\t\t\t\t\t 2. Update your ToDo List. \n");    //listExists(); fuctions returns "1" and if statment will be executed.
    }                                                            //And prints update your todolist, in case if there is no todolist else stament get's executed.
    else {                                                      //which prints create your todollist.
        printf("\n\t\t\t\t\t\t 2. Create your ToDo List. \n");
    }
    printf("\n\t\t\t\t\t\t 3. Delete your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 4. Change Font Color \n");
    printf("\n\t\t\t\t\t\t 5. Exit ");
    printf("\n\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t Enter your choice \n\t\t\t\t\t\t --> ");

    scanf("%d",&choice);          //takes input from the user and returns to void main();
    return choice;
}

void seeTodo(int do_pause){
    system("cls");
    struct todo *temp;
    temp = start;
    if(start == NULL)
    {
        printf("\n\t\t\t\t\t\t Empty list");
    }
    else
    {
        while(temp != NULL)
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
        scanf("%s",a);

        if(a[0] =='y' && a[1] == '\0')
        {
            if(start == NULL)
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
    while(ptr != NULL)
    {
        ptr->count = i;
        i++;
        ptr= ptr->next;
    }
}

void DeleteTodo(){
    system("cls");
    if(start != NULL){
    seeTodo(0);
    int a;
    int flagFound = 0;
    printf("\n\t\t\t\t\t\t Enter the Index you want to delete \n\t\t\t\t\t\t --> ");
    scanf("%d",&a);
    
    if (a==1){
         
         struct todo* NodeToDelete = start;
         start = start -> next;
         free(NodeToDelete);
         flagFound=1;

    }
    else {
    struct todo* loopCounter = start;
    while(loopCounter -> next != NULL)
    {

        if(loopCounter->next->count == a)
        {
            struct todo* NodeToDelete = loopCounter->next;
            loopCounter->next = NodeToDelete->next;
            free(NodeToDelete);
            flagFound =1;
            break;
        }

        loopCounter = loopCounter->next;

    }
    }
    if (!flagFound){
        printf("\n\t\t\t\t\t\t Index Not Found. \n\t\t\t\t\t\t");
        system ("pause");
    }
    else{
        fixcount();
    }
}
    else {
            printf("\n\t\t\t\t\t\t Cannot delete as list is empty.\n\t\t\t\t\t\t");
            system ("pause");
    }
}

