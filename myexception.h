#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class MyException : public exception
{
private:
    string _error;
public:
    MyException(const string error):_error(error){}
    const char* what() const noexcept { return _error.c_str(); }
};
