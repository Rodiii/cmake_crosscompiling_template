#include "CurlSender.h"

#include <iostream>

CurlSender::CurlSender() {
  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
}

CurlSender::~CurlSender() {
  if (curl) {
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}

size_t DummyWriteFunc(void* ptr, size_t size, size_t nmemb, struct string* s) {
  // do nothing
  return size * nmemb;
}

void CurlSender::SendData(const std::string& data) {
  if (!curl) return;

  /* Specify the POST data */
  struct curl_slist* headers = NULL;  // init to NULL is important
  headers = curl_slist_append(headers, "Accept: application/json");
  headers = curl_slist_append(headers, "Content-Type: application/json");
  headers = curl_slist_append(headers, "charsets: utf-8");

  std::string json_str = "{\"data\" : " + data + "}";

  /* Set the URL that is about to receive our POST. */
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8080");
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
  curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, json_str.length());
  curl_easy_setopt(curl, CURLOPT_POST, 1);
  // pipe curl return message to DummyWriteFunc to prevent stdout spam
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, DummyWriteFunc);
  // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

  /* Perform the request, res will get the return code */
  CURLcode res = curl_easy_perform(curl);
  /* Check for errors */
  if (res != CURLE_OK) {
    std::cout << "CurlSender: Error, curl_easy_perform() failed: " + std::string(curl_easy_strerror(res));
  }

  /* always cleanup */
  curl_slist_free_all(headers);
}