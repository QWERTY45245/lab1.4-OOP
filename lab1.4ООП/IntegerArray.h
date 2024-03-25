#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H

#include <vector>
#include <string>

class IntegerArray {
private:
    std::vector<int> data;
    int lowerIndex;
    int upperIndex;

public:
    IntegerArray(int lower, int upper);
    int getValue(int index) const;
    void setValue(int index, int value);
    void Init(int value);
    void Read();
    void Display() const;
    std::string toString() const;
    void setLowerIndex(int lower);
    void setUpperIndex(int upper);
    int getLowerIndex() const;
    int getUpperIndex() const;
    IntegerArray add(const IntegerArray& other) const;
    IntegerArray subtract(const IntegerArray& other) const;
    IntegerArray multiply(int scalar) const;
    IntegerArray divide(int scalar) const;
};

#endif
