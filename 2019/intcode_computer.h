#pragma once
#include "common.h"

#ifndef INTCODE_COMP_H
#define INTCODE_COMP_H

class IntcodeComputer
{
  private:
    std::string file;
    int m_noun;
    int m_verb;
    std::vector<int> v;
    std::vector<int> vR;
    std::ifstream fs;
    int vSize;
  protected:
    static int haltCode;
    static int addCode;
    static int mulCode;
  public:
    IntcodeComputer(std::string file);

    void setInput(int noun, int verb);
    void run();

    int getResult() { return vR[0]; }
    int getNoun() { return m_noun; }
    int getVerb() { return m_verb; }
};

int IntcodeComputer::haltCode = 99;
int IntcodeComputer::addCode  = 1;
int IntcodeComputer::mulCode  = 2;

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
    v.push_back(std::stoi(s));
  }
  // Set defaults
  m_noun = v[1];
  m_verb = v[2];
  vR = v;
  vSize = v.size();
}

void IntcodeComputer::setInput(int noun, int verb)
{
  m_noun = noun;
  m_verb = verb;
  vR = v;
  vR[1] = m_noun;
  vR[2] = m_verb;
}

void IntcodeComputer::run()
{
  for(int i=0; i < vSize; i++)
  {
    int opCode = vR[i];
    int n1     = vR[i+1];
    int n2     = vR[i+2];
    int t      = vR[i+3];
    int v1     = vR[n1];
    int v2     = vR[n2];

    if (opCode == haltCode)
      break;

    if (opCode == addCode)
    {
      vR[t] = v1 + v2;
    }

    if (opCode == mulCode)
    {
      vR[t] = v1 * v2;
    }

    i += 3; // skip to next op
  }
}

#endif // !INTCODE_COMP_H
