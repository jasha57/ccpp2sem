#include <iostream>
#include "sequence.hpp"
#include <string>
#include "Stack.hpp"
#include <complex>
#include "unit.hpp"
#include "Vector.hpp"



const std::string MSG[] = {"1.EXIT", "2.Enter vector", "3.List vector", "4.Sum vector", "5. scalar ", "6. dot", "7. norm"};
const int SMSG = 13;

int getmenu() {
    std::string error = "";
    int ch = 0;
    do {
        std::cout << error;
        error = "You're wrong. Try again!";
        for (int i = 0; i < SMSG; i++) {
            std::cout << MSG[i] << std::endl;
        }
        std::cout << "Make your choice: ";
        std::cin >> ch;
        while (getchar() != '\n') {}
    } while(ch < 1 || ch > SMSG);

    return ch;
}

int main() {
    Stack<Vector<double> > vecdd;
    bool turn = true;
        while(turn) {
            int ch = getmenu();
            switch (ch) {
                case 1:
                    turn = 0;
                    break;
                case 2:{
                        double * temp;
                        int n = 0;
                        std::cout << "Enter dimention:\n";
                        std::cin >> n;
                        std::cout << "Enter Vector:\n";
                        temp = read<double>(std::cin, n);
                        try{
                            Vector<double> newmatr(temp, n);
                            vecdd.push(newmatr);
                        }catch(const char * a){
                            std::cout << a << std::endl;
                        }
                        scanf("%*c");
                        clear<double>(temp, n);
                        break;
                    }
                case 3: {
                        for(int i = 0; i < vecdd.GetSize(); i++){
                            Vector<double>  ptr = vecdd.Get(i);
                            std::cout << "Vector N:" << i << std::endl;
                            std::cout << "{";
                            for(int j = 0; j < ptr.GetDim(); j++){
                                std::cout << ptr.Get(j) << ", ";
                            }
                            std::cout << "}" << std::endl;
                            ptr.clear();
                        }
                        scanf("%*c");
                        break;
                    }
                case 4:{
                    std::cout << "Man: SUM(NUM1,NUM2) =: NEWNUM = NUM1 + NUM2\n";
                    std::cout << "Enter NUM1:";
                    int num1 = 0, num2 = 0;
                    std::cin >> num1;
                    std::cout << "Enter NUM2:";
                    std::cin >> num2;
                    
                    
                    Vector<double> *temp = vecdd.Get(num1 - 1).sum(vecdd.Get(num2 - 1));
                    vecdd.push(*temp);
                    std::cout << "New Number for your vector :" << vecdd.GetSize() << std::endl;

                    scanf("%*c");
                    break;
                }
                case 5:{
                    printf("Man: Scalar(NUM,SCLAR) =:  NEWNUM = NUM * SCLAR\n");
                    int NUM = 0;
                    printf("Enter NUM:");
                    std::cin >> NUM;
                    double scal;
                    std::cout << "Enter Scalar:";
                    std::cin >> scal;
                    Vector<double>* temp = vecdd.Get(NUM - 1).scalar(scal);
                    vecdd.push(*temp);
                    std::cout << "New number for your vector:" << vecdd.GetSize() << std::endl;
                    scanf("%*c");
                    break;
                }
                case 6:{
                        std::cout << "Man: DOT(NUM1,NUM2) =: Result = (NUM1 , NUM2)\n";
                    std::cout << "Enter NUM1:";
                    int num1 = 0, num2 = 0;
                    std::cin >> num1;
                    std::cout << "Enter NUM2:";
                    std::cin >> num2;
                    
                    
                    std::complex<double> res = vecdd.Get(num1 - 1).dot(vecdd.Get(num2 - 1));
                    std::cout << "Result :" << res << std::endl;

                    scanf("%*c");
                    break;
                    }
                case 7:{
                    std::cout << "Man: NORM(NUM) =: res = NUM(ARGV)\n";
                        std::cout << "Enter NUM:";
                        int num = 0;
                        std::cin >> num;
                        double res = 0;
                        try{
                            res = vecdd.Get(num - 1).norm();
                        } catch(const char* s){
                            std::cerr << s << std::endl;
                            break;
                        }
                        
                        std::cout << "Result:" << res << std::endl;
                        scanf("%*c");
                        break;
                }

            }
        }
    
    return 0;
}