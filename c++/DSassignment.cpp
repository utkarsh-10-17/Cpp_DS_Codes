#include<iostream>
using namespace std;
#define size 10

class stack{
    public:
        char a[size];
        int top;
    char peek(){
    return this->a[this->top];}
};


void push(stack *temp,char v){
    if(temp->top == size-1)
    {
        cout<<"Car can't enter as the Lane is full "<<endl;
    }
    else{
        temp->top+=1;
        temp->a[temp->top]=v;
    }
} 

int pop(stack *temp)
{
    int i,c=0;
    if(temp->top != -1 && temp->a[temp->top] == 'D')
    {   
        for(i=temp->top-1;i>-1;i--)
            {
                if(temp->a[i] == 'D')
                    c++;
            } 
    }
    temp->top--;
    return c;
}

int main(){
    char car[size][2];
    stack var; var.top=-1;
    int c;

    for(int i=0;i<=size;i++){
        cout<<"Enter the Car Details : "<<endl;
        cin>>car[i][0]; cin>>car[i][1];
        push(&var,car[i][0]);       
    }

    for(int i=0;i<size;i++){
        c = pop(&var);
        cout<<"The car no."<<car[i][1]<<" was moved out "<<c<<" times to allow other cars to depart."<<endl;
    }

    return 0;
}