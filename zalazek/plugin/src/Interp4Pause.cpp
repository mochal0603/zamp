#include <iostream>
#include <unistd.h>

#include "Interp4Pause.hh"


Interp4Pause::Interp4Pause():  time_ms(0)
{
}

Interp4Pause::~Interp4Pause()
{

}

AbstractInterp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}



void Interp4Pause::PrintCmd() const
{
   std::cout <<"    " <<this->GetCmdName() << " " << time_ms << std::endl;
}


void Interp4Pause::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    std::cout << "    Pause time[s]" << std::endl;
}


const char* Interp4Pause::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Pause";
}

bool Interp4Pause::ExecCmd( AbstractScene      &rScn, 
                        const char         *sMobObjName,
                        AbstractComChannel &rComChann )
{

    usleep(time_ms*1000);
    
    return true;
}

bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> time_ms))
    {
        std::cerr << "Nie wczytano poprawnie czasu"<< std::endl;
        return false;
    }

    return true;
}

void Interp4Pause::PrintParams() const
{
    std::cerr<<"Czas: "<<time_ms <<" ms"<<std::endl;   
}


////////////////////////////////////////////wtyczka/////////////////////////////////////////////

extern "C"
{
    /*! 
    * \brief Get command name
    *
    *  Get command name
    * \return Name of object
    */
    const char * GetCmdName(void);
    /*! 
    * \brief Returns pointer to instance of command
    *
    *  Returns pointer to instance of command
    * \return Pointer to instance of command
    */
    AbstractInterp4Command* CreateCmd(void);
}

const char* GetCmdName(void)
{
    return "Pause";
}


AbstractInterp4Command* CreateCmd(void)
{
    return Interp4Pause::CreateCmd();
}