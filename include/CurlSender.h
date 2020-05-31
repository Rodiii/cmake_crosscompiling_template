#ifndef CURLSENDER_H_
#define CURLSENDER_H_

#include <curl/curl.h>

#include <string>

class CurlSender {
 public:
  CurlSender();
  ~CurlSender();

  void SendData(const std::string& data);

 private:
  CURL* curl = nullptr;
};

#endif  // CURLSENDER_H_
