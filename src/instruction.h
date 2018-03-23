#ifndef __instruction__
#define __instruction__

#include <string>

class Instruction {
public:
  virtual void execute(Bug b);

  virtual void parse(std::string args);

protected:
  World w;
};

#endif