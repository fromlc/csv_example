//------------------------------------------------------------------------------
// csv_example.cpp
// 
// 1) two fields, one comma between them
// 2) more than two fields separated by commas
//------------------------------------------------------------------------------
#include <iostream>
#include <string>       // for stoi()
#include <vector>

using namespace std;

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
void csv_example_1();
void csv_example_2();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // two fields, one comma between them
    csv_example_1();

    // more than two fields separated by commas
    csv_example_2();

    return 0;
}

//------------------------------------------------------------------------------
// Example 1: two fields, one comma between them
//------------------------------------------------------------------------------
void csv_example_1() {

    // test data
    string csv_str = "one,2";

    // get index of first comma in file data line
    size_t comma_index = csv_str.find(',');

    // text before index of the comma
    string str_before_comma = csv_str.substr(0, comma_index);

    // text after index of the comma
    string str_after_comma = csv_str.substr(comma_index + 1);

    // stoi() is string to int library function
    int i_after_comma = stoi(str_after_comma);

    cout << "\nExample 1: two fields, one comma between them\n";
    cout << "csv data line: " << csv_str << '\n';
    cout << "text before comma: " << str_before_comma << '\n';
    cout << "text after comma: " << str_after_comma << '\n';
}

//------------------------------------------------------------------------------
// Example 2: more than two fields separated by commas
// 
// -this code is for your future use, you don't need it for Assignment 5 
//------------------------------------------------------------------------------
void csv_example_2() {

    // test data
    string csv_str = "one,2,three,happy Thanksgiving";

    // accumulate data values in vector
    vector<string> vs;

    // use a temporary string variable to avoid data loss in csv_str
    string working_string = csv_str;

    // get index of first comma in csv data line
    size_t comma_index = working_string.find(',');

    // terminate loop when no commas are left in the working string
    while (comma_index != string::npos) {

        // data is all text before the comma
        vs.push_back(working_string.substr(0, comma_index));

        // remove old data field from our working string
        working_string = working_string.substr(comma_index + 1);

        // look for another comma
        comma_index = working_string.find(',');
    }

    // last data field is all data after the last comma
    vs.push_back(working_string);

    cout << "\nExample 2: more than two fields separated by commas\n";
    cout << "csv data line: " << csv_str << '\n';

    // display vector elements
    for (int i = 0; i < vs.size(); i++) {

        cout << "data field " << i + 1 << ": " << vs.at(i) << '\n';
    }
}