#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

inline bool is_correct(vector<int>& v) { 
    int smaller = 0;
    int bigger = 0;
    for(int i = 0; i < v.size() - 1; i++) {

        // if((v[i] - v[i-1] < 0 && v[i] - v[i+1] < 0) || (v[i] - v[i-1] > 0 && v[i] - v[i+1] > 0)) {
        //     return false;
        // }
        if(v[i] > v[i+1]) { 
            if(smaller != 0) { 
                return false;
            }
            bigger++;
        } else { 
            if(bigger != 0) { 
                return false;
            }
            smaller++;
        }
        if(1 > abs(v[i] - v[i+1]) || abs(v[i] - v[i+1]) > 3) { 
            return false;
        }
    }
    
    return true;
}

int main() { 
    vector<int> a;
    int counter;
    ifstream file("text.txt");
    int x = 0;
    while(file >> x) {
        a.push_back(x);

        char y;
        file.get(y);
        if(y == '\n' || file.eof()) {
            if(is_correct(a)) {
                
                counter++;
            }
            a.erase(a.begin(), a.end());
        }
    }

    cout << counter;

    return 0;
}


