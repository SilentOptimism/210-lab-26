#include <iostream>
#include <fstream>

#include <set>
#include <list>
#include <vector>

#include <algorithm>

#include <chrono>

using namespace std;
using namespace std::chrono;

void fillList(list<string> &data);
void fillVec(vector<string> &data);
void fillSet(set<string> &data);

void sortVec(vector<string> &data);
void sortList(list<string> &data);

void insertMidVec(vector<string> &data, string element);
void insertMidList(list<string> &data, string element);
void insertMidSet(set<string> &data, string element);

void deleteMidVec(vector<string> &data);
void deleteMidSet(set<string> &data);
void deleteMidList(list<string> &data);

int main() {
    vector<string> vec;
    list<string> li;
    set<string> set;

   

    return 0;
}


/// @brief Reads data into a List that had working pushback and returns the time it took for the calculation
/// @param data an empty vector
/// @return a duration object containing time for caclulation
void fillList(list<string> &data){
    ifstream fin;
    fin.open("codes.txt");
    if(!fin){
        cout << "File opening error" << endl;
        return;
    }

    while(fin){
        string code;
        getline(fin,code);
        data.push_back(code);
    }
}
/// @brief Reads data into a Vec that had working pushback and returns the time it took for the calculation
/// @param data an empty vector
/// @return a duration object containing time for caclulation
void fillVec(vector<string> &data){
    ifstream fin;
    fin.open("codes.txt");
    if(!fin){
        cout << "File opening error" << endl;
        return;
    }

    while(fin){
        string code;
        getline(fin,code);
        data.push_back(code);
    }
}
/// @brief Reads data into a set and returns the time it took for the calculation
/// @param data an empty list
/// @return a duration object containing time for caclulation
void fillSet(set<string> &data){
    ifstream fin;
    fin.open("codes.txt");
    if(!fin){
        cout << "File opening error" << endl;
        return;
    }

    while(fin){
        string code;
        getline(fin,code);
        data.insert(code);
    }
}

/// @brief Sorts a Vector
/// @param data The vector to be sorted
void sortVec(vector<string> &data){
    sort(data.begin(),data.end());
}
/// @brief Sorts a List
/// @param data The List to be sorted
void sortList(list<string> &data){
    data.sort();
}

/// @brief Inserts an element to the middle of a vector
/// @param data The vector to be inserted
/// @param element The element that will be inserted
void insertMidVec(vector<string> &data, string element){
    auto middle = data.begin();
    advance(middle, data.size()/2);
    data.insert(middle, element);
}
/// @brief Inserts an element to the middle of a List
/// @param data The list to be inserted
/// @param element The element that will be inserted
void insertMidList(list<string> &data, string element){
    auto middle = data.begin();
    advance(middle, data.size()/2);
    data.insert(middle, element);
}
/// @brief Inserts an element to the middle of a List
/// @param data The set to be inserted
/// @param element The element that will be inserted
void insertMidSet(set<string> &data, string element){
    data.insert(element);
}

/// @brief Removes the middle element in a vector
/// @param data The vector where the middle element will be removed
void deleteMidVec(vector<string> &data){
    auto midIter = data.begin();
    int midIndex = data.size()/2;

    // For vectors this will simply move the ptr 
    // For lists/sets it will have to actually iterate through each element
    advance(midIter, midIndex);

    data.erase(midIter);
}
/// @brief Removes the middle element in a set
/// @param data The set where the middle element will be removed
void deleteMidSet(set<string> &data){
    auto midIter = data.begin();
    int midIndex = data.size()/2;

    // For vectors this will simply move the ptr 
    // For lists/sets it will have to actually iterate through each element
    advance(midIter, midIndex);

    data.erase(midIter);
}
/// @brief Removes the middle element in a list
/// @param data The list where the middle element will be removed
void deleteMidList(list<string> &data){
    auto midIter = data.begin();
    int midIndex = data.size()/2;

    // For vectors this will simply move the ptr 
    // For lists/sets it will have to actually iterate through each element
    advance(midIter, midIndex);

    data.erase(midIter);
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<microseconds>(end - start)
duration.count() references elapsed microseconds
*/