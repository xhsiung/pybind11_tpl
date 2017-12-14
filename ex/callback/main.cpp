#include <pybind11/pybind11.h>
#include <iostream>
#include <unistd.h>
using namespace std;

namespace py = pybind11;

class Callback{
public:
    py::handle self;
    int state;
    Callback(py::handle self,int state):self(self),state(state){
        cout << "Construct Callback " << endl;
    }

    void callback(int value){
        py::gil_scoped_acquire gil;
        cout << "In Callbck::callback" << endl;
        
        sleep(10);
        py::object method = self.attr("callback");
        method.call( state , value);
    }
};

void emit(Callback *cb, int value) {
    py::gil_scoped_release gil;
    cout << "emit_callback" <<endl;
    cb->callback(value);
}

PYBIND11_MODULE(my, m){
    m.def("emit", &emit);

    py::class_<Callback>(m, "Callback")
        .def(py::init<py::object, int>());
}
