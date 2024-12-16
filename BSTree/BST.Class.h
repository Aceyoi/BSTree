﻿//Сапожников Юрий ИВТ-22
#pragma once

﻿//Сапожников Юрий ИВТ-22

#include <iostream>
#include <chrono>
#include <cassert> // Для использования assert
#include <vector>

using namespace std;
using namespace chrono;

// Узел дерева бинарного поиска
struct Node {
    int value;         // Значение узла
    Node* left;        // Левый потомок
    Node* right;       // Правый потомок

    // Конструктор узла
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Класс для дерева бинарного поиска
class BST {
private:
    Node* root; // Корень дерева

    // Рекурсивная функция для вставки значения в дерево
    Node* insert(Node* node, int value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Рекурсивная функция для поиска значения
    bool search(Node* node, int value) {
        if (!node) {
            return false;
        }
        if (value == node->value) {
            return true;
        }
        else if (value < node->value) {
            return search(node->left, value);
        }
        else {
            return search(node->right, value);
        }
    }

    // Рекурсивная функция для удаления узла
    Node* remove(Node* node, int value) {
        if (!node) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        }
        else if (value > node->value) {
            node->right = remove(node->right, value);
        }
        else {
            // Узел найден
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                // Узел имеет двух потомков
                Node* temp = findMin(node->right);
                node->value = temp->value;
                node->right = remove(node->right, temp->value);
            }
        }
        return node;
    }

    // Функция для поиска минимального значения в дереве
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Рекурсивная функция для вывода дерева (обход LNR)
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

public:
    // Конструкторы дерева
    BST() : root(nullptr) {} // Без параметров

    explicit BST(int value) { // С одним параметром
        root = new Node(value);
    }

    BST(const initializer_list<int>& values) : root(nullptr) { // С параметрами (список значений)
        for (int value : values) {
            insert(value);
        }
    }

    // Вставка значения в дерево
    void insert(int value) {
        root = insert(root, value);
    }

    // Поиск значения в дереве
    bool search(int value) {
        return search(root, value);
    }

    // Удаление значения из дерева
    void remove(int value) {
        root = remove(root, value);
    }

    // Обход дерева (симметричный)
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

