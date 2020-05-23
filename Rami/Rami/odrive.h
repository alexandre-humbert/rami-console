#ifndef ODRIVE_H
#define ODRIVE_H
#include <string>

using namespace std;

class ODrive
{
    string odAgentPath_;
    string odDrivePath_;
    string redirString_;
    bool debugMode_;
public:
    ODrive(string odAgentDir=".odrive-agent", string odDriveDir="odrive", bool debugMode=false);
    string getFullName(string file) {return odDrivePath_+'/'+file;}
    void sync(string dir);
    void refresh(string dir);
    void emptytrash();
    void mkDir(string dir);
    void delFile(string file);
    bool isDir(string dir);
    void waitForChange(string file);
};

#endif // ODRIVE_H
