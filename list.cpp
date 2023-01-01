#include "Header.h"

template <typename T> class Node {

  public:
    Node() : _next(nullptr), _prev(nullptr), _data(T()) {}
    Node(const T &value) : _next(nullptr), _prev(nullptr), _data(value) {}

  public:
    Node *_prev;
    Node *_next;
    T _data;
};

template <typename T> class Iterator {
  public:
    Iterator() : _node(nullptr) {}
    Iterator(Node<T> *node) : _node(node) {}

  public:
    Iterator &operator++() {
        _node = _node->_next;
        return *this;
    }

    Iterator &operator++(int) {
        auto temp = *this;
        _node = _node->_next;
        return temp;
    }

    Iterator &operator--() {
        _node = _node->_prev;
        return *this;
    }

    Iterator &operator--(int) {
        auto temp = *this;
        _node = _node->_prev;
        return temp;
    }

    T &operator*() { return _node->_data; }
    bool operator==(const Iterator &other) const {
        return _node == other._node;
    }
    bool operator!=(const Iterator &other) const {
        return _node != other._node;
    }

  public:
    Node<T> *_node;
};

template <typename T> class List {
  public:
    List() : _size(0) {
        _head = new Node<T>();
        _tail = new Node<T>();

        _head->_next = _tail;
        _tail->_prev = _head;
    }
    ~List() {
        while (_size > 0)
            pop_back();

        delete _head;
        delete _tail;
    }

  public:
    int size() const { return _size; }
    void push_back(const T &value) { addNode(_tail, value); }
    void pop_back() { removeNode(_tail->_prev); }

  public:
    using iterator = Iterator<T>;
    iterator begin() { return iterator(_head->_next); }
    iterator end() { return iterator(_tail); }
    iterator insert(iterator it, const T &value) {
        auto iter = addNode(it._node, value);
        return iterator(iter);
    }

    iterator erase(iterator it) {
        auto iter = removeNode(it._node);
        return iterator(iter);
    }

  private:
    // head <-> [1] <-> preNode <-> before <-> tail
    Node<T> *addNode(Node<T> *before, const T &value) {
        Node<T> *newNode = new Node<T>(value);
        auto prevNode = before->_prev;

        prevNode->_next = newNode;

        newNode->_prev = prevNode;
        newNode->_next = before;

        before->_prev = newNode;
        ++_size;

        return newNode;
    }

    // head <-> [1] <-> preNode <-> node <-> nextNode <-> tail
    // head <-> [1] <-> preNode <-> nextNode <-> tail
    Node<T> *removeNode(Node<T> *node) {

        auto prev = node->_prev;
        auto next = node->_next;

        prev->_next = next;
        next->_prev = prev;

        delete node;
        --_size;

        return next;
    }

  private:
    Node<T> *_head;
    Node<T> *_tail;
    int _size;
};

//  List<int> test;
// List<int>::iterator eraseit;
// for (int i = 0; i < 10; ++i) {
//
//    if (i == 5) {
//        eraseit = test.insert(test.end(), 5);
//    } else {
//        test.push_back(i);
//    }
//}
//
// test.pop_back();
// test.erase(eraseit);
//
// for (auto it = test.begin(); it != test.end(); ++it) {
//    cout << *it << endl;
//}