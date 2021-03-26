cmake_minimum_required(VERSION 2.8)

add_library(mylib STATIC
  strutill.cpp
  PathManager.cpp
  Commander.cpp
  InternalCommander.cpp
  ExternalCommander.cpp
  CommandManager.cpp
  User.cpp
)