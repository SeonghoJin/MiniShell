#include "library/PathManager.h"
#include "library/CommandManager.h"
#include "library/User.h"
#include <string>
#include <iostream>

using namespace std;

int main(char *argc, char *argv[]){
  
    PathManager* pm = PathManager::getPathManager();
    User user;
    CommandManager cmdmanager;
    string buffer;

    while(1){
        cout << user.getUid() << "@" << user.getHost() << ":" << pm->getCurrentPath() <<'\n';
        cout << "$ ";
        getline(cin, buffer);
        cmdmanager.command(buffer);
    }

    delete pm;
    return 0;
}