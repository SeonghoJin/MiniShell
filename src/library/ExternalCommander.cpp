#include "ExternalCommander.h"
#include "Commander.h"
#include "PathManager.h"
#include <cstdarg>
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//debug
#include <iostream>

ExternalCommander::ExternalCommander()
    : Commander(std::vector<std::string>({"cat", "cp", "echo", "ls", "mkdir", "rm", "touch", "grep"}))
{
}

bool ExternalCommander::command(std::vector<std::string> cmd){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        fprintf(stderr, "fork Error");
    }
    else if(pid == 0){
        int cmdSize = cmd.size();
        if(cmdSize == 0)exit(0);

        if(cmd[0] == "ls")ls();
        else if(cmd[0] == "cat" && cmdSize >= 1)cat(cmd[1]);
        else if(cmd[0] == "echo" && cmdSize >= 1)echo(cmd[1]);
        else if(cmd[0] == "mkdir" && cmdSize >= 1)mkdir(cmd[1]);
        else if(cmd[0] == "rm" && cmdSize >= 1)rm(cmd[1]);
        else if(cmd[0] == "touch" && cmdSize >= 1)touch(cmd[1]);
        else if(cmd[0] == "grep" && cmdSize >= 2)grep(cmd[1], cmd[2]);
        exit(0);
    }

    if(pid > 0){
        wait(NULL);
        return true;
    }

    return false;
}

void ExternalCommander::ls(){
    execlp("ls", "ls", getCurrentPath().c_str(), NULL);
}

void ExternalCommander::cat(std::string path){
    std::string newPath = getCurrentPath()+"/"+path;
    execlp("cat", "cat", newPath.c_str(), NULL);
}

void ExternalCommander::echo(std::string str){
    execlp("echo", "echo", str.c_str(), NULL);
}

void ExternalCommander::mkdir(std::string dirName){
    std::string path = getCurrentPath()+"/"+dirName;
    execlp("mkdir", "mkdir", path.c_str(), NULL);
}

void ExternalCommander::rm(std::string fileName){
    std::string path = getCurrentPath()+"/"+fileName;
    execlp("rm", "rm", path.c_str(), NULL);
}

void ExternalCommander::touch(std::string fileName){
    std::string path = getCurrentPath()+"/"+fileName;
    execlp("touch", "touch", path.c_str(), NULL);
}


void ExternalCommander::grep(std::string pattern, std::string fileName){
    std::string path = getCurrentPath()+"/"+fileName;
    execlp("grep", "grep", pattern.c_str(), path.c_str(), NULL);
}

ExternalCommander::~ExternalCommander()
{
}