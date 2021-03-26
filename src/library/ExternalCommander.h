#pragma once
#include "Commander.h"
#include "PathManager.h"
#include <string>
#include <vector>

class ExternalCommander : public Commander{
    private:
        void ls();
        void cat(std::string path);
        void echo(std::string str);
        void mkdir(std::string dirName);
        void rm(std::string fileName);
        void touch(std::string fileName);
        void grep(std::string pattern, std::string fileName);
    public:
        ExternalCommander();
        virtual bool command(std::vector<std::string> cmd) final override;
        ~ExternalCommander();
};