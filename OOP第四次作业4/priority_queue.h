#pragma once
#include "abstract_compare.h"
#include<vector>
template<class T> class PriorityQueue {
public:
    vector<T> p_queue;
    AbstractCompare<T>* cmp;
    PriorityQueue(AbstractCompare<T> *_cmp);
    ~PriorityQueue() = default;
    bool empty();
    int size();
    void push(T element);
    void pop();
    T top();
};
template<class T>
PriorityQueue<T>::PriorityQueue(AbstractCompare<T> *_cmp){
    cmp=_cmp;
}
template<class T>//检查队列是否为空
bool PriorityQueue<T>:: empty(){
    return p_queue.empty();
}
template<class T>//返回队列中元素的个数
int PriorityQueue<T>::size(){
    return p_queue.size();
}
template<class T>//将元素插入到队列中
void PriorityQueue<T>::push(T element){
    p_queue.push_back(element);
}
template<class T>//删除队列中的最小值
void PriorityQueue<T>::pop(){
    int num=0;
    for(int i=1;i<p_queue.size();i++){
        if(cmp->compare(p_queue[i],p_queue[num])){
            num=i;
        }
    }
    p_queue.erase(p_queue.begin()+num);
}
template<class T>//输出队列中的最小值
T PriorityQueue<T>::top(){
    int num=0;
    for(int i=1;i<p_queue.size();i++){
        if(cmp->compare(p_queue[i],p_queue[num])){
            num=i;
        }
    }
    // cout<<p_queue[num]<<endl;
    return p_queue[num];
}
