#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
  int code;
  std::string name;

  static int nextCode;
  static int totalClients;

public:
  Client(const std::string &n);
  ~Client();

  int GetCode() const;
  std::string GetName() const;

  static int GetTotalClients();
};

#endif