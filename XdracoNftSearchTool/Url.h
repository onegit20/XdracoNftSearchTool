#pragma once
#include "BaseUrl.h"
#include "UrlParameter.h"

class Url:public BaseUrl, public UrlParameter
{
public:
	Url();
	std::string url();
	void url_update();
private:
	std::string url_;
};

