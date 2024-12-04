#ifndef STACKONLIST_H
#define STACKONLIST_H
#include <initializer_list>
#include <stdexcept>

#include "NodeStack.h"
#include "spdlog/spdlog.h"

// StackOnList declaration

template <typename T>
class StackOnList
{
public:
    StackOnList();
    StackOnList(const std::initializer_list<T> &);
    ~StackOnList();

    void push(const T &);
    T pop();
    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] std::size_t size() const;

    const NodeStack<T> *top() const;
    NodeStack<T> *top();

private:
    std::size_t size_;
    NodeStack<T> *top_;
};

// StackOnList implementation

template <typename T>
StackOnList<T>::StackOnList()
{
    spdlog::trace("StackOnList::StackOnList()");
    top_ = nullptr;
    size_ = 0;
}

template <typename T>
StackOnList<T>::StackOnList(const std::initializer_list<T> &values)
{
    spdlog::debug("StackOnList::StackOnList(const std::initializer_list<T> &) initializing with {} elements", values.size());
    size_ = 0;
    top_ = nullptr;
    for (const auto &value : values) {
        push(value);
    }
    spdlog::debug("StackOnList::StackOnList(const std::initializer_list<T> &) Top is {}, size = {}",
                  top()->value, size_);
}

template <typename T>
StackOnList<T>::~StackOnList()
{
    spdlog::trace("StackOnList::~StackOnList() destructor, size = {}", size_);
    while (!isEmpty()) {
        pop();
    }
    spdlog::trace("StackOnList::~StackOnList() end of destructor");
}

template <typename T>
void StackOnList<T>::push(const T &value)
{
    spdlog::trace("StackOnList::push({}) begin", value);
    NodeStack<T> *node;
    if (isEmpty()) {
        node = new NodeStack<T>(value);
        top_ = node;
    } else {
        node = new NodeStack<T>(value, top_);
        top_ = node;
    }
    ++size_;
    spdlog::debug("StackOnList::push({}), top = {}", value, top_->value);
}

template <typename T>
T StackOnList<T>::pop()
{
    spdlog::trace("StackOnList::pop(), size = {}", size_);
    if (isEmpty()) {
        spdlog::error("StackOnList::pop(): Stack is empty!");
        throw std::length_error("StackOnList::pop: StackOnList is empty");
    }

    T result = top_->value;
    NodeStack<T> *tmp = top_;
    top_ = top_->next;
    delete tmp;
    --size_;
    spdlog::trace("StackOnList::pop() end, result: {}, size = {}", result, size_);
    return result;
}

template <typename T>
bool StackOnList<T>::isEmpty() const
{
    return top_ == nullptr;
}

template <typename T>
std::size_t StackOnList<T>::size() const
{
    return size_;
}

template <typename T>
const NodeStack<T> *StackOnList<T>::top() const
{
    return top_;
}

template <typename T>
NodeStack<T> *StackOnList<T>::top()
{
    return top_;
}

#endif // STACKONLIST_H
