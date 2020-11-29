#pragma once

#include <addon/registerDataStructs.hpp>
#include <cstdio>
#include <vector>
#ifndef NAME
#define NAME "Unnamed"
#endif
#ifndef TYPE
#error "Tried to compile a library without a type. This won't work!"
#endif
#ifndef VERSION
#define VERSION "No Version"
#endif
#ifndef AUTHORS
#define AUTHORS "None"
#endif

#ifdef _WIN32
#include <Process.h>
#include <Windows.h>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpReserved) {
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
__declspec (dllexport) void registerAddon(std::vector<registerData>* regList) {
#else
void registerAddon(std::vector<registerData>* regList) {
#endif
    regList->emplace_back(registerData{ NAME,TYPE,VERSION,AUTHORS });
}