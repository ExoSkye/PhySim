//
// Created by ProtoBit on 26/11/2020.
//

#ifndef PHYSIM_PHYSIM_HPP
#define PHYSIM_PHYSIM_HPP
#ifdef CompileToShared
#ifdef _WIN32
#include <Process.h>
#include <Windows.h>
BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpReserved) {
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
#endif
#endif
#include "graph_class.h"
#include <cstdio>


#endif //PHYSIM_PHYSIM_HPP
