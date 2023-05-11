#include "HashTable.h"

int main() {
    HashTable ht(10);

    while (ht.display(), true) {
        cout << "Enter a command (insert, remove, exit): ";
        string command;
        cin >> command;

        if (command == "insert") {
            cout << "Enter a value to insert: ";
            int value;
            cin >> value;
            ht.insert(value);
        }
        else if (command == "remove") {
            cout << "Enter a value to remove: ";
            int value;
            cin >> value;
            ht.remove(value);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
