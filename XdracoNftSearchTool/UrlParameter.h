#pragma once
#include <iostream>

enum class CharacterClass {
	ALL = 0,
	WARRIOR,
	SORCERER,
	TAOIST,
	ARBALIST,
	LANCER,
};

class UrlParameter
{
public:
	UrlParameter();
	std::string listType();
	int classFuck();
	void set_classFuck(int classFuck);
	int levMin();
	void set_levMin(int levMin);
	int levMax();
	void set_levMax(int levMax);
	int powerMin();
	void set_powerMin(int powerMin);
	int powerMax();
	void set_powerMax(int powerMax);
	int priceMin();
	void set_priceMin(int priceMin);
	int priceMax();
	void set_priceMax(int priceMax);
	std::string sort();
	void set_sort(std::string sort);
	int page();
	void set_page(int page);
	std::string languageCode();
	void set_languageCode(std::string languageCode);
private:
	std::string listType_;
	int classFuck_;  //为什么要用class关键字！
	int levMin_;  /* 60 */
	int levMax_;  /* 170 */
	int powerMin_;  /* 100000 */
	int powerMax_;  /* 350000 */
	int priceMin_;
	int priceMax_;
	std::string sort_;  /* latest, oldest, pricehigh, pricelow, lvhigh, pshigh */
	int page_;
	std::string languageCode_;  /* en, zh-Hans, ... */
};

