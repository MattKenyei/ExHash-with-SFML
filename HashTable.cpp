#include "HashTable.h"
HashTable::HashTable(int capacity) 
{
    size = 0;
    level = 1;
    this->capacity = capacity;
    table.resize(capacity);
    window.create(sf::VideoMode(800, 600), "Hash Table");
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(2);
}

void HashTable::insert(int value) 
{
    int hash_value = hash(value);
    if (!contains(value, hash_value)) 
    {
        table[hash_value].push_back(value);
        size++;
        if (size > capacity * level) 
        {
            level++;
            expand();
        }
        drawTable();
    }
}

bool HashTable::contains(int value) {
    int hash_value = hash(value);
    return contains(value, hash_value);
}

void HashTable::remove(int value) {
    int hash_value = hash(value);
    for (int i = 0; i < table[hash_value].size(); i++) 
        if (table[hash_value][i] == value) 
        {
            table[hash_value].erase(table[hash_value].begin() + i);
            size--;
            drawTable();
            return;
        }
}

void HashTable::display() {
    for (int i = 0; i < capacity; i++) 
    {
        cout << i << ": ";
        for (int j = 0; j < table[i].size(); j++) 
            cout << table[i][j] << " ";
        cout << endl;
    }
}
int HashTable::hash(int value) 
{
    return value % capacity;
}

bool HashTable::contains(int value, int hash_value) {
    for (int i = 0; i < table[hash_value].size(); i++) 
        if (table[hash_value][i] == value)
            return true;
    return false;
}

void HashTable::expand() 
{
    int new_capacity = capacity * 2;
    vector<vector<int>> new_table(new_capacity);
    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < table[i].size(); j++) 
        {
            int value = table[i][j];
            int hash_value = value % new_capacity;
            new_table[hash_value].push_back(value);
        }
    }
    capacity = new_capacity;
    table = new_table;
    drawTable();
}

void HashTable::drawTable() 
{
    window.clear();

    // calculate the size of each square
    int square_size = min(window.getSize().x / capacity, window.getSize().y / level);

    // draw the squares for each element in the table
    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            square.setSize(sf::Vector2f(square_size, square_size));
            square.setPosition(i * square_size, j * square_size);
            square.setFillColor(sf::Color::Green);
            window.draw(square);
        }
    }

    window.display();
}
