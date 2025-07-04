#include <iostream>
using namespace std;

int reverse(int n)
{
    //int cnt = 0;
    int rev = 0;
    while(n>0)
    {
        int last_digit = n%10;
        n = n/10;
        //cnt = cnt + 1;
        rev = (rev * 10) + last_digit;
    }
    cout<<rev;
}

int count(int n)
{
    int cnt = 0;
    while(n>0)
    {
        // int last_digit = n%10;
        n = n/10;
        cnt = cnt + 1;
    }
    cout<<cnt;
}


int main() {
    int n;
    cin >> n;
    //reverse(n);

}
