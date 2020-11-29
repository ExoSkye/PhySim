//
// Created by protobit on 29/11/2020.
//

#ifndef PHYSIM_LOAD_HPP
#define PHYSIM_LOAD_HPP

#include <addon/registerDataStructs.hpp>
#include <stdexcept>
#include <vector>
#ifdef _WINDOWS
#include <windows.h>
#include <cstdio>
typedef void(__cdecl* RegFunc)(std::vector<registerData>*);

#elif __linux__

#include <dlfcn.h>
typedef void(*RegFunc)(std::vector<registerData>*);

#endif

namespace physim {
#ifdef __linux__
    void* loadLib(const char* name) {
        void* dlHandle = dlopen(name,RTLD_LAZY);
        const char* err = dlerror();
        if (err != nullptr) {
            printf("%s", dlerror());
            throw std::runtime_error("Couldn't open library");
        }
        return dlHandle;
#elif _WINDOWS
    HINSTANCE loadLib(const char* name) {
        // Get a handle to the DLL module.

        HINSTANCE hinstLib = LoadLibrary(TEXT(name));

        // If the handle is valid, try to get the function address.

        if (hinstLib != NULL)
        {
            return hinstLib;
        }
        else {
            throw std::runtime_error("Couldn't open library");
        }
#endif
    }
    std::vector<registerData> registerObjs(const char* name) {
        std::vector<registerData> regDat;

#ifdef _WINDOWS
        HINSTANCE hinstLib = loadLib(name);
        RegFunc RegisterFunc;
        BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;


        RegisterFunc = (RegFunc)GetProcAddress(hinstLib, "registerAddon");

        // If the function address is valid, call the function.

        if (NULL != RegisterFunc)
        {
            fRunTimeLinkSuccess = TRUE;
            (RegisterFunc)(&regDat);
            printf("Registered %s: %s V%s by %s", regDat[0].type == 1 ? "law addon" : "material Addon", regDat[0].name, regDat[0].version, regDat[0].authors);
        }
        // Free the DLL module.

        fFreeResult = FreeLibrary(hinstLib);
    }


#elif __linux__
        void* dlHandle = loadLib(name);
        RegFunc funcHandle = (RegFunc)dlsym(dlHandle, "registerAddon");
        (funcHandle)(&regDat);
        printf("Registered %s: %s V%s by %s", regDat[0].type == 1 ? "law addon" : "material Addon", regDat[0].name, regDat[0].version, regDat[0].authors);
#endif
        return regDat;
    }
}

#endif //PHYSIM_LOAD_HPP
