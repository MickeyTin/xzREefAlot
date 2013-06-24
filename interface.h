#ifndef INTERFACE_H
#define INTERFACE_H

#include "Scheduler.h"

class Interface
{
	public:
		Interface ();
		void getCommand ();
	    void executeCommand ();
		int done ();

	private:
		Scheduler scheduler; 
		char command;
		int finished; 
};

#endif
