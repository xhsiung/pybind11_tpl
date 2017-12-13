#include <pybind11/pybind11.h>
#include <iostream>

using namespace std;
namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(my, m) {
    m.doc() = "pybind11 my plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
}

int main(int argc, char** argv){
    cout << add(3,4) << endl;
    return 0;
}