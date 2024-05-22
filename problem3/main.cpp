#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    
    std::map<int, int> myMap;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int num : numbers) {
        myMap[num] = 1; 
    }

    std::cout << "Уникальные номера: ";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << " ";
    }
    std::cout << std::endl;

    
    std::vector<int> container = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // a
    container.erase(container.begin() + 3);
    std::cout << "После удаления 4-го элемента: ";
    for (int num : container) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // b
    container.insert(container.begin(), 2, 0);
    std::cout << "После вставки двух элементов в начале: ";
    for (int num : container) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // c
    container.insert(container.end() - 1, 11);
    std::cout << "После вставки нового элемента перед последним элементом: ";
    for (int num : container) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // d
    container.push_back(12);
    std::cout << "После вставки нового элемента в конец: ";
    for (int num : container) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // e
    std::sort(container.begin(), container.end());
    std::cout << "После сортировки: ";
    for (int num : container) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // f
    int target = 5;
    auto it = std::find(container.begin(), container.end(), target);
    if (it != container.end()) {
        std::cout << "Найденный " << target << " на позиции " << std::distance(container.begin(), it) << std::endl;
    } else {
        std::cout << "Элемент " << target << " не найдено" << std::endl;
    }

    return 0;
}