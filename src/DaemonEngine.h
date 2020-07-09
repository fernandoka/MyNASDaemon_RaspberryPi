//============================================================================
// Name        : DaemonEngine.h
// Author      : Fernando Candelario Herrero
// Version     :
//===============================

#ifndef SRC_DAEMONENGINE_H_
#define SRC_DAEMONENGINE_H_

// To use sleep function
#include <unistd.h>

// To use system logger
#include <syslog.h>

#include "DaemonFileManager.h"


class DaemonEngine {

private:
	bool killDaemon = false;
	bool updateDevices = false;
	float sleepTime_ms = 0.5;

	DaemonFileManager myDmFiles;

public:
	DaemonEngine(DaemonFileManager dmFiles, int pid);
	void start();

};

#endif /* SRC_DAEMONENGINE_H_ */
