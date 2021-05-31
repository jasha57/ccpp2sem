#ifndef Stack_HPP
#define Stack_HPP

#include "sequence.hpp"

template<class T>
class Stack{

public:
    Stack(){
        sp = 0;
        data;
    }
    void push(T& obj){
        if(sp < data.GetLenght()){
            data.Set(sp, obj);
        } else {
            data.Append(obj);
            
        }
        sp++;
    }
    T Get(int i){
        return data.Get(i);
    }
    T pop(){
        if(sp > 0){
            T res = data.Get(sp);
            sp--;
            return res;
        } else {
            throw "StackEmpty";
        }
    }
    bool isEmpty(){
        return (sp)?true:false;
    }
    int GetSize(){
        return sp;
    }
    void map(T (*f)(T)){
        for(int i = 0; i < sp; i++){
            data.Set(i, f(data.Get(i)));
        }
    }
    T reduce(T (*f)(T,T),const T& start){
        if(sp > 0){
            T tmp = f(data.GetFirst(), start);
            for(int i = 1; i < sp; i++){
                tmp = f(data.Get(i), tmp);
            }
            return tmp;
        }else {
            throw "StackEmpty";
        }
    }

    ArraySequence<bool> where(bool (*f)(T)){
        ArraySequence<bool> res(sp);
        for(int i = 0; i < sp; i++){
            res.Set(i,f(data.Get(i)));
        }
        return res;
    }

    Stack<T> * Getsubstack(int start , int end){
        if(start < 0 or start >= sp or end >= sp or end < 0 or start > end) {
            throw "IndexOutOfRange";
            return nullptr;
        }
        Stack<T> * res;
        res->data = data.GetSubsequence(start, end);
        res->sp = end - start + 1;
        return res;
    }

    void Concat(Stack<T> * add){
        for(int i = 0; i < add->sp; i++){
            push(add->data.Get(i));
        }
    }
    int findSubSequence(T * subseq, int len){
        if(len > sp){
            return false;
        }
        int ind;
        bool res = false;
        for(int i = 0; i < sp - len + 1 && (!res); i++){
            res = true;
            for(int j = 0; j < len; j++){
                if(subseq[j] != data.Get(i+j)){
                    res = false;
                }
            }
            if(res){
                ind = i;
            }
        }
        return ind;
    }
private:
    int sp;
    ArraySequence<T> data;
};

#endif