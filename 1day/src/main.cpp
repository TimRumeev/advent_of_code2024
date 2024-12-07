#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <fstream>



int main() { 
    std::vector<int> vec1;
    std::vector<int> vec2;
    for(int i = 0; i < 1000; i++) { 
        
        int a,b;
        std::cin >> a;
        std::cin >> b;
        vec1.push_back(a);
        vec2.push_back(b);
    }
    
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    
    long long res;
    for(int i = 0; i < 1000; i++) {
        res += abs(vec1[i] - vec2[i]);
    }

    std::cout << res;
    return 0;
}

/*
std::ifstream file("data.txt");
    int a,b;
    while(file >> a >> b) { 
        vec1.push_back(a);
        vec2.push_back(b);
    }
    1189356
    */