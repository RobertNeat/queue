#include <iostream>

//random number generation (+ cls):
#include <stdlib.h>
#include <time.h>

#include <fstream>

using namespace std;
///STACK IMPLEMENTATION///
struct element{
    char character;
    element* next;
};

struct queue{
    element* head;
    element* tail;
};

void push(queue &q, char value){    //add element to queue
    element* el=new element;
    el->character=value;
    el->next=nullptr;
    if(q.tail!=nullptr){
        q.tail->next=el;
    }
    else{
        q.head=el;
    }
    q.tail=el;
}

void pop(queue &q){     //drop element from queue
    element* temp=q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head==nullptr){
        q.tail=nullptr;
    }
}

bool isEmptyQ(queue q){      //check if queue is empty
    if(q.head==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void first(queue q){        //reads first element from queue
    cout<<q.head->character;
}
//////////////////////////PROGRAM MENU//////////////////////////////////////////
void line(){cout<<"-------------------------------------------------------\n";}
void menu(int &a){
line();
cout<<"Menu (number 1-6):"<<endl
<<"1. check if queue is empty"<<endl
<<"2. generate random number and add to queue"<<endl
<<"3. drop element from queue"<<endl
<<"4. display first element from queue"<<endl
<<"5. drop all elements from queue"<<endl
<<"6. read only big letters from \"data.txt\" file"<<endl;
line();
cout<<"Choose:";
cin>>a;
system("cls");
}

void isEmpty(queue &q){    //check if queue is empty
    if(isEmptyQ(q)){
        cout<<"Queue is empty"<<endl;
    }else{
    cout<<"Queue have elements"<<endl;}
}

void generateChar(queue &q){       //generate random character and adds to queue
    //generate small letter as ASCII: 97-122
    push(q,rand()%26+'a');
    cout<<"Generated:";
    first(q);
    cout<<endl;
}

void deleteChar(queue &q){        //drop character from queue
    if(isEmptyQ(q)==true){
        cout<<"Queue id empty"<<endl;
    }
    else{
    cout<<"Dropped 1 character"<<endl;
    pop(q);
    }
}
void displayCharacter(queue &q){        //display last character
    if(isEmptyQ(q)==false){
    cout<<"First element:";
    first(q);
    cout<<endl;
    }
    else{
        cout<<"Empty queue"<<endl;
    }
}
void dropAll(queue &q){       //drop all ements from queue and display them
    if(isEmptyQ(q)==true){
        cout<<"Queue empty alredy"<<endl;
    }else{
        while(!isEmptyQ(q)){
        cout<<"Delete file:";
        first(q);
        cout<<endl;
        pop(q);
        }
    }
}

void readChars(queue &q, ifstream &file){        //reads only BIG characters from file
    string textLine;
    while(!(file.eof())){
        getline(file, textLine);

        for(int a=0;a<textLine.length();a++){
            if(int(textLine[a])>=65 && int(textLine[a]) <=90){
                push(q,textLine[a]);
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
    //queue initialization
    queue q;
    q.head=nullptr;
    q.tail=nullptr;

    srand  (time(NULL));//<- for generating numbers

    ifstream file;
    file.open("data.txt");

    int choice;
    menu(choice);

    while(choice>=1 && choice<=6){
    switch(choice){
        case 1:
            isEmpty(q);
        menu(choice);
        break;
        case 2:
            generateChar(q);
        menu(choice);
        break;
        case 3:
            deleteChar(q);
        menu(choice);
        break;
        case 4:
            displayCharacter(q);
        menu(choice);
        break;
        case 5:
            dropAll(q);
        menu(choice);
        break;
        case 6:
            readChars(q,file);
        menu(choice);
        break;
    }}

    return 0;
}
