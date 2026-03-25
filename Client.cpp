#include "Client.h"

int Client::nextCode = 1000;
int Client::totalClients = 0;

Client::Client(const std::string &n) : code(nextCode++), name(n) {
  totalClients++;
}

Client::~Client() { totalClients--; }

int Client::GetCode() const { return code; }

std::string Client::GetName() const { return name; }

int Client::GetTotalClients() { return totalClients; }