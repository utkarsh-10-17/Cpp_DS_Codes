#include <bits/stdc++.h>
using namespace std;

int facto(int n) {

    if(n <=0)return 1;
    return n*facto(n-1);

}



int main()
{
    int n = 4;


    for (int i = 1;i< n ; i++)
    {
        cout<<i<<" ";
    }
    
    return 0;
}