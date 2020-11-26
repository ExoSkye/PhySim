//
// Created by ProtoBit on 26/11/2020.
//

#ifndef PHYSIM_PHYSIM_HPP
#define PHYSIM_PHYSIM_HPP

#ifdef _WIN32
#include <Process.h>
BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
#endif

#include "graph_class.h"


#endif //PHYSIM_PHYSIM_HPP
