#ifndef NODESTACK_H
#define NODESTACK_H
template <typename T>
struct NodeStack
{
  T value;
  NodeStack<T>* next;

  explicit NodeStack(T value, NodeStack<T>* next = nullptr) : value(value), next(next) {}

private:
  NodeStack() = default;
};

#endif //NODESTACK_H
