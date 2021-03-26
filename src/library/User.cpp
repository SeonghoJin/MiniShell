#include "User.h"
#include <string.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


User::User(){
    initUid();
    initHost();
}

void User::initHost(){
    int len = 256;
    char host_name[len];

    if(gethostname(host_name, len) == -1){
        printf("gethostname Error!\n");
        exit(1);
    }

    host = std::string(host_name);
}

std::string User::getHost(){
    return host;
}

void User::initUid(){
    struct passwd *pwd;
    pwd = getpwuid(getuid());
    if(pwd == nullptr){
        printf("error\n");
    }
    uid = std::string(pwd->pw_name);
}

std::string User::getUid(){
    return uid;
}

