cmake_minimum_required(VERSION 3.13)
project(poker)

set(CMAKE_CXX_STANDARD 11)

add_executable(poker main.cpp src/Card.cpp src/Card.h src/Bet.cpp src/Bet.h src/Game.cpp src/Game.h src/PlayerType.h src/Hand.cpp src/Hand.h src/BetHistory.cpp src/BetHistory.h src/Player.cpp src/Player.h)