﻿//Сапожников Юрий ИВТ-22
#pragma once

#include <iostream>
#include <chrono>
#include <cassert> // Для использования assert
#include <vector>
#include "BST-Class.h"

using namespace std;
using namespace chrono;

// Тестирование
void testcheck() {
    
}

// Замер времени выполнения
void timePlot() {
    BST tree;
    constexpr int N = 100000;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        tree.insert(i);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time to insert " << N << " elements: " << duration.count() << " ms\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        tree.search(i);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "Time to search " << N << " elements: " << duration.count() << " ms\n";
}