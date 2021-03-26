#include "InternalCommander.h"
#include "Commander.h"
#include "PathManager.h"
#include <cstdarg>
#include <string>
#include <vector>
#include <iostream>

InternalCommander::InternalCommander()
    : Commander(std::vector<std::string>({"pwd", "cd", "exit"}))
{
}

bool InternalCommander::command(std::vector<std::string> cmd)
{
    if (cmd.size() == 0)
    {
        return false;
    }

    if (cmd[0] == "cd" && cmd.size() >= 2)
    {
        cd(cmd[1]);
        return true;
    }
    else if (cmd[0] == "pwd")
    {
        pwd();
        return true;
    }
    else if(cmd[0] == "exit"){
        exit(0);
    }
    return false;
}

void InternalCommander::cd(std::string path)
{
    changeDirecetory(path);
}

void InternalCommander::pwd()
{
    std::string currentPath = getCurrentPath();
    std::cout << currentPath << '\n';
}

InternalCommander::~InternalCommander()
{
}