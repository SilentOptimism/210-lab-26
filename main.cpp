#include <iostream>
#include <fstream>

#include <set>
#include <list>
#include <vector>

#include <algorithm>

#include <chrono>
#include <typeinfo>

using namespace std;
using namespace std::chrono;

/// @brief Reads data into a container that had working pushback and returns the time it took for the calculation
/// @param data an empty vector
/// @return a duration object containing time for caclulation
microseconds fillUsingPushBack(auto &data){
    microseconds fail;
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
    microseconds duration = duration_cast<microseconds>(end - start);

    return duration;
}
/// @brief Reads data into a set and returns the time it took for the calculation
/// @param data an empty list
/// @return a duration object containing time for caclulation
microseconds fillUsingInsert(auto &data){

    microseconds fail;
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
    microseconds duration = duration_cast<microseconds>(end - start);

    return duration;
}

microseconds sortVec(vector<string> &data){
    auto start = high_resolution_clock::now();
    sort(data.begin(),data.end());
    auto end = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(end-start);

    return duration;
}
microseconds sortList(list<string> &data){
    auto start = high_resolution_clock::now();
    data.sort();
    auto end = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(end-start);
    return duration;
}

microseconds insertMid(auto &data, string element){
    auto middle = data.begin();
    advance(middle, data.size()/2);

    time_point start = steady_clock::now();
    data.insert(middle, element);
    time_point end = steady_clock::now();

    microseconds duration = duration_cast<microseconds>(end - start);
    return duration;
}

microseconds insertSet(set<string> &data, string element){
    time_point start = steady_clock::now();
    data.insert(element);
    time_point end = steady_clock::now();

    microseconds duration = duration_cast<microseconds> (end - start);
    return duration;
}

int main() {
    vector<string> vec;
    list<string> li;
    set<string> set;

    cout << fillUsingPushBack(vec).count() << endl;
    cout << fillUsingPushBack(li).count() << endl;
    cout << fillUsingInsert(set).count() << endl;

    cout << endl;

    cout << sortVec(vec).count() << endl;
    cout << sortList(li).count() << endl;
    cout << -1 << endl;

    cout << endl;

    cout << insertMid(vec, "TESTCODE").count() << endl;
    cout << insertMid(li, "TESTCODE").count() << endl;
    cout << insertSet(set, "TESTCODE").count() << endl;
    cout << vec.at(vec.size()/2-1) << endl;
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<microseconds>(end - start)
duration.count() references elapsed microseconds
*/