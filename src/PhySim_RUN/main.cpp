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

#error Linux is not supported yet!

#endif
std::vector<registerData> registerObjs(const char* name) {
    std::vector<registerData> regDat;
#ifdef _WINDOWS
    HINSTANCE hinstLib;
    RegFunc RegisterFunc;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    // Get a handle to the DLL module.

    hinstLib = LoadLibrary(TEXT("name"));

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
    return regDat;

#elif __linux__
#endif
}
int main() {
    registerObjs();
    return 0;
}