#include <iostream>
#include <pybind11/embed.h>

using namespace std;
namespace py=pybind11;


PYBIND11_EMBEDDED_MODULE(embed,m){
    m.def("add", [](int i, int j){
        return i+j ;
    });
}

int main(){
    py::scoped_interpreter guard{};

    //os.getcwd()  
    auto os = py::module::import("os");
    auto pwd = os.attr("getcwd")().cast<string>();
    
    //sys.append( pwd )
    auto sys = py::module::import("sys");
    sys.attr("path").attr("append")( pwd );
  
    //embed
    auto embed = py::module::import("embed");
    auto result = embed.attr("add")(1,2).cast<int>();
    cout << result << endl;

    return 0;
}