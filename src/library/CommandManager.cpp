#include "CommandManager.h"
#include "InternalCommander.h"
#include "ExternalCommander.h"
#include "PathManager.h"
#include "strutill.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

CommandManager::CommandManager(){
    excmd = new ExternalCommander();
    incmd = new InternalCommander();
}

void CommandManager::command(std::string cmd){
    std::vector<std::string> pipSeg = split(cmd, '|');
    std::for_each(pipSeg.begin(), pipSeg.end(), [=](std::string pipSegment) -> void{
        excute(pipSegment);
    });
}

void CommandManager::excute(std::string cmd){
    std::vector<std::string> commandSeg = split(trim(cmd), ' ');
    if(commandSeg.size() == 0)return;
    if(excmd->existsCommand(commandSeg[0])){
        excmd->command(commandSeg);
    }
    if(incmd->existsCommand(commandSeg[0])){
        incmd->command(commandSeg);
    }
}

CommandManager::~CommandManager(){
    if(excmd){
        delete excmd;
    }
    if(incmd){
        delete incmd;
    }
}