#include <iostream>
#include <unistd.h>

#include "Interp4Rotate.hh"


Interp4Rotate::Interp4Rotate():  obj_name(""), axis_name(""), rot_speed_degs(0), rot_deg(0)
{
}

Interp4Rotate::~Interp4Rotate()
{

}

AbstractInterp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}



void Interp4Rotate::PrintCmd() const
{
   std::cout << "    "<< this->GetCmdName() <<" "<< axis_name << " " << obj_name << " " << rot_speed_degs  << " " << rot_deg << std::endl;
}


void Interp4Rotate::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    std::cout << "    Rotate obj_name axis_name rotate_speed[deg/s]  rotation[deg]" << std::endl;
}


const char* Interp4Rotate::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Rotate";
}

bool Interp4Rotate::ExecCmd( AbstractScene      &rScn, 
                        const char         *sMobObjName,
                        AbstractComChannel &rComChann )
{

    
}

bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> obj_name))
    {
        std::cerr << "Nie wczytano poprawnie nazwy obiektu ktory ma sie obrocic"<< std::endl;
        return false;
    }

    if(!(Strm_CmdsList >> axis_name))
    {
        std::cerr << "Nie wczytano poprawnie nazwy osi"<< std::endl;
        return false;
    }

    if(!(Strm_CmdsList >> rot_speed_degs))
    {
        std::cerr << "Nie wczytano poprawnie predkosci obrotowej"<< std::endl;
        return false;
    }

    if(!(Strm_CmdsList >> rot_deg))
    {
        std::cerr << "Nie wczytano poprawnie kata obrotu"<< std::endl;
        return false;
    }
    

    return true;
}


void Interp4Rotate::PrintParams() const
{
    std::cout<<"Nazwa obiektu "<<obj_name<<" Nazwa osi "<<axis_name<<" Predkości obrotowa "<<rot_speed_degs<<" kąt obrotu "<<rot_deg<<std::endl;
}


////////////////////////////////////////////wtyczka/////////////////////////////////////////////

extern "C"
{   /*! 
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
    return "Rotate";
}


AbstractInterp4Command* CreateCmd(void)
{
    return Interp4Rotate::CreateCmd();
}