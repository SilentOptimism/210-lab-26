#include <iostream>
#include <fstream>

#include <set>
#include <list>
#include <vector>

#include <chrono>
#include <typeinfo>

using namespace std;
using namespace std::chrono;

/// @brief Reads data into a vector and returns the time it took for the calculation
/// @param data an empty vector
/// @return a duration object containing time for caclulation
milliseconds readIntoVector(vector<string> &data){
    milliseconds fail;
    auto start = high_resolution_clock::now();

    ifstream fin;
    fin.open("codes.txt");
    if(!fin){
        cout << "File opening error" << endl;
        return fail;
    }

    while(fin){
        string code;
        getline(fin,code);
        data.push_back(code);
    }

    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);

    return duration;
}

/// @brief Reads data into a List and returns the time it took for the calculation
/// @param data: an empty list
/// @return a duration object containing time for caclulation
milliseconds readIntoList(list<string> &data){
    milliseconds fail;
    auto start = high_resolution_clock::now();

    ifstream fin;
    fin.open("codes.txt");
    if(!fin){
        cout << "File opening error" << endl;
        return fail;
    }

    while(fin){
        string code;
        getline(fin,code);
        data.push_back(code);
    }

    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);

    return duration;
}

/// @brief Reads data into a set and returns the time it took for the calculation
/// @param data an empty list
/// @return a duration object containing time for caclulation
milliseconds readIntoSet(set<string> &data){
    milliseconds fail;
    auto start = high_resolution_clock::now();

    ifstream fin;
    fin.open("codes.txt");
    if(!fin){
        cout << "File opening error" << endl;
        return fail;
    }

    while(fin){
        string code;
        getline(fin,code);
        data.insert(code);
    }

    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);

    return duration;
}

int main() {
    vector<string> vec;
    list<string> li;
    set<string> set;

    cout << readIntoVector(vec).count() << endl;
    cout << readIntoList(li).count() << endl;
    cout << readIntoSet(set).count() << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/