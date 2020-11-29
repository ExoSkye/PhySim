//
// Created by ProtoBit on 26/11/2020.
//
#include <physim.hpp>
#include <addon/registerDataStructs.hpp>

#ifdef _WINDOWS
#include <windows.h> 
#include <cstdio>
typedef void(__cdecl* RegFunc)(std::vector<registerData>*);

#elif __linux__

#include <dlfcn.h>
typedef void(*RegFunc)(std::vector<registerData>*);

#endif
std::vector<registerData> registerObjs(const char* name) {
    std::vector<registerData> regDat;
#ifdef _WINDOWS
    HINSTANCE hinstLib;
    RegFunc RegisterFunc;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    // Get a handle to the DLL module.

    hinstLib = LoadLibrary(TEXT(name));

    // If the handle is valid, try to get the function address.

    if (hinstLib != NULL)
    {
        RegisterFunc = (RegFunc)GetProcAddress(hinstLib, "?registerAddon@@YAPADPAV?$vector@UregisterData@@V?$allocator@UregisterData@@@std@@@std@@@Z");

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
    else {
        printf("%s", "Can't open dll");
    }

#elif __linux__
    void* dlHandle = dlopen(name,RTLD_LAZY);
    const char* err = dlerror();
    if (err != nullptr) {
        printf("%s", dlerror());
    }
    else {
        RegFunc funcHandle = (RegFunc)dlsym(dlHandle, "_Z13registerAddonPSt6vectorI12registerDataSaIS0_EE");
        (funcHandle)(&regDat);
        printf("Registered %s: %s V%s by %s", regDat[0].type == 1 ? "law addon" : "material Addon", regDat[0].name, regDat[0].version, regDat[0].authors);
    }
#endif
    return regDat;
}
int main(int argc, const char** argv) {
#ifdef __linux__
    registerObjs("./libGravityLaw.so");
#elif _WINDOWS
    registerObjs("GravityLaw.dll");
#endif
    if(argc > 1) {
        if (strcmp(argv[1],"-test-dl") == 0) {
            printf("All ok");
            return 0;
        }
    }
    return 0;
}