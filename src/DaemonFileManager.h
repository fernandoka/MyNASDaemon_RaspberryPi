//============================================================================
// Name        : DaemonFileManager.h
// Author      : Fernando Candelario Herrero
// Version     :
//===============================

#ifndef SRC_DAEMONFILEMANAGER_H_
#define SRC_DAEMONFILEMANAGER_H_

// To check if a directory exists
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>

// Use C++ string class
#include <string>

// To use system logger
#include <syslog.h>

// To use strerror
#include <string.h>

#include <exception>

using namespace std;

class DaemonFileManager {

private:
	const char * fileConfName = "/etc/MyNASDaemon_RaspberryPi/MyNASDaemon_RaspberryPi.conf";
	const char * folderName = "/etc/MyNASDaemon_RaspberryPi";

	bool setupOk = true;

	// PRIVATE METHODS
	void openFileErrors(ifstream &ifs);
	bool setup();
	bool dirExists();
	bool createFolder();


public:
	DaemonFileManager();
	bool isOk();
};

#endif /* SRC_DAEMONFILEMANAGER_H_ */
