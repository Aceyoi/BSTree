﻿//Сапожников Юрий ИВТ-22

#include <iostream>
#include <chrono>
#include <cassert> // Для использования assert
#include <vector>
#include "BST.Class.h"
#include "BST.Test.h"

using namespace std;
using namespace chrono;


int main() {
    // Установить локаль для корректного вывода русского текста
    setlocale(LC_ALL, "Russian");

    testcheck();

    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "\nSearch for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;

    tree.remove(40);
    cout << "Inorder traversal after removing 40: ";
    tree.inorder();


    timePlot();

    return 0;
}
