#ifndef STACKONARRAY_H
#define STACKONARRAY_H
#include "NodeStack.h"
#include "spdlog/spdlog.h"

template <typename T>
class StackOnArray
{
public:
    StackOnArray() = default;
    ~StackOnArray() = default;
    StackOnArray(const std::initializer_list<T> &);


    void push(const T &);
    T pop();
    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] std::size_t size() const;

    const NodeStack<T> *top() const;
    NodeStack<T> *top();

    bool operator==(const StackOnArray<T> &other) const
    {
        return stack_ == other.stack_;
    }
private:
    std::vector<T> stack_;
};

template <typename T>
StackOnArray<T>::StackOnArray(const std::initializer_list<T> &values)
{
    spdlog::debug("StackOnArray(const std::initializer_list<T> &)");
    stack_ = std::vector<T>(values);
}

template <typename T>
void StackOnArray<T>::push(const T &value)
{
    stack_.push_back(value);
}

template <typename T>
T StackOnArray<T>::pop()
{
    if (stack_.empty()) {
        spdlog::error("StackOnArray<T>::pop(): empty stack");
        throw std::length_error("StackOnArray<T>::pop(): empty stack");
    }
    T value = stack_.back();
    stack_.pop_back();
    return value;
}

template <typename T>
bool StackOnArray<T>::isEmpty() const
{
    return stack_.empty();
}

template <typename T>
std::size_t StackOnArray<T>::size() const
{
    return stack_.size();
}

template <typename T>
const NodeStack<T> *StackOnArray<T>::top() const
{
    return &stack_.rbegin();
}

template <typename T>
NodeStack<T> *StackOnArray<T>::top()
{
    return &stack_.rbegin();
}

#endif // STACKONARRAY_H
