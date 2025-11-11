#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "AbstractInterp4Command.hh"
#include "AbstractMobileObj.hh"
#include "AbstractScene.hh"

#include <memory>

/*!
 * \file
 * \brief Definition of class Interp4Pause
 *
 * File contains definition of class Interp4Pause
 */



    /*!
    * \brief Class used to represent pause command
    *
    *  Class used to represent pause command
    */
    class Interp4Pause: public AbstractInterp4Command
    {
        private:
            /*! 
            * \brief Time of pause ms
            *
            *  Time of pause ms
            */
            int time_ms;
        public:
            /*! 
            * \brief Constructor of move command class
            *
            *  Constructor of move command class
            */
            Interp4Pause();
            /*! 
            * \brief Destructor of move command class
            *
            *  Destructor of move command class
            */
            ~Interp4Pause();
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
            * \brief Get the name of object
            * 
            * Get the name of object
            * 
            * \return Name of object
            */
            std::string GetObjName(){return "";}
    };

#endif
