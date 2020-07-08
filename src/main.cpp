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
using namespace std;

int main() {

	DaemonFileManager dmFiles;

	if(dmFiles.isOk()){
		pid_t pid=fork();
		switch(pid){
			case -1:
				cout << "[FAILS] MyNASDaemon_RaspberryPi fork failed"  << endl;
				exit(-1);
			case 0:

				for (int i = 0; i < 12; ++i)
					cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
				break;
			default:
				cout << "!!!Cucu!!!" << endl; // prints !!!Hello World!!!

				exit(0);
			}
	}
	else{
		cout << "[FAILS] MyNASDaemon_RaspberryPi fails during opening daemon config files"  << endl;
		exit(-1);
	}
}
