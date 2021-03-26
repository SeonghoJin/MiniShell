#pragma once
#include "Commander.h"
#include "PathManager.h"
#include <string>
#include <vector>

class InternalCommander : public Commander{
    public:
        InternalCommander();
        virtual bool command(std::vector<std::string> cmd) final override;
        void cd(std::string path);
        void pwd();
        ~InternalCommander();
};