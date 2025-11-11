#include <iostream>
#include "Interp4Set.hh"


using namespace std;

Interp4Set::Interp4Set():  obj_name(""), pos_x_m(0), pos_y_m(0), pos_z_m(0), angle_x_deg(0), angle_y_deg(0), angle_z_deg(0)
{
}

Interp4Set::~Interp4Set()
{

}

AbstractInterp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}



void Interp4Set::PrintCmd() const
{
   cout << "    " <<this->GetCmdName() << " " << obj_name << " " << pos_x_m  << " " << pos_y_m << " " << " " << pos_z_m << " " << angle_x_deg << " " << angle_y_deg << " " << angle_z_deg << endl;
}


void Interp4Set::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "    Set obj_name pos_x[m]  pos_y[m] pos_z[m] angle_x[deg] angle_y[deg] angle_z[deg]" << endl;
}


const char* Interp4Set::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Set";
}

bool Interp4Set::ExecCmd( AbstractScene      &rScn, 
                        const char         *sMobObjName,
                        AbstractComChannel &rComChann )
{
    
    return true;
    /* Wykonuje polecenie oraz wizualizuje jego realizacje */
}

bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
    
    

    return true;
}

void Interp4Set::PrintParams() const
{
    std::cout<<"Nazwa obiektu "<<obj_name<<" pozycja x: "<<pos_x_m<<" y: "<<pos_y_m<<" z: "<<pos_z_m<<" kat obrotu x: "<<angle_x_deg<<" y: "<<angle_y_deg<<" z: "<<angle_z_deg<<std::endl;
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
    return "Set";
}


AbstractInterp4Command* CreateCmd(void)
{
    return Interp4Set::CreateCmd();
}