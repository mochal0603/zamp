#include <dlfcn.h>
#include <iostream>
#include <map>
#include <string>

#include "AbstractInterp4Command.hh"
#include "LibraryInterface.hh"

LibInterface::LibInterface(): pLibHnd(NULL)
{}

bool LibInterface::init(const std::string& filename){
pLibHnd = dlopen(filename.c_str(), RTLD_LAZY);
if (!pLibHnd) {
    std::cerr << "!!! Brak biblioteki: " << filename << std::endl;
    return false;
    }
// Pomocnicza lambda do pobierania symboli
auto loadSymbol = [&](auto& funcPtr, const char* symbolName, const char* errorMsg) -> bool {
void* pFun = dlsym(pLibHnd, symbolName);
if (!pFun) {
    std::cerr << "!!! " << errorMsg << " (" << dlerror() << ")" << std::endl;
    dlclose(pLibHnd);
    pLibHnd = nullptr;
    return false;
    }
    funcPtr = reinterpret_cast<std::remove_reference_t<decltype(funcPtr)>>(pFun);
    return true;
    };
    
if (!loadSymbol(Create_CMD, "CreateCmd", "Nie znaleziono funkcji CreateCmd")) return false;
if (!loadSymbol(Get_Name, "GetCmdName", "Nie znaleziono funkcji GetCmdName")) return false;
    
return true;
}
    