#pragma once
#include "PathManager.h"
#include "InternalCommander.h"
#include "ExternalCommander.h"
#include <string>

class CommandManager{
    private:
    ExternalCommander* excmd;
    InternalCommander* incmd;   
    
    public:
        CommandManager();
        void excute(std::string cmd);
        void command(std::string cmd);
        ~CommandManager();
};