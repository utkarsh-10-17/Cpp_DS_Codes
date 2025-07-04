#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string str = "apple;banana;cherry;date";
    stringstream ss(str);
    string item;
    vector<string> fruits;

    while (getline(ss, item, ';')) {
        fruits.push_back(item); // Split by custom delimiter ';'
    }

    // Print the result
    for (const string& fruit : fruits) {
        cout << fruit << endl;
    }
}
