#include "Commander.h"
#include "PathManager.h"

Commander::Commander(std::vector<std::string> cmds)
:commands(cmds){
    pm = PathManager::getPathManager();
}

Commander::~Commander(){
    if(pm){
        delete pm;
    }
}

bool Commander::existsCommand(std::string command){
    for(size_t i = 0; i < commands.size(); i++){
        if(commands[i] == command)return true;
    }
    return false;
}

std::string Commander::getCurrentPath(){
    return pm->getCurrentPath();
}

void Commander::changeDirecetory(std::string path){
    pm->changeDirectory(path);
}
