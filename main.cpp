#include <iostream>
#include <iomanip>
#include <fstream>

#include <set>
#include <list>
#include <vector>
#include <array>

#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillList(list<string>&);
void fillVec(vector<string>&);
void fillSet(set<string>&);

void sortVec(vector<string>&);
void sortList(list<string>&);

void insertMidVec(vector<string>&, string);
void insertMidList(list<string>&, string);
void insertMidSet(set<string>&, string);

void deleteMidVec(vector<string> &);
void deleteMidSet(set<string> &);
void deleteMidList(list<string> &);

array<microseconds,3> timedFillTest(vector<string>&, list<string>&, set<string>&);
array<microseconds,2> timedSortTest(vector<string>&, list<string>&);
array<microseconds,3> timedInsertMidTest(vector<string>&, list<string>&, set<string>&);
array<microseconds,3> timedDeleteMidTest(vector<string>&, list<string>&, set<string>&);

int main() {
    int runCount = 15;

    array<microseconds,3> averageFillTime;
    array<microseconds,3> averageSortTime;
    array<microseconds,3> averageInsertTime;
    array<microseconds,3> averageDeleteTime;

    array<array<microseconds,3>, 15> allRunTimesForFill;
    array<array<microseconds,3>, 15> allRunTimesForSort;
    array<array<microseconds,3>, 15> allRunTimesForInsertMid;
    array<array<microseconds,3>, 15> allRunTimesForDeleteMid;

    for (int i = 0; i < runCount; i++){
        vector<string> vec;
        list<string> list;
        set<string> set;

        array<microseconds, 3> timesForFill = timedFillTest(vec, list, set);
        array<microseconds, 2> timesForSort = timedSortTest(vec, list);
        array<microseconds, 3> timesForInsertMid = timedInsertMidTest(vec, list, set);
        array<microseconds, 3> timesForDeleteMid = timedDeleteMidTest(vec, list, set);

        allRunTimesForFill.at(i) = timesForFill;
        allRunTimesForSort.at(i) = timesForFill;
        allRunTimesForInsertMid.at(i) = timesForFill;
        allRunTimesForDeleteMid.at(i) = timesForDeleteMid;
    }






    cout << right << setw(9) << "Operation";
    cout << right << setw(9) << "Vector";
    cout << right << setw(9) << "List";
    cout << right << setw(9) << "Set";
    cout << "\n";
    cout << right << setw(9) << "Read";
    cout << right << setw(9) << timesForFill[0].count();
    cout << right << setw(9) << timesForFill[1].count();
    cout << right << setw(9) << timesForFill[2].count();
    cout << "\n";
    cout << right << setw(9) << "Sort";
    cout << right << setw(9) << timesForSort[0].count();
    cout << right << setw(9) << timesForSort[1].count();
    cout << right << setw(9) << "-1";
    cout << "\n";
    cout << right << setw(9) << "Insert";
    cout << right << setw(9) << timesForInsertMid[0].count();
    cout << right << setw(9) << timesForInsertMid[1].count();
    cout << right << setw(9) << timesForInsertMid[2].count();
    cout << "\n";
    cout << right << setw(9) << "Delete";
    cout << right << setw(9) << timesForDeleteMid[0].count();
    cout << right << setw(9) << timesForDeleteMid[1].count();
    cout << right << setw(9) << timesForDeleteMid[2].count();
    cout << "\n";


    return 0;
}

/// @brief Runs a timed test filling each container and returns a 3 element microsecond array containing their consecutive times
/// @param vec A vector to be filled
/// @param list A list to be filled
/// @param set A set to be filled
/// @return a 3 element array containing the times for each test
array<microseconds,3> timedFillTest(vector<string> &vec, list<string> &list, set<string> &set){
    array<microseconds,3> timings;

    time_point start = high_resolution_clock::now();
    fillVec(vec);
    time_point end = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(end - start);

    timings.at(0) = duration;

    start = high_resolution_clock::now();
    fillList(list);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(1) = duration;
   
    start = high_resolution_clock::now();
    fillSet(set);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(2) = duration;

    return timings;
}

/// @brief Runs a timed test sorting each container and returns a 2 element microsecond array containing their consecutive times
/// @param vec A vector to be sorting 
/// @param list A list to be sorting 
/// @return a 2 element array containing the times for each test
array<microseconds,2> timedSortTest(vector<string> &vec, list<string> &list){
    array<microseconds,2> timings;

    time_point start = high_resolution_clock::now();
    sortVec(vec);
    time_point end = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(end - start);

    timings.at(0) = duration;

    start = high_resolution_clock::now();
    sortList(list);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(1) = duration;
   
    return timings;
}

/// @brief Runs a timed test inserting into the middle of each container and returns a 3 element microsecond array containing their consecutive times
/// @param vec A vector to be inserted 
/// @param list A list to be inserted 
/// @param set A set to be inserted 
/// @return a 3 element array containing the times for each test
array<microseconds,3> timedInsertMidTest(vector<string> &vec, list<string> &list, set<string> &set){
    array<microseconds,3> timings;

    time_point start = high_resolution_clock::now();
    insertMidVec(vec, "TESTCODE");
    time_point end = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(end - start);

    timings.at(0) = duration;

    start = high_resolution_clock::now();
    insertMidList(list, "TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(1) = duration;
   
    start = high_resolution_clock::now();
    insertMidSet(set, "TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(2) = duration;

    return timings;
}

/// @brief Runs a timed test deleting the middle element of each container and returns a 3 element microsecond array containing their consecutive times
/// @param vec A vector to be modified
/// @param list A list to be modified 
/// @param set A set to be modified
/// @return a 3 element array containing the times for each test
array<microseconds,3> timedDeleteMidTest(vector<string> &vec, list<string> &list, set<string> &set){
    array<microseconds,3> timings;

    time_point start = high_resolution_clock::now();
    deleteMidVec(vec);
    time_point end = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(end - start);

    timings.at(0) = duration;

    start = high_resolution_clock::now();
    deleteMidList(list);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(1) = duration;
   
    start = high_resolution_clock::now();
    deleteMidSet(set);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    timings.at(2) = duration;

    return timings;
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