#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <vector>

template <typename TElem>
class DynamicArray {
private:
    std::vector<TElem> elements;

public:
    // Constructor
    DynamicArray(int capacity) : elements() {
        elements.reserve(capacity);
    }

    // Method to add an element to the array
    void addElem(TElem element) {
        elements.push_back(element);
    }

    // Method to delete an element based on its index
    void deleteElem(int delete_index) {
        elements.erase(elements.begin() + delete_index);
    }

    // Method to update an element of the array
    void updateElem(int update_index, TElem element) {
        elements[update_index] = element;
    }

    // Getter method for the elements of the array
    const std::vector<TElem>& elemGetter() const {
        return elements;
    }

    // Getter method for the number of elements of the array
    int nrEntitiesGetter() const {
        return elements.size();
    }
};

#endif // DYNAMIC_ARRAY_H