#pragma once
#include <iostream>
#include <curl/curl.h>

class LibcurlHttp
{
public:
	LibcurlHttp();
	bool HttpRequest(std::string url, std::string& response, bool get = 1, std::string postdata = "");  //ture=GET, false=POST
	void AppendHeadersList(std::string header);
private:
	struct curl_slist* headers_list_;
};
