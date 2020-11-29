//
// Created by ProtoBit on 26/11/2020.
//
#include <physim.hpp>
#include <dl/load.hpp>
int main() {
#ifdef __linux__
    physim::registerObjs("./libGravityLaw.so");
#elif _WINDOWS
    physim::registerObjs("GravityLaw.dll");
#endif
    return 0;
}