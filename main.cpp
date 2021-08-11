#include <iostream>

using namespace std;

int main() {
    std::cout << getenv("USERPROFILE") << std::endl;
    void* number =  0;
    printf("%d\n",sizeof(&number));
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
