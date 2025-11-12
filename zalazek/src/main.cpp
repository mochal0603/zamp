#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <array>
#include <memory>
#include <stdexcept>

#include "AbstractInterp4Command.hh"
#include "xmlinterp.hh"

using namespace std;

std::string preprocessFile(const std::string& filePath) {
  std::string command = "cpp -E -P " + filePath;
  std::array<char, 4096> buffer{};
  std::string result;

  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("Nie udało się otworzyć potoku do preprocesora");
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}

void LoadAndShowPlugin(const std::string &libName)
{
  void *pLibHnd = dlopen(libName.c_str(), RTLD_LAZY);
  if (!pLibHnd) {
    cerr << "!!! Brak biblioteki: " << libName << endl;
    return;
  }

  void *pFun = dlsym(pLibHnd, "CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd w " << libName << endl;
    dlclose(pLibHnd);
    return;
  }

  auto pCreateCmd = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);
  AbstractInterp4Command *pCmd = pCreateCmd();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;

  delete pCmd;
  dlclose(pLibHnd);
}

int main()
{
  LoadAndShowPlugin("libInterp4Move.so");
  LoadAndShowPlugin("libInterp4Pause.so");
  LoadAndShowPlugin("libInterp4Rotate.so");
  LoadAndShowPlugin("libInterp4Set.so");
  return 0;
}
