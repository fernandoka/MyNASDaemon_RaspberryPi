//============================================================================
// Name        : main.cpp
// Author      : Fernando Candelario Herrero
// Version     :
// Notes	   : Log file is /var/log/syslog
//============================================================================

#include <iostream>

// To use fork()
#include <sys/types.h>
#include <unistd.h>

#include "DaemonFileManager.h"
#include "DaemonEngine.h"


using namespace std;

int main(){

	DaemonFileManager dmFiles;

	if(dmFiles.isOk()){
		pid_t pid=fork();

		if(pid==-1){
			cout << "[FAILS] MyNASDaemon_RaspberryPi fork failed"  << endl;
			exit(-1);

		}else if(pid==0){
			DaemonEngine engine(dmFiles, (int)pid);
			engine.start();
			exit(0);

		}else{
			cout << "[OK] MyNASDaemon_RaspberryPi is running: "  << pid << endl;
			exit(0);
		}

	}
	else{
		cout << "[FAILS] MyNASDaemon_RaspberryPi fails setting up .conf file" << endl;
		exit(-1);
	}
}// main()
