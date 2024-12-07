#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ifstream inp_file;
    std::string ref = "mul(X,X)";
    std::string dostr = "do()";
    std::string dontstr = "don't()";
    int p1_sum = 0;
    int p2_sum = 0;
    inp_file.open("data.txt");
    if(inp_file.is_open()){
        std::string line;
        bool enable = true;
        while(std::getline(inp_file, line)){
            int ptr, ptr1, ptr2, temp, num1, num2, flag;
            ptr = ptr1 = ptr2 = temp = num1 = num2 = flag = 0;
            bool ifflag;
            //part 1
            for(int i = 0; i < line.size(); i++){
                if(ptr < 4 && line[i] == ref[ptr])
                    ptr++;
                else if(ptr == 4 && line[i] >= '0' && line[i] <= '9'){
                    flag = 1;
                    temp = temp * 10 + (line[i] - '0');
                } else if(line[i] == ',' && ptr == 4 && temp <= 999 && flag == 1){
                    num1 = temp;
                    temp = 0;
                    flag = 0;
                    ptr++;
                } else if(ptr == 5 && line[i] >= '0' && line[i] <= '9'){
                    flag = 1;
                    temp = temp * 10 + (line[i] - '0');
                } else if(ptr == 5 && line[i] == ')' && temp <= 999 && flag == 1){
                    num2 = temp;
                    p1_sum += (num1 * num2);
                    temp = ptr = flag = num1 = num2 = 0;
                } else {
                    temp = ptr = flag = num1 = num2 = 0;
                }
            }
            //part 2
            for(int i = 0; i < line.size(); i++){
                ifflag = true;
                if(line[i] == dostr[ptr1]){
                    ptr1++;
                    ifflag = false;
                    if(ptr1 == dostr.size()){
                        enable = true;
                        ptr1 = 0;
                    }
                }
                else
                    ptr1 = 0;
                if(line[i] == dontstr[ptr2]){
                    ptr2++;
                    ifflag = false;
                    if(ptr2 == dontstr.size()){
                        enable = false;
                        ptr2 = 0;
                    }
                }
                else
                    ptr2 = 0;
                if(ptr < 4 && enable && ifflag && line[i] == ref[ptr])
                    ptr++;
                else if(ptr == 4 && line[i] >= '0' && line[i] <= '9'){
                    flag = 1;
                    temp = temp * 10 + (line[i] - '0');
                } else if(line[i] == ',' && ptr == 4 && temp <= 999 && flag == 1){
                    num1 = temp;
                    temp = flag = 0;
                    ptr++;
                } else if(ptr == 5 && line[i] >= '0' && line[i] <= '9'){
                    flag = 1;
                    temp = temp * 10 + (line[i] - '0');
                } else if(ptr == 5 && line[i] == ')' && temp <= 999 && flag == 1){
                    num2 = temp;
                    p2_sum += (num1 * num2);
                    temp = ptr = flag = num1 = num2 = 0;
                } else {
                    temp = flag = ptr = num1 = num2 = 0;
                }
            }
        }
    }
    std::cout << p1_sum << std::endl;
    std::cout << p2_sum << std::endl;
    return 0;
}