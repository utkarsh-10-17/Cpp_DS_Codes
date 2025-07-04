#include <iostream>
using namespace std;

int sumofdividors(int n)
{
    int totalSum = 0;

    // Iterate over all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        int sum = 0;

        // Calculate sum of divisors for the current number 'i'
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }

        // Add the sum of divisors to the total sum
        totalSum += sum;
    }

    cout<< totalSum;
}

int gcd(int a , int b)
{
    while(a>0 && b>0)
    {
        if(a>b) a = a%b;
        else b = b % a;
    }
    if(a==0) cout<< b;
    cout<< a;
}




int main() {

    int n ;
    cin>>n;

    int a,b;
    cin>>a>>b;

    gcd(  a ,   b);

    /*int dup = n;
    int sum = 0;
    while(n > 0)
    {
        int last_digit = n % 10;
        sum = sum + (last_digit*last_digit*last_digit);
    }
    if (sum == dup) cout<<"Yes";
    else cout<<"No";
     */

    return 0;
}
