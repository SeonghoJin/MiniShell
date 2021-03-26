#pragma once
#include "PathManager.h"
#include <string>
#include <stdarg.h>
#include <vector>

class Commander{
    private:
        PathManager* pm;
    protected:
        const std::vector<std::string> commands;
        std::string getCurrentPath();
        void changeDirecetory(std::string path);
    public:
        Commander(std::vector<std::string> cmds);
        bool existsCommand(std::string command);
        virtual bool command(std::vector<std::string> cmd) = 0;
        virtual ~Commander();
};