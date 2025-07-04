#include <iostream>
#include <array>
#include <stack>

using namespace std;

int main()
{

  /* array<int, 4> a = {1, 2, 3, 4};
    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    cout << "Element at 2nd Index ->" << a.at(2) << endl;
    cout << "Empty or not->" << a.empty() << endl;
    cout << "First Element->" << a.front() << endl;
    cout << "Last Element->" << a.back() << endl;*/

//stack creation
    stack<int>s;

//push operation -> adds element to stack LIFO
    s.push(2);
    s.push(3);

    //pop operation -> top element removed
    s.pop();

    cout<<"Printing the top element "<<s.top()<<endl;


    if(s.empty())
    {
        cout<<"The stack is empty"<<endl;
    }

    else
    {
        cout<<"The stack is not empty"<<endl;
    }

   cout<<"The size of stack is "<<s.size()<<endl;

    return 0;
}