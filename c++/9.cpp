#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;

  int i = 1;

  //for 1st triangle
   while(i<=n)
   {
      int space = n-i;;
      while(space)
      {
         cout<<" ";
         space--;
      }
      //for 2nd triangle

      int j = 1;
      while(j<=i)
      {
         cout<<j;
         j++;
      }

      //for 3rd triangle
     int start = i-1;
      while(start)
      {
         cout<<start;
         start--;
      }
      cout<<endl;
      i++;
   }
  
return 0;
}