cmake_minimum_required(VERSION 3.10)

project (
  CollapsibleSidebar
  LANGUAGES CXX
  VERSION 1.0.0
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(
  collapsible_sidebar_example
  main.cpp
  mainwindow.cpp
  collapsible_sidebar.cpp
)

target_link_libraries(
  collapsible_sidebar_example
  PUBLIC
    Qt::Gui
    Qt::Widgets
    Qt::Core
)
