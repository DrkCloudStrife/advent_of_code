#pragma once
#include "../shared/cpp/common.h"
#include <map>

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
    std::map<std::string,int> prepareOperations(int);
    int autoInputVal = { -999 }; // not ideal, but...
  protected:
    static const int haltCode;
    static const int addCode;
    static const int mulCode;
    static const int inCode;
    static const int outCode;
    static const int jmpTCode;
    static const int jmpFCode;
    static const int ltCode;
    static const int eqCode;
  public:
    IntcodeComputer(std::string);

    void setInput(int, int);
    void run();
    void runTest();
    void runTest(int);
    void reset();

    int getResult() { return pIntCode[0]; }
    int getResultFromPosition(int);
    int getNoun() { return mNoun; }
    int getVerb() { return mVerb; }
};

const int IntcodeComputer::haltCode = 99;
const int IntcodeComputer::addCode = 1;
const int IntcodeComputer::mulCode = 2;
const int IntcodeComputer::inCode = 3;
const int IntcodeComputer::outCode = 4;
const int IntcodeComputer::jmpTCode = 5;
const int IntcodeComputer::jmpFCode = 6;
const int IntcodeComputer::ltCode = 7;
const int IntcodeComputer::eqCode = 8;

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
  reset();
  pSize = pIntCode.size();
}

void IntcodeComputer::reset()
{
  mNoun = intCode[1];
  mVerb = intCode[2];
  pIntCode = intCode;
}

int IntcodeComputer::getResultFromPosition(int pos)
{
  return pIntCode[pos];
}

void IntcodeComputer::setInput(int noun, int verb)
{
  mNoun = noun;
  mVerb = verb;
  pIntCode = intCode;
  pIntCode[1] = mNoun;
  pIntCode[2] = mVerb;
}

// TODO: Optimize
std::map<std::string,int> IntcodeComputer::prepareOperations(int index)
{
  std::list<int> params; // ABCDE
  std::map<std::string,int> ops;

  int code = pIntCode[index];
  int oc1;
  int oc2;

  if (code < 100) // short circuit
  {
    ops["operation"] = code;
    ops["param1"] = 0;
    ops["param2"] = 0;
    // ops["param3"] = 0; // not needed, yet?

    return ops;
  }
  else
  {
    params = splitInt(code, true);
    oc1 = params.back();
    params.pop_back();
    if (params.size() > 0)
    {
      oc2 = params.back() * 10;
      params.pop_back();
      ops["operation"] = oc2 + oc1;
    }
    else
      ops["operation"] = oc1;

    if (params.size() > 0)
      std::reverse(params.begin(),params.end());
  }

  for(int i=0; i<3; i++) // 4 operations (opCode + 3 params)
  {
    std::stringstream ss;
    ss << "param" << i+1;
    int type;
    if (params.size() > 0)
    {
      type = params.front();
      params.pop_front();
    }
    else
      type = 0;

    ops[ss.str()] = type;
  }

  return ops;
}

// Leaving as `runTest` is slower due to parameter behavior detection
void IntcodeComputer::run()
{
  for(int i=0; i < pSize; i++)
  {
    int opCode = pIntCode[i];
    int opInput1 = pIntCode[i+1];
    int opInput2 = pIntCode[i+2];
    int opTarget = pIntCode[i+3];
    int val1 = pIntCode[opInput1];
    int val2 = pIntCode[opInput2];

    if (opCode == addCode)
    {
      pIntCode[opTarget] = val1 + val2;
    }
    else if (opCode == mulCode)
    {
      pIntCode[opTarget] = val1 * val2;
    }
    else if (opCode == haltCode)
    {
      break;
    }

    i += 3; // skip to next op
  }
}

void IntcodeComputer::runTest(int autoVal)
{
  autoInputVal = autoVal;
  runTest();
}

void IntcodeComputer::runTest()
{
  for(int i=0; i < pSize; i++)
  {
    int opCode;
    int op1;
    int op2;
    int op3;
    int opTarget;
    int val1;
    int val2;
    int opShift = 3; // default params are 4, we set 3 + 1 on loop for next instruction.
    std::map<std::string,int> mOpMode;

    mOpMode = prepareOperations(i);

    opCode = mOpMode["operation"];

    if (opCode == haltCode)
      break;

    op1 = pIntCode[i+1];
    op2 = pIntCode[i+2];
    op3 = pIntCode[i+3];

    val1 = (mOpMode["param1"] == 0) ? pIntCode[op1] : op1;
    val2 = (mOpMode["param2"] == 0) ? pIntCode[op2] : op2;
    opTarget = op3;

    if (opCode == addCode)
    {
      pIntCode[opTarget] = val1 + val2;
    }
    else if (opCode == mulCode)
    {
      pIntCode[opTarget] = val1 * val2;
    }
    else if (opCode == inCode)
    {
      if (autoInputVal == -999)
      {
        std::cout << "Enter an input" << std::endl;
        std::cin >> val1;
        pIntCode[op1] = val1;
      }
      else
        pIntCode[op1] = autoInputVal;

      opShift = 1;
    }
    else if (opCode == outCode)
    {
      std::cout << "O: " << val1 << std::endl;
      opShift = 1;
    }
    else if (opCode == jmpTCode)
    {
      if(val1 != 0)
      {
        i = val2;
        opShift = -1; // due to auto-increment
      }
      else
        opShift = 2; // do nothing
    }
    else if (opCode == jmpFCode)
    {
      if(val1 == 0)
      {
        i = val2;
        opShift = -1; // due to auto-increment
      }
      else
        opShift = 2; // do nothing
    }
    else if (opCode == ltCode)
    {
      pIntCode[opTarget] = (val1 < val2) ? 1 : 0;
      opShift = 2;
    }
    else if (opCode == eqCode)
    {
      pIntCode[opTarget] = (val1 == val2) ? 1 : 0;
      opShift = 2;
    }
    else
      opShift = 0; // no new params, shift to next instruction

    i += opShift; // skip to next op
  }
}

#endif // !INTCODE_COMP_H
