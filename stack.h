#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

/**
 * Templated Stack class using std::vector
 */
template <typename T>
class Stack 
{
public:
    Stack() = default;
    ~Stack() = default;

    bool empty() const { return data_.empty(); }
    size_t size() const { return data_.size(); }

    void push(const T& item) { data_.push_back(item); }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        data_.pop_back();
    }

    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data_.back();
    }

private:
    std::vector<T> data_; 
};

#endif 
