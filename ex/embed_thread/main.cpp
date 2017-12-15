#include <iostream>
#include <pybind11/embed.h>
#include <thread>

using namespace std;
namespace py = pybind11;
using namespace py::literals;

int main()
{
    py::scoped_interpreter guard{};

    constexpr auto num_threads = 1000;
    auto locals = py::dict("count"_a = 0);

    py::gil_scoped_release gil_release{};

    auto threads = std::vector<std::thread>();
    for (auto i = 0; i < num_threads; ++i){
        threads.emplace_back([&]() {
            py::gil_scoped_acquire gil{};
            locals["count"] = locals["count"].cast<int>() + 1;
            
            sleep(1);
            cout << locals["count"].cast<int>() << endl;
        });
    }

    for (auto &thread : threads){
        thread.join();
    }
    cout << "end" << endl;

    return 0;
}