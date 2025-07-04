#include <iostream>
using namespace std;

class aplha
{
protected:
    int a;

public:
    aplha()
    {
        cout << "The default constructor of class alpha  is called   " << endl;
    }
    aplha(int x)
    {
        a = x;
    }
};
class beta
{
protected:
    int b;

public:
    beta()
    {
        cout << "The default constructor of class beta is called " << endl;
    }

    beta(int y)
    {
        b = y;
    }
};
class gamma : public aplha, public beta
{
public:
    gamma()
    {
        cout << "The default constructor of derived class is called" << endl;
    }
};
int main()
{

    gamma ob;

    return 0;
}