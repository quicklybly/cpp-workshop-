#include <string>
#include <iostream>
#include "List.h"

using namespace list;

int main() {
    auto *list = new List<int>();
    list->append(1);
    list->append(2);
    list->append(3);

    std::cout << "Size: " << list->getSize() << ", values: \n";
    for (int i = 0; i < list->getSize(); ++i) {
        std::cout << "  " << (*list)[i] << "\n";
    }

    list->removeAt(1);
    std::cout << "Size after removal: " << list->getSize() << ", values: \n";
    for (int i = 0; i < list->getSize(); ++i) {
        std::cout << "  " << (*list)[i] << "\n";
    }
    delete list;

    auto *list_of_strings= new List<std::string>();
    list_of_strings->append("One");
    list_of_strings->append("Two");
    list_of_strings->append("Three");

    std::cout << "Size: " << list_of_strings->getSize() << ", values: \n";
    for (int i = 0; i < list_of_strings->getSize(); ++i) {
        std::cout << "  " << (*list_of_strings)[i] << "\n";
    }

    list_of_strings->removeAt(1);
    std::cout << "Size after removal: " << list_of_strings->getSize() << ", values: \n";
    for (int i = 0; i < list_of_strings->getSize(); ++i) {
        std::cout << "  " << (*list_of_strings)[i] << "\n";
    }
    delete list_of_strings;

    return 0;
}
