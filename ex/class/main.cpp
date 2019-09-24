#include <pybind11/pybind11.h>
#include <iostream>

using namespace std;
namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

class Pet{
public:
    string name;
    int age;
    Pet(){}
    Pet(string name, int age):name(name), age(age){}
    
    string bark(string msg){
        return msg;
    }

    int readnum(int a,int b){
        return add(a,b);
    }
};


PYBIND11_MODULE(my, m) {
    m.def("add",&add);

    py::class_<Pet>(m,"Pet")
        .def(py::init<>())                 //default contruct
        .def(py::init<string,int>())       //construct
        .def_readwrite("name",&Pet::name)  //name property
        .def_readwrite("age",&Pet::age)    //age  property
        .def("bark" , &Pet::bark)          //func
        .def("readnum" , &Pet::readnum);   //func
}

int main(int argc, char** argv){
    cout << add(3,4) << endl;
    return 0;
}
