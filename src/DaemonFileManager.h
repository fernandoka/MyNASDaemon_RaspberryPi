//============================================================================
// Name        : DaemonFileManager.h
// Author      : Fernando Candelario Herrero
// Version     :
//===============================

#ifndef SRC_DAEMONFILEMANAGER_H_
#define SRC_DAEMONFILEMANAGER_H_

#include <iostream>

// To check if a directory/file exists
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// To use file streams
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
	const char * confFileName = "/etc/MyNASDaemon_RaspberryPi/MyNASDaemon_RaspberryPi.conf";
	const char * folderName = "/etc/MyNASDaemon_RaspberryPi";

	bool setupOk = true;

	// PRIVATE METHODS
	void openFileErrors(ifstream &ifs);
	bool setup();
	bool dirExists();
	bool createFolder();
	bool confFileExist();
	void createConfFile();

public:
	DaemonFileManager();
	bool isOk();
	bool writePidAndRefreshTime(int pid, int timeMs);
};

#endif /* SRC_DAEMONFILEMANAGER_H_ */
