cmake_minimum_required(VERSION 3.21)
project(Project1Lexer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1Lexer
        Automaton.h
        ColonAutomaton.h
        ColonDashAutomaton.h
        IDAutomaton.h
        Lexer.h
        main.cpp
        Token.h
        UndefinedCharAutomaton.h)
