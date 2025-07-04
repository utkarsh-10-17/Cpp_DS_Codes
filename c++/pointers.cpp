#include<iostream>
using namespace std;
int main(){


int n = 6;
int*ptr = &n;

// same ting
cout<<n<<endl;
cout<<*ptr<<endl;

int *p = 0;
p = &n;

cout<<*p<<endl;
cout<<p<<endl;

int a = 69;
int*x = &a;

cout<<"befhore "<<a<<endl;
(*x)++;
cout<<"after "<<a<<endl;

int *y = x;

cout<<y<<endl;
cout<<*y<<endl;


int i =3 ;
int *t = &i;

*t = *t + 1;

cout<<*t<<endl;
cout<<t<<endl;
t = t + 1;
cout<<t<<endl;

return 0;
}