#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definition of class Interp4Set
 *
 * File contains definition of class Interp4Set
 */

	/*!
    * \brief Class used to represent set command
    *
    *  Class used to represent set command
    */
	class Interp4Set: public AbstractInterp4Command
	{
		private:
			/*! 
            * \brief Name of object to be positioned
            *
            *  Name of object to be positioned
            */
			std::string obj_name;
			/*! 
            * \brief Final position x-axis in meters (m)
            *
            *  Final position x-axis in meters (m)
            */
			int pos_x_m;
			/*! 
            * \brief Final position y-axis in meters (m)
            *
            *  Final position y-axis meters (m)
            */
			int pos_y_m;
            /*! 
            * \brief Final position z-axis in meters (m)
            *
            *  Final position y-axis meters (m)
            */
			int pos_z_m;
			/*! 
            * \brief Final rotation around x-axis in degrees
            *
            *  Final rotation in meters
            */
			int angle_x_deg;
            /*! 
            * \brief Final rotation around y-axis in degrees
            *
            *  Final rotation in meters
            */
			int angle_y_deg;
            /*! 
            * \brief Final rotation around z-axis in degrees
            *
            *  Final rotation in meters
            */
			int angle_z_deg;
		public:
			/*! 
            * \brief Constructor of move command class
            *
            *  Constructor of move command class
            */
			Interp4Set();
			/*! 
            * \brief Destructor of move command class
            *
            *  Destructor of move command class
            */
			~Interp4Set();
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
