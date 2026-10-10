#include <iostream>

int main() {
    LinkedList list;

    list.insertHead(2);
    list.insertHead(1);
    list.insertTail(3);

    vector<int> values = list.getValues();

    for (int x : values) {
        cout << x << " ";
    }
    // Output: 1 2 3

    list.remove(1);

    values = list.getValues();

    for (int x : values) {
        cout << x << " ";
    }
    // Output: 1 3
}