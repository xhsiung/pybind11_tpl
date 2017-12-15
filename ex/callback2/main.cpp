#include <iostream>
#include <pybind11/pybind11.h>
#include <future>
#include <unistd.h>

using namespace std;
namespace py = pybind11;

class A{
public:
    virtual void pure_virt() = 0;
};

class B : public A{
public:
    void pure_virt() override {

    };
    virtual int added_fcn(){
        return -1;
    }
};

class PyB : public B {
    public:
        /* Inherit the constructors */
        using B::B;

        /* Trampoline (need one for each virtual function) */
        int added_fcn() override {
            
            /* Acquire GIL before calling Python code */
            py::gil_scoped_acquire acquire;
            
            sleep(3);
            PYBIND11_OVERLOAD(
                int,               /* Return type */
                B,                 /* Parent class */
                added_fcn,         /* Name of function in C++ (must match Python name) */
                                   /* Argument(s) */
            );
        }
};

void call_parallel(const std::shared_ptr<B> &BB) {
    cout << "call_parallel" << endl;
    std::future<void> f2 = std::async(std::launch::async, [BB](){ 
        BB->added_fcn() ; 
    }); 

    f2.get();
}


PYBIND11_MODULE(my , m){
    py::class_<A, std::shared_ptr<A>>(m, "A");
    
    py::class_<B, PyB, A, std::shared_ptr<B> >(m, "B")
        .def(py::init<>())
        .def("added_fcn", &B::added_fcn);

    m.def("call_parallel", call_parallel, py::call_guard<py::gil_scoped_release>());
}
