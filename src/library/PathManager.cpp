#include "PathManager.h"
#include "strutill.h"
#include <sys/types.h>
#include <sys/param.h>
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <sstream>

PathManager* PathManager::pathManager = nullptr;

PathManager::PathManager()
{
    std::string rawPath = getStartPath("myshell");
    currentPath = before(rawPath);
}

bool PathManager::changeDirectory(std::string path) 
{   
    if(path == ".."){
        setCurrentPath(format(before(getCurrentPath())));
        return true;
    }
    else if(format(path) == "/"){
        setCurrentPath(format(path));
    }
    else if(existsDirByRelativePath(path)){
        setCurrentPath(format(getRelativePath(path)));
        return true;
    }
    else if(existsDirByAbsolutePath(path)){
        setCurrentPath(format(getAbsolutePath(path)));
        return true;
    }
    else{
        return false;
    }
}

std::string PathManager::getCurrentPath()
{
    return currentPath == "" ? "/" : currentPath;
}

void PathManager::setCurrentPath(std::string nextPath)
{
    currentPath = nextPath;
}

bool PathManager::existsDir(std::string dirPath) 
{
    DIR *dir = opendir(dirPath.c_str());
    if (dir)
    {
        closedir(dir);
        return true;
    }
    else
    {
        return false;
    }
}

bool PathManager::existsDirByAbsolutePath(std::string absoluteDirPath) 
{
    return existsDir("/" + absoluteDirPath);
}

bool PathManager::existsDirByRelativePath(std::string relativeDirPath) 
{
    return existsDir(getCurrentPath() + "/" + relativeDirPath);
}

std::string PathManager::format(std::string path) {
    std::stringstream ss;
    size_t pathLen = path.size();

    for(int i = 0; i < pathLen; i++){
        while(i+1 < pathLen && path[i] == '/' && path[i+1] == path[i])i++;
        ss << path[i];
    }

    return ss.str();
}

std::string PathManager::getAbsolutePath(std::string path) {
    return path == "/" ? "/" : "/"+path;
}

std::string PathManager::getRelativePath(std::string path) {
    return getCurrentPath()+"/"+path;
}

std::string PathManager::getStartPath(std::string path) 
{
    char resolved_path[MAXPATHLEN];
    realpath(path.c_str(), resolved_path);
    std::string ret(resolved_path);
    return ret;
}

std::string PathManager::before(std::string path) {
    std::string cp = path; 
    std::vector<std::string> pathSeg = split(cp,'/');
    if(pathSeg.size() == 0)return "";
    std::string beforePath = join(
        std::vector<std::string>(pathSeg.begin(), --pathSeg.end()),'/');
    return beforePath;
}

PathManager* PathManager::getPathManager(){
    if(pathManager == NULL) PathManager::pathManager = new PathManager();
    return pathManager;
}

PathManager::~PathManager(){
    if(pathManager != NULL)delete PathManager::pathManager;
}