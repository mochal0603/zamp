#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH
#define N 100
#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "AbstractInterp4Command.hh"

#include <memory>


/*!
 * \file
 * \brief Definition of class Interp4Rotate
 *
 * File contains definition of class Interp4Rotate
 */

    /*!
    * \brief Class used to represent rotate command
    *
    *  Class used to represent rotate command
    */
    class Interp4Rotate: public AbstractInterp4Command
    {
        private:
            /*! 
            * \brief Name of object to be rotated
            *
            *  Name of object to be rotated
            */
            std::string obj_name; 
            /*! 
            * \brief Name of a axis in which object will be rotated
            *
            *  Name of a axis in which object will be rotated
            */
            std::string axis_name; 
            /*! 
            * \brief Angular velocity of an object in degrees/second (deg/s)
            *
            *  Angular velocity of an object in degrees/second (deg/s)
            */
            double rot_speed_degs;
            /*! 
            * \brief Rotation of an object in degrees (deg)
            *
            *  Rotation of an object in degrees (deg)
            */
            double rot_deg;
        public:
            /*! 
            * \brief Constructor of move command class
            *
            *  Constructor of move command class
            */
            Interp4Rotate();
            /*! 
            * \brief Destructor of move command class
            *
            *  Destructor of move command class
            */
            ~Interp4Rotate();
            /*!
            * \brief Display name and parameters of command
            */
            void PrintCmd() const;
            /*!
            * \brief Print syntax of command
            */
            void PrintSyntax() const;
            /*!
            * \brief Return the name of command
            * \return Name of command
            */
            const char* GetCmdName() const;
            /*!
            * \brief Execute command
            * \retval true - executed without problems
            * \retval false - there was an error 
            */
            bool ExecCmd( AbstractScene      &rScn, 
                        const char         *sMobObjName,
                        AbstractComChannel &rComChann );
            /*!
            * \brief Read parameters of command
            * \param[in, out] Strm_CmdsList - stream containing parameters to be read
            * \retval true - read was successfull
            * \retval false - read was not successfull
            */
            bool ReadParams(std::istream& Strm_CmdsList);
            /*!
            * \brief Wyświetla wartości wczytanych parametrów
            */
            void PrintParams() const;
            /*!
            * \brief Static funtion creating instance of command,
            * 
            * Static funtion creating instance of command
            * \return Handler to command instance
            */
            static AbstractInterp4Command* CreateCmd();
            /*!
            * \brief Get the name of object beeing moved
            * 
            * Get the name of object beeing moved
            * 
            * \return Name of object
            */
            std::string GetObjName(){return obj_name;}
    };

#endif
