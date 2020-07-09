//============================================================================
// Name        : DaemonEngine.cpp
// Author      : Fernando Candelario Herrero
// Version     :
//===============================

#include "DaemonEngine.h"

DaemonEngine::DaemonEngine(DaemonFileManager dmFiles, int pid) {
	// TODO Auto-generated constructor stub
	this->myDmFiles = dmFiles;
	this->killDaemon = !this->myDmFiles .writePidAndRefreshTime(pid, (int)(this->sleepTime_ms*1000));
}

void DaemonEngine::start(){
	while(!killDaemon){
		sleep(this->sleepTime_ms);
		syslog(LOG_INFO,"MyNASDaemon_RaspberryPi is alive...");
	}

	syslog(LOG_INFO,"MyNASDaemon_RaspberryPi is shutting down");
}
