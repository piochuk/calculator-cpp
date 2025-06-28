#include <iostream>
#include <cmath>
#include "calculator.h"

bool ReadNumber(Number& result){
    //cin >> result;
    if(!(std::cin >> result)){
        cerr << "Error: Numeric operand expected" << endl;
        return false;
    }else {
        return true;
    }
} 

bool RunCalculatorCycle(){

    Number right;
    Number memory_cell = 0;
    Number cur_sum = 0;
    string oper;
    bool been_saved = false;
    
   //ReadNumber(cur_sum);
   if(!ReadNumber(cur_sum)){
    return false;
   };

    while (!(oper == "q"s)){
        cin >> oper;
        
        if(oper == "+"s){
           // ReadNumber(right);
            if(!ReadNumber(right)){
            return false;
            };
            cur_sum += right;

        }else if(oper == "-"s){        
            //ReadNumber(right);
            if(!ReadNumber(right)){
            return false;
            };
            cur_sum -= right;

        }else if(oper == "*"s){        
            //ReadNumber(right);
            if(!ReadNumber(right)){
            return false;
            };
            cur_sum *= right;

        }else if(oper == "/"s){
            //ReadNumber(right);
            if(!ReadNumber(right)){
            return false;
            };
            cur_sum /= right;

        }else if(oper == "**"s){
            //ReadNumber(right);
            if(!ReadNumber(right)){
            return false;
            };
            cur_sum = pow(cur_sum, right);

        }else if(oper == ":"s){
            //ReadNumber(right);
            if(!ReadNumber(right)){
            return false;
            };
            cur_sum = right;

        }else if(oper == "="s){
            cout << cur_sum << endl;

        }else if(oper == "c"s){
            cur_sum = 0;

        }else if(oper == "q"s){
            continue;

        }else if(oper == "s"s){
            memory_cell = cur_sum;
            been_saved = true;

        }else if(oper == "l"s){
            if(!been_saved){
                cerr << "Error: Memory is empty" << endl;
                return false;
            }
            cur_sum = memory_cell;
        }else{
            cerr << "Error: Unknown token " << oper << endl;
            return false;
        }
    }
    return true;
}