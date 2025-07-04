#include<iostream>
using namespace std;

void MinMaxElement(int*arr , int size , int *min ,int *max)
{
    *min = *max = *arr;

   for(int i = 1 ; i<size ;i++)
   {
    if(*(arr+i)<*min)
    {
        *min = *(arr+i);
    }
      if(*(arr+i)>*max)
    {
        *max = *(arr+i);
    }

   }
   cout<<endl;
}

int main(){

    int size;

    cout<<"enter size of the array "<<endl;
    cin>>size;

    int *arr = new int[size];

    cout<<"enter elements"<<endl;

    for(int i=0;i<size ;i++)
    {
        cin>>*(arr + i);
    }

    int min , max;

    MinMaxElement(arr,size,&min,&max);

    cout<<"min Element "<<min<<endl;
    cout<<"max Element "<<max<<endl;

    delete  []arr;

return 0;
}