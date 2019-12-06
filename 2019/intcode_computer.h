#pragma once
#include "common.h"

#ifndef INTCODE_COMP_H
#define INTCODE_COMP_H

class IntcodeComputer
{
  private:
    int mNoun;
    int mVerb;
    std::vector<int> intCode;
    std::vector<int> pIntCode;
    std::ifstream fs;
    int pSize;
    int pMode;
    void prepOperation(int&, int);
  protected:
    static const int haltCode;
    static const int addCode;
    static const int mulCode;
    static const int inCode;
    static const int outCode;
  public:
    IntcodeComputer(std::string);

    void setInput(int, int);
    void run();

    int getResult() { return pIntCode[0]; }
    int getNoun() { return mNoun; }
    int getVerb() { return mVerb; }
};

const int IntcodeComputer::haltCode = 99;
const int IntcodeComputer::addCode = 1;
const int IntcodeComputer::mulCode = 2;
const int IntcodeComputer::inCode = 3;
const int IntcodeComputer::outCode = 4;

IntcodeComputer::IntcodeComputer(std::string file)
{
  fs.open(file);

  if (!fs)
  {
    std::cerr << "File: " << file << " could not be opened";
    exit(1);
  }

  std::string s;
  while (std::getline(fs, s, ','))
  {
    intCode.push_back(std::stoi(s));
  }
  // Set defaults
  mNoun = intCode[1];
  mVerb = intCode[2];
  pIntCode = intCode;
  pSize = pIntCode.size();
}

void IntcodeComputer::setInput(int noun, int verb)
{
  mNoun = noun;
  mVerb = verb;
  pIntCode = intCode;
  pIntCode[1] = mNoun;
  pIntCode[2] = mVerb;
}

void IntcodeComputer::prepOperation(int& opCode,int code)
{
  std::vector<int> params = splitInt(code);
  opCode = code;
}

void IntcodeComputer::run()
{
  for(int i=0; i < pSize; i++)
  {
    int opCode;
    prepOperation(opCode, pIntCode[i]);
    int n1     = pIntCode[i+1];
    int n2     = pIntCode[i+2];
    int t      = pIntCode[i+3];
    int v1     = pIntCode[n1];
    int v2     = pIntCode[n2];

    switch(opCode)
    {
      case addCode:
        pIntCode[t] = v1 + v2;
      break;
      case mulCode:
        pIntCode[t] = v1 * v2;
      break;
      case haltCode:
      default:
      break;
    }

    i += 3; // skip to next op
  }
}

#endif // !INTCODE_COMP_H
