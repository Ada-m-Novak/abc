#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
  int code;
  std::string name;

public:
  Client(int c, const std::string &n);

  int GetCode() const;
  std::string GetName() const;
};

#endif