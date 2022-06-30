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
        UndefinedCharAutomaton.h
        CommaAutomaton.h
        PeriodAutomaton.h
        Q_MarkAutomaton.h
        Left_ParenAutomaton.h
        Right_ParenAutomaton.h
        MultiplyAutomaton.h
        AddAutomaton.h
        SchemesAutomaton.h
        FactsAutomaton.h
        RulesAutomaton.h
        QueriesAutomaton.h
        StringAutomaton.h
        CommentAutomaton.h
        BlockCommentAutomaton.h Parser.h)
