#include <iostream>
#include "json.hpp"
#include "utils.h"

using namespace std;
using namespace nlohmann;

int main() {
    cout << TimeFormat(TimeEpochFormat(13271850055021582)) << endl;
    cout << time(nullptr) << endl;
    auto text = R"(
    {
        "Image": {
            "Width":  800,
            "Height": 600,
            "Title":  "View from 15th Floor",
            "Thumbnail": {
                "Url":    "http://www.example.com/image/481989943",
                "Height": 125,
                "Width":  100
            },
            "Animated" : false,
            "IDs": [116, 943, 234, 38793]
        }
    }
    )";
    json j_complete = json::parse(text);
    auto jsonObj = j_complete.find("Image");
    cout << jsonObj->dump(4) << endl;

#ifdef __GNUC__
    std::cout << "__WINDOWS_" << std::endl;
#endif
#ifdef _WIN32
    std::cout << "_WIN32" << std::endl;
#endif
#ifdef _WIN64
    std::cout << "_WIN64" << std::endl;
#endif
#ifdef __APPLE__
    std::cout << "__APPLE__" << std::endl;
#endif
#ifdef __linux__
    std::cout << "__linux__" << std::endl;
#endif
#ifdef __FreeBSD__
    std::cout << "__FreeBSD__" << std::endl;
#endif
#ifdef __unix
    std::cout << "__unix" << std::endl;
#endif
    return 0;
}
