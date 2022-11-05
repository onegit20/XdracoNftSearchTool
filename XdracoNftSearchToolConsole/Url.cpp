#include "Url.h"
#include <string>

Url::Url() {
	url_ = baseurl_lists() + "?listType=" + listType() +
							"&class=" + std::to_string(classFuck()) +
							"&levMin=" + std::to_string(levMin()) +
							"&levMax=" + std::to_string(levMax()) +
							"&powerMin=" + std::to_string(powerMin()) +
							"&powerMax=" + std::to_string(powerMax()) +
							"&priceMin=" + std::to_string(priceMin()) +
							"&priceMax=" + std::to_string(priceMax()) +
							"&sort=" + sort() +
							"&page=" + std::to_string(page()) +
							"&languageCode=" + languageCode();
}

std::string Url::url() {
	return url_;
}

void Url::url_update() {
	url_ = baseurl_lists() + "?listType=" + listType() +
							"&class=" + std::to_string(classFuck()) +
							"&levMin=" + std::to_string(levMin()) +
							"&levMax=" + std::to_string(levMax()) +
							"&powerMin=" + std::to_string(powerMin()) +
							"&powerMax=" + std::to_string(powerMax()) +
							"&priceMin=" + std::to_string(priceMin()) +
							"&priceMax=" + std::to_string(priceMax()) +
							"&sort=" + sort() +
							"&page=" + std::to_string(page()) +
							"&languageCode=" + languageCode();
}
