#include<iostream>
#include<deque>
using namespace std;

template<class T>
class queue {
public:
    queue() {}
    void push(const T&);
    void pop();
    T& front();
    T& back();
    bool empty();
    size_t size();
private:
    deque<T> data;
};

template<class T>
void queue<T>::push(const T& value) {
    data.push_back(value);
}

template<class T>
void queue<T>::pop() {
    data.pop_front();
}

template<class T>
bool queue<T>::empty() {
    return data.empty();
}

template<class T>
size_t queue<T>::size() {
    return data.size();
}

template<class T>
T& queue<T>::front() {
    return data.front();
}

template<class T>
T& queue<T>::back() {
    return data.back();
}