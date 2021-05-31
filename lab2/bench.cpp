//#define DEBUG

#include <iostream>
#include <fstream>
#include "list.hpp"
#include "dynamic.hpp"
#include "sequence.hpp"
#include "Stack.hpp"
#include "unit.hpp"
#include "Vector.hpp"

int dynamictestcreate(){ // test for debug memory error and memleak
    DynamicArray<int> a; // first construction
    DynamicArray<int> b(10); // second
    int * array;
    array = new int[10];
    for(int i = 0;i < 10;i++){
        array[i] = i;
    }
    DynamicArray<int> c(array, 10); // firdth
    DynamicArray<int> d = c; // copy
    delete[] array;
    return 0;
}

int dynamictestget(){
    int * array;
    int p = 0;
    array = new int[10];
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }
    DynamicArray<int> a(array, 10);
    try{
        std::cout << a.Get(0) << std::endl;
    }catch(char const * s){
        std::cerr << s << std::endl;
        p = -1;
    }

    /*try{
        std::cout << a.Get(10) << std::endl;
    }catch(char const * s){
        std::cerr << s << std::endl;
        p = -2;
    }

    try{
        std::cout << a.Get(-2) << std::endl;
    }catch(char const * s){
        std::cerr << s << std::endl;
        p = -3;
    }*/
    delete[] array;
    return p;
}
int concatsequencetest(){
    std::ifstream in("test/concatsequence");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size1 = 0, size2 = 0, size3 = 0;
        in >> size1;
        int* data1, *data2, *data3;
        data1 = read<int>(in, size1);
        in >> size2;
        data2 = read<int>(in, size2);
        in >> size3;
        data3 = read<int>(in, size3);
        ArraySequence<int> a1(data1,size1);
        ArraySequence<int> a2(data2,size2);
        ArraySequence<int> * a3 = a1.Concat(&a2);
        std::cerr << "Concat in ArraySequence" << std::endl;
        comparedata<int>(a3, data3, size3);

        LinkedListSequence<int> l1(data1,size1);
        LinkedListSequence<int> l2(data2,size2);
        LinkedListSequence<int> * l3 = l1.Concat(&l2);
        std::cerr << "Concat in LinkedListSequence" << std::endl;
        comparedata<int>(l3, data3, size3);

        clear<int>(data1, size1);
        clear<int>(data2, size2);
        clear<int>(data3, size3);
    }
    return 0;
}

int subsequencetest(){
    std::ifstream in("test/subsequence");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size1 = 0, start = 0, end = 0;
        in >> size1;
        int* data1, *data2;
        data1 = read<int>(in, size1);
        in >> start >> end;
        data2 = read<int>(in, end - start + 1);
        ArraySequence<int> a1(data1, size1);
        ArraySequence<int> * a3 = a1.GetSubsequence(start, end);
        std::cerr << "SubSequence in ArraySequence" << std::endl;
        comparedata<int>(a3, data2, end - start + 1);

        LinkedListSequence<int> l1(data1,size1);
        LinkedListSequence<int> * l3 = l1.GetSubsequence(start, end);
        std::cerr << "SubSequence in LinkedListSequence" << std::endl;
        comparedata<int>(l3, data2, end - start + 1);

        clear<int>(data1, size1);
        clear<int>(data2, end - start + 1);
    }
    return 0;
}

int vectestsum(){
    std::ifstream in("test/vecsum");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size = 0;
        in >> size;
        int* data1, *data2, *data3;
        data1 = read<int>(in, size);
        data2 = read<int>(in, size);
        data3 = read<int>(in, size);
        Vector<int> v1(data1, size);
        Vector<int> v2(data2, size);
        Vector<int> * v3 = v1.sum(v2);
        std::cerr << "VectorSum test:" << std::endl;
        comparedatav<int>(v3, data3, size);

        clear<int>(data1, size);
        clear<int>(data2, size);
        clear<int>(data3, size);
        v1.clear();
        v2.clear();
        v3->clear();
        delete v3;
    }
    return 0;
}

int vectestscalar(){
    std::ifstream in("test/vecscalar");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN VECTESTSCALAR" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size = 0, scal = 0;
        in >> size;
        int* data1, *data2;
        data1 = read<int>(in, size);
        in >> scal;
        data2 = read<int>(in, size);
        Vector<int> v1(data1, size);
        Vector<int> * v3 = v1.scalar(scal);
        std::cerr << "VectorScalar test:" << std::endl;
        comparedatav<int>(v3, data2, size);
        
        clear<int>(data1, size);
        clear<int>(data2, size);
        v3->clear();
        delete v3;
        v1.clear();
    }
    return 0;
}

int vectestnorm(){
    std::ifstream in("test/vecnorm");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size = 0;
        double res = 0;
        in >> size;
        double* data1;
        data1 = read<double>(in, size);
        in >> res;
        Vector<double> v1(data1, size);
        double maybe = v1.norm();
        std::cerr << "VectorNorm test:" << std::endl;
        if(std::abs(maybe - res) > 0.00001){
            std::cerr << "Error in VectorNorm test" << std::endl;
        }
        
        clear<double>(data1, size);
        v1.clear();
    }
    return 0;
}




int main(int argc,  char ** argv){
    std::cout << ":*JASHABENCHMAKER:*" << std::endl;
    dynamictestcreate();
    dynamictestget();
    subsequencetest();
    concatsequencetest();
    vectestnorm();
    vectestscalar();
    vectestsum();
    return 0;
}