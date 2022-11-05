#include <iostream>
#include "LibcurlHttp.h"
#include "Url.h"
//#include "NewCharacterObjectArray.h"
#include "Character.h"
#include "vector"
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main()
{
	//system("chcp 65001");

	LibcurlHttp http;
	Url url;
	//NewCharacterObjectArray ncoa(total_count);
	//Character* character = ncoa.character();
	vector<Character> character;

	//url.set_languageCode("zh-Hans");
	url.set_classFuck(CharacterClass::ALL);
	url.set_levMin(115);
	url.set_levMax(125);
	//url.set_powerMin(250000);
	//url.set_powerMax(300000);
	//url.set_priceMin(0);
	url.set_priceMax(1000);


	string response;
	int page = 1;
	int total_count = 0;
	while (1) {
		url.set_page(page);
		url.url_update();
		bool res = http.HttpRequest(url.url(), response);
		if (res) {
			json j = json::parse(response);
			if (j["code"] == 200) {
				int first_id = j["data"]["firstID"];
				int next_total_count = j["data"]["totalCount"];
				cout << "Page: " << page << " firstID: " << first_id << " totalCount: " << next_total_count << endl;
				if (total_count != next_total_count) {
					total_count = next_total_count;
					character.resize(total_count);
				}
				//int more = j["data"]["more"];  //1表示满20条，0表示不满20条，0不代表最后一页！
				int lists_size = j["data"]["lists"].size();

				if (lists_size == 0)
					break;

				int begin_i = (page - 1) * 20;
				int end_i = begin_i + lists_size;
				for (int i = begin_i; i < end_i; ++i) {
					int j_index = i % 20;
					cout << j["data"]["lists"][j_index]["rowID"] << endl;
					character[i].set_row_id(j["data"]["lists"][j_index]["rowID"]);
					character[i].set_sequence(j["data"]["lists"][j_index]["seq"]);

					character[i].set_transport_id(j["data"]["lists"][j_index]["transportID"]);
					string response_training;
					http.HttpRequest(
						url.baseurl_training() + "?transportID=" + to_string(character[i].transport_id()) + "&languageCode=" + url.languageCode(),
						response_training);
					json j_training = json::parse(response_training);
					character[i].set_consitution_level(j_training["data"]["consitutionLevel"]);

					string response_spirit;
					http.HttpRequest(
						url.baseurl_spirit() + "?transportID=" + to_string(character[i].transport_id()) + "&languageCode=" + url.languageCode(),
						response_spirit);
					json j_spirit = json::parse(response_spirit);
					character[i].set_pets_count(j_spirit["data"]["inven"].size());
					int epic_count = 0, legendary_count = 0;
					for (int ii = 0; ii < character[i].pets_count(); ++ii) {
						switch (j_spirit["data"]["inven"][ii].value("grade", 0)) {
						case 4:
							++epic_count;
							break;
						case 5:
							++legendary_count;
							break;
						default:
							break;
						}
						if (j_spirit["data"]["inven"][ii]["iconPath"] == character[i].draknyan_icon_path()) {
							character[i].set_have_resurrector_darknyan(true);
						}
					}
					character[i].set_epic_pets_count(epic_count);
					character[i].set_legendary_pets_count(legendary_count);

					character[i].set_token_id(j["data"]["lists"][j_index]["nftID"]);
					character[i].set_character_name(j["data"]["lists"][j_index]["characterName"]);
					character[i].set_character_class(j["data"]["lists"][j_index]["class"]);
					character[i].set_level(j["data"]["lists"][j_index]["lv"]);
					character[i].set_power(j["data"]["lists"][j_index]["powerScore"]);
					character[i].set_price(j["data"]["lists"][j_index]["price"]);
				}
			}
		}
		page++;
	}

	cout << "End: " << total_count << endl;

	int count = 0;
	for (int i = 0; i < total_count; ++i) {
		if (character[i].legendary_pets_count() >= 3 && character[i].have_resurrector_darknyan()) {
			count++;
			cout << "购买链接： " << url.baseurl_nft_trade() << character[i].sequence() << endl;
			cout << "价格：" << character[i].price() << endl;
			cout << "体质： " << character[i].consitution_level() << endl;
			cout << "等级： " << character[i].level() << endl;
			cout << "战力： " << character[i].power() << endl;
			cout << "红宠数量： " << character[i].epic_pets_count() << endl;
			cout << "金宠数量： " << character[i].legendary_pets_count() << endl;
		}
	}
	cout << "合计： " << count << "条" << endl;

	return 0;
}
