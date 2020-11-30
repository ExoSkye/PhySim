//
// Created by protobit on 29/11/2020.
//
#include <dl/load.hpp>
int main() {
#ifdef __linux__
    void* dlhandle = physim::loadLib(CMAKE_BINARY_DIR"/../examples/law/libGravityLaw.so");
#elif _WINDOWS
    HINSTANCE dlhandle = physim::loadLib(CMAKE_BINARY_DIR"/../examples/law/GravityLaw.dll");
#endif
    if (dlhandle != NULL) {
        printf("All ok");
    }
}