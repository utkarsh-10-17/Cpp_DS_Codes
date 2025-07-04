#include <iostream>

int main() {
    const int size = 10;
    int numbers[size];
 
    std::cout << "Enter 10 values: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    int largest = numbers[0];
    int secondLargest = numbers[0];

    for (int i = 1; i < size; ++i) {
        if (numbers[i] > largest) {
            secondLargest = largest;
            largest = numbers[i];
        } else if (numbers[i] > secondLargest && numbers[i] < largest) {
            secondLargest = numbers[i];
        }
    }

    if (secondLargest == largest) {
        std::cout << "There is no second largest element." << std::endl;
    } else {
        int difference = largest - secondLargest;
        std::cout << "Difference between last and second largest elements: " << difference << std::endl;
    }

    return 0;
}
