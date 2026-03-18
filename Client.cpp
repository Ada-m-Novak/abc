#include "Client.h"

Client::Client(int c, const std::string &n) : code(c), name(n) {}

int Client::GetCode() const { return code; }

std::string Client::GetName() const { return name; }