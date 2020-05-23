#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sys/stat.h"
#include <ctime>
#include <thread>
#include <chrono>
#include "odrive.h"

#if defined(_WIN32) || defined(WIN32)
#define stat _stat
#pragma warning(suppress : 4996)
#endif


using namespace std;

/**
 * Constructs the ODrive object
 *
 * @param odAgentDir the path where the odriveagent is installed
 * @param odDriveDir the path of the mounting point of the drive
 * @param debugMode  output odrive information to the console
 */
ODrive::ODrive(string odAgentDir, string odDriveDir, bool debugMode)
{
    ostringstream osAgent,osDrive;
    string logFile="odrive_class.log";

#ifdef __unix__
    osAgent<<getenv("HOME")<<'/'<<odAgentDir<<"/bin/odrive";
    osDrive<<getenv("HOME")<<'/'<<odDriveDir<<"/Google Drive";
    redirString_=" >> "+logFile+" 2>&1";
#elif defined(_WIN32) || defined(WIN32)
    osAgent<<getenv("HOMEDRIVE")<<getenv("HOMEPATH")<<'\\'<<odAgentDir<<"\\bin\\odrive";
    osDrive<<getenv("HOMEDRIVE")<<getenv("HOMEPATH")<<'\\'<<odDriveDir<<"\\Google Drive";
    redirString_=" >> "+logFile+" 2>&1";
#endif

    odAgentPath_=osAgent.str();
    odDrivePath_=osDrive.str();

    debugMode_=debugMode;
    if (debugMode) {
        redirString_="";
        cout<<"Init the odrive"<<endl;
        cout<<odAgentPath_<<endl;
        cout<<odDrivePath_<<endl;
    }
    else {
        ofstream logStream(logFile);
        logStream<<"Init the odrive"<<endl;
        logStream<<odAgentPath_<<endl;
        logStream<<odDrivePath_<<endl;
    }
}


void ODrive::sync(string dir)
{
    // Wait for 1s
    this_thread::sleep_for(chrono::seconds(1));
    // Synchronize a file
    string fich=odDrivePath_+'/'+dir+".cloudf";
    if (ifstream(fich).good())
    {
        ostringstream ocmd;
        ocmd<<odAgentPath_<<" sync \""<<fich<<'"'<<redirString_;
        system(ocmd.str().c_str());
    }
    else
    {
        fich=odDrivePath_+'/'+dir+".cloud";
        if (ifstream(fich).good())
        {
            ostringstream ocmd;
            ocmd<<odAgentPath_<<" sync \""<<fich<<'"'<<redirString_;
            system(ocmd.str().c_str());
        }
    }
}


void ODrive::refresh(string dir)
{
    // Wait for 1s
    this_thread::sleep_for(chrono::seconds(1));
    // Send refresh command
    ostringstream ocmd;
    ocmd<<odAgentPath_<<" refresh \""<<odDrivePath_<<'/'<<dir<<'"'<<redirString_;
    string cmd=ocmd.str();
    system(ocmd.str().c_str());
}


void ODrive::emptytrash()
{
    string cmd=odAgentPath_+" emptytrash"+redirString_;
    system(cmd.c_str());
}


void ODrive::mkDir(string dir)
{
    ostringstream ocmd;
    ocmd<<"mkdir \""<<odDrivePath_<<'/'<<dir<<'"'<<redirString_;
    system(ocmd.str().c_str());
}



void ODrive::delFile(string file)
{
    // Deletes the file
    ostringstream ocmd;
#ifdef __unix__
    ocmd<<"rm \""<<odDrivePath_<<'/'<<file<<"\""<<redirString_;
#elif defined(_WIN32) || defined(WIN32)
    ocmd<<"del \""<<odDrivePath_<<'/'<<file<<"\""<<redirString_;
#endif
    system(ocmd.str().c_str());

    // Extract parent dir
    string odDir;
    size_t pos=file.find_last_of("/\\");
    if (pos!=string::npos) odDir=file.substr(0,pos);
    else odDir="";
    // Refresh parent dir
    refresh(odDir);
    // Wait for 2s
    this_thread::sleep_for(chrono::seconds(2));
    // Empty the trash to delete the file in the drive
    emptytrash();
}


bool ODrive::isDir(string dir)
{
    // Test place holder
    string fich=odDrivePath_+'/'+dir+".cloudf";
    bool b=ifstream(fich).good();

    if (!b) {
        // Test directory
        string fich=odDrivePath_+'/'+dir;
        struct stat t_stat;
        b=stat(fich.c_str(), &t_stat)==0;
    }

    return b;
}




void ODrive::waitForChange(string file)
{
    string odfile=odDrivePath_+'/'+file;
    // Extract parent dir
    string odDir;
    size_t pos=file.find_last_of("/\\");
    if (pos!=string::npos) odDir=file.substr(0,pos);
    else odDir="";

    // Get initial time
    struct stat t_stat;
    stat(odfile.c_str(), &t_stat);
    time_t t1=t_stat.st_mtime;

    // Scan time change
    bool changed=false;
    while(!changed)
    {
        // Refresh
        refresh(odDir);
        // Check if time is changed
        stat(odfile.c_str(), &t_stat);
        time_t t2=t_stat.st_mtime;
        if (difftime(t1,t2)!=0) changed=true;
    }

}

