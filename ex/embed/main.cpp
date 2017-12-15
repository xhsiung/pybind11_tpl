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
    
    //sys.append( mypath )
    auto sys = py::module::import("sys");
    string mypath = pwd + "/tmp";
    sys.attr("path").attr("append")( mypath );
    py::print(sys.attr("path")  );

    //add embed 
    auto embed = py::module::import("embed");
    auto result = embed.attr("add")(1,2).cast<int>();
    cout << result << endl;

    //global local 
    auto locals = py::dict();
    locals["age3"] = 22;
    py::exec( R"(
        c=10
        a=20
        dict={'age':c,'age2':a}
    )", py::globals(), locals );
    //python type
    py::print( locals["a"] );
    //c++ type
    cout << locals["age3"].cast<int>()  << endl;

    return 0;
}