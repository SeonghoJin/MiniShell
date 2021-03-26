#pragma once
#include <string>

class User{
    private:
        std::string uid;
        std::string host;
        void initUid();
        void initHost();
    public:
        std::string getHost()
        std::string getUid();
        User();
};