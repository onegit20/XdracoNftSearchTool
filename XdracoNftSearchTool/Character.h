#pragma once
#include <iostream>

class Character
{
public:
	Character();
	int row_id();
	void set_row_id(int row_id);
	int sequence();
	void set_sequence(int sequence);
	int transport_id();
	void set_transport_id(int transport_id);
	std::string token_id();
	void set_token_id(std::string token_id);
	std::string character_name();
	void set_character_name(std::string character_name);

	int character_class();
	void set_character_class(int character_class);
	int level();
	void set_level(int level);
	int power();
	void set_power(int power);
	int price();
	void set_price(int price);

	int pets_count();
	void set_pets_count(int pets_count);
	int uncommon_pets_count();
	void set_uncommon_pets_count(int uncommon_pets_count);
	int rare_pets_count();
	void set_rare_pets_count(int rare_pets_count);
	int epic_pets_count();
	void set_epic_pets_count(int epic_pets_count);
	int legendary_pets_count();
	void set_legendary_pets_count(int legendary_pets_count);
	bool have_resurrector_darknyan();
	void set_have_resurrector_darknyan(bool have_resurrector_darknyan);
	const char* draknyan_icon_path();

	int inven_count();
	void set_inven_count(int inven_count);
	int legendary_core_count();
	void set_legendary_core_count(int legendary_core_count);
	int legendary_book_count();
	void set_legendary_book_count(int legendary_book_count);

	int meterial_secret_01();
	void set_meterial_secret_01(int meterial_secret_01);
	int meterial_secret_02();
	void set_meterial_secret_02(int meterial_secret_02);
	int meterial_secret_03();
	void set_meterial_secret_03(int meterial_secret_03);
	int meterial_secret_04();
	void set_meterial_secret_04(int meterial_secret_04);

	int consitution_level();
	void set_consitution_level(int consitution_level);

	std::string codex_character_total();
	void set_codex_character_total(std::string codex_character_total);
	std::string codex_character_completed();
	void set_codex_character_completed(std::string codex_character_completed);
	std::string codex_character_inprogress();
	void set_codex_character_inprogress(std::string codex_character_inprogress);
	std::string codex_reputation_total();
	void set_codex_reputation_total(std::string codex_reputation_total);
	std::string codex_reputation_completed();
	void set_codex_reputation_completed(std::string codex_reputation_completed);
	std::string codex_reputation_inprogress();
	void set_codex_reputation_inprogress(std::string codex_reputation_inprogress);
	std::string codex_server_total();
	void set_codex_server_total(std::string codex_server_total);
	std::string codex_server_completed();
	void set_codex_server_completed(std::string codex_server_completed);
	std::string codex_server_inprogress();
	void set_codex_server_inprogress(std::string codex_server_inprogress);
private:
	int row_id_;  //rowID
	int sequence_;  //seq
	int transport_id_;  //transportID
	std::string token_id_;  //nftID
	std::string character_name_;  //characterName

	int character_class_;  //class
	int level_;  //lv
	int power_;  //powerScore
	int price_;  //price

	int pets_count_;
	int uncommon_pets_count_;
	int rare_pets_count_;
	int epic_pets_count_;
	int legendary_pets_count_;
	bool have_resurrector_darknyan_;
	const char* draknyan_icon_path_;

	int inven_count_;
	int legendary_core_count_;
	int legendary_book_count_;

	int meterial_secret_01_;
	int meterial_secret_02_;
	int meterial_secret_03_;
	int meterial_secret_04_;

	int consitution_level_;

	std::string codex_character_total_;
	std::string codex_character_completed_;
	std::string codex_character_inprogress_;
	std::string codex_reputation_total_;
	std::string codex_reputation_completed_;
	std::string codex_reputation_inprogress_;
	std::string codex_server_total_;
	std::string codex_server_completed_;
	std::string codex_server_inprogress_;
};
