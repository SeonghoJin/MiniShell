#pragma once
#include <string>

class PathManager;

class PathManager
{
private:
    std::string currentPath;
    static PathManager* pathManager;
    void setCurrentPath(std::string nextPath);
    bool existsDir(std::string dirPath);
    bool existsDirByAbsolutePath(std::string absoluteDirPath);
    bool existsDirByRelativePath(std::string relativeDirPath);
    std::string getAbsolutePath(std::string path);
    std::string getRelativePath(std::string path);
    std::string getStartPath(std::string path);
    std::string format(std::string path);
    std::string before(std::string path);
    PathManager();

public:
    static PathManager* getPathManager();
    std::string getCurrentPath();
    bool changeDirectory(std::string path);
    ~PathManager();
};