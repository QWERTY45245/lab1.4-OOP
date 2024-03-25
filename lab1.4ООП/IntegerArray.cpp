#include "IntegerArray.h"
#include <iostream>
#include <stdexcept>

IntegerArray::IntegerArray(int lower, int upper) : lowerIndex(lower), upperIndex(upper) {
    if (lowerIndex > upperIndex) {
        throw std::invalid_argument("Lower index cannot be greater than upper index");
    }
    data.resize(upperIndex - lowerIndex + 1);
}

int IntegerArray::getValue(int index) const {
    if (index < lowerIndex || index > upperIndex) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index - lowerIndex];
}

void IntegerArray::setValue(int index, int value) {
    if (index < lowerIndex || index > upperIndex) {
        throw std::out_of_range("Index out of bounds");
    }
    data[index - lowerIndex] = value;
}

void IntegerArray::Init(int value) {
    for (int i = 0; i < data.size(); ++i) {
        data[i] = value;
    }
}

void IntegerArray::Read() {
    std::cout << "Enter " << data.size() << " integers:" << std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cin >> data[i];
    }
}

void IntegerArray::Display() const {
    std::cout << "Array elements:" << std::endl;
    for (int value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

std::string IntegerArray::toString() const {
    std::string result = "";
    for (int value : data) {
        result += std::to_string(value) + " ";
    }
    return result;
}

void IntegerArray::setLowerIndex(int lower) {
    lowerIndex = lower;
}

void IntegerArray::setUpperIndex(int upper) {
    upperIndex = upper;
}

int IntegerArray::getLowerIndex() const {
    return lowerIndex;
}

int IntegerArray::getUpperIndex() const {
    return upperIndex;
}

IntegerArray IntegerArray::add(const IntegerArray& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Arrays must have the same size");
    }
    IntegerArray result(lowerIndex, upperIndex);
    for (int i = 0; i < data.size(); ++i) {
        result.setValue(lowerIndex + i, data[i] + other.getValue(lowerIndex + i));
    }
    return result;
}

IntegerArray IntegerArray::subtract(const IntegerArray& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Arrays must have the same size");
    }
    IntegerArray result(lowerIndex, upperIndex);
    for (int i = 0; i < data.size(); ++i) {
        result.setValue(lowerIndex + i, data[i] - other.getValue(lowerIndex + i));
    }
    return result;
}

IntegerArray IntegerArray::multiply(int scalar) const {
    IntegerArray result(lowerIndex, upperIndex);
    for (int i = 0; i < data.size(); ++i) {
        result.setValue(lowerIndex + i, data[i] * scalar);
    }
    return result;
}

IntegerArray IntegerArray::divide(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    IntegerArray result(lowerIndex, upperIndex);
    for (int i = 0; i < data.size(); ++i) {
        result.setValue(lowerIndex + i, data[i] / scalar);
    }
    return result;
}
