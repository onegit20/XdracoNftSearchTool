#include "pch.h"
#include "UrlParameter.h"

UrlParameter::UrlParameter() :listType_("sale"),
								classFuck_(0),
								levMin_(0),
								levMax_(0),
								powerMin_(0),
								powerMax_(0),
								priceMin_(0),
								priceMax_(0),
								sort_("latest"),
								page_(1),
								languageCode_("en") {}

std::string UrlParameter::listType() {
	return listType_;
}
int UrlParameter::classFuck() {
	return classFuck_;
}
void UrlParameter::set_classFuck(int classFuck) {
	classFuck_ = classFuck;
}
int UrlParameter::levMin() {
	return levMin_;
}
void UrlParameter::set_levMin(int levMin) {
	levMin_ = levMin;
}
int UrlParameter::levMax() {
	return levMax_;
}
void UrlParameter::set_levMax(int levMax) {
	levMax_ = levMax;
}
int UrlParameter::powerMin() {
	return powerMin_;
}
void UrlParameter::set_powerMin(int powerMin) {
	powerMin_ = powerMin;
}
int UrlParameter::powerMax() {
	return powerMax_;
}
void UrlParameter::set_powerMax(int powerMax) {
	powerMax_ = powerMax;
}
int UrlParameter::priceMin() {
	return priceMin_;
}
void UrlParameter::set_priceMin(int priceMin) {
	priceMin_ = priceMin;
}
int UrlParameter::priceMax() {
	return priceMax_;
}
void UrlParameter::set_priceMax(int priceMax) {
	priceMax_ = priceMax;
}
std::string UrlParameter::sort() {
	return sort_;
}
void UrlParameter::set_sort(std::string sort) {
	sort_ = sort;
}
int UrlParameter::page() {
	return page_;
}
void UrlParameter::set_page(int page) {
	page_ = page;
}
std::string UrlParameter::languageCode() {
	return languageCode_;
}
void UrlParameter::set_languageCode(std::string languageCode) {
	languageCode_ = languageCode;
}
