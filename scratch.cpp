#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> small;
    small[2] += 1;
    small[3] += 2;

    map<int, int> large;
    large[3] += 3;
    large[5] += 1;
    for(auto itr = small.begin(); itr != small.end(); itr++){
        if(large[itr->first] < itr->second){
            large[itr->first] = itr->second;
        }
    }

    for(auto itr = large.begin(); itr != large.end(); itr++){
        cout << itr->first << " count " << itr->second << endl;
    }
    return 0;
}