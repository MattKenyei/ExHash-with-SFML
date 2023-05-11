#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
public:
    HashTable(int capacity);

    void insert(int value);

    bool contains(int value);

    void remove(int value);

    void display();

private:
    int size;
    int capacity;
    int level;
    vector<vector<int>> table;
    sf::RenderWindow window;
    sf::RectangleShape square;

    int hash(int value);

    bool contains(int value, int hash_value);

    void expand();

    void drawTable();
};
