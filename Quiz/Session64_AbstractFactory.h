//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION64_ABSTRACTFACTORY_H
#define QUIZ_SESSION64_ABSTRACTFACTORY_H

#include <iostream>
using std::cout, std::cin, std::endl;

class Composer{
public:
    virtual void compose() = 0;
};

class Parser{
public:
    virtual void parse() = 0;
};

class NasdaqComposer: public Composer{
public:
    void compose(){
        std::cout << "Composing Nasdaq message" << std::endl;
    }
};

class NasdaqParser: public Parser{
public:
    void parse(){
        cout << "Parsing Nasdaq message" << endl;
    }
};

class EBSComposer: public Composer{
public:
    void compose(){
        cout << "Composing EBS message" << endl;
    }
};

class EBSParser: public Parser{
public:
    void parse(){
        cout << "Parsing EBS message" << endl;
    }
};

class AbstractFactory{
public:
    virtual Composer* createComposer() = 0;
    virtual Parser* createParser() = 0;
};

class FactoryNasdaq: public AbstractFactory{
public:
    Composer* createComposer(){
        return new NasdaqComposer();
    }
    Parser* createParser(){
        return new NasdaqParser();
    }
};

class FactoryEBS: public AbstractFactory{
public:
    Composer* createComposer(){
        return new EBSComposer();
    }
    Parser* createParser(){
        return new EBSParser();
    }
};
//
//class Composer{
//
//};
//
//class Parser{
//
//};
//
//class NasdaqComposer: public Composer{
//
//};
//
//class NasdaqParser: public Parser{
//
//};
//
//class EBSComposer: public Composer{
//
//};
//
//class EBSParser: public Parser{
//
//};
//
//class AbstractFactory{
//public:
//    Composer* createComposer();
//    Parser* createParser();
//};
//
//class FactoryNasdaq: public AbstractFactory{
//public:
//    Composer* createComposer(){
//        new NasdaqComposer();
//    }
//    Parser* createParser(){
//        new NasdaqParser();
//    }
//};
//
//class FactoryEBS: public AbstractFactory{
//public:
//    Composer* createComposer(){
//        new EBSComposer();
//    }
//    Parser* createParser(){
//        new EBSParser();
//    }
//};

void session_64(){

    AbstractFactory* nasdaqFactory = new FactoryNasdaq();
    AbstractFactory* ebsFactory = new FactoryEBS();

    Composer* composer;
    Parser* parser;

    composer = nasdaqFactory->createComposer();
    parser = nasdaqFactory->createParser();

    composer->compose();
    parser->parse();

    composer = ebsFactory->createComposer();
    parser = ebsFactory->createParser();

    composer->compose();
    parser->parse();

    delete composer;
    delete parser;
}

#endif //QUIZ_SESSION64_ABSTRACTFACTORY_H
