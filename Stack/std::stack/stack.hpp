#include<iostream>
#include<vector>
using namespace std;

template<class T>
class stack {
public:
    stack() {}
    ~stack() {}
    stack(const stack&);
    bool empty() const;
    size_t size() const;
    T & top();
    const T& top() const;
    void push(const T&);
    void pop();

private:
    vector<T>data;
};

template<class T>
stack<T>::stack(const stack & origin) {
    this->data = origin.data;
}

template<class T>
bool stack<T>::empty() const {
    return data.size() ? false : true;
}

template<class T>
size_t stack<T>::size() const {
    return data.size();
}

template<class T>
T & stack<T>::top() {
    return data[data.size()-1];
}

template<class T>
const T& stack<T>::top() const {
    return data[data.size()-1];
}

template<class T>
void stack<T>::push(const T& value) {
    data.push_back(value);
}

template<class T>
void stack<T>::pop() {
    data.pop_back();
}