#include "pch.h"
#include "Character.h"

Character::Character() :
	pets_count_(0),
	uncommon_pets_count_(0),
	rare_pets_count_(0),
	epic_pets_count_(0),
	legendary_pets_count_(0),
	have_resurrector_darknyan_(false),
	draknyan_icon_path_("https://file.mir4global.com/xdraco-thumb/Content/UI/Atlas_N_Resource/Icon/Pet/Pet_Portrait/Icon_Item_Pet_Cat03.png"),
	consitution_level_(0),
	legendary_core_count_(0),
	legendary_book_count_(0),
	meterial_secret_01_(0),
	meterial_secret_02_(0),
	meterial_secret_03_(0),
	meterial_secret_04_(0) {}

int Character::row_id() {
	return row_id_;
}
void Character::set_row_id(int row_id) {
	row_id_ = row_id;
}
int Character::sequence() {
	return sequence_;
}
void Character::set_sequence(int sequence) {
	sequence_ = sequence;
}
int Character::transport_id() {
	return transport_id_;
}
void Character::set_transport_id(int transport_id) {
	transport_id_ = transport_id;
}
std::string Character::token_id() {
	return token_id_;
}
void Character::set_token_id(std::string token_id) {
	token_id_ = token_id;
}
std::string Character::character_name() {
	return character_name_;
}
void Character::set_character_name(std::string character_name) {
	character_name_ = character_name;
}

int Character::character_class() {
	return character_class_;
}
void Character::set_character_class(int character_class) {
	character_class_ = character_class;
}
int Character::level() {
	return level_;
}
void Character::set_level(int level) {
	level_ = level;
}
int Character::power() {
	return power_;
}
void Character::set_power(int power) {
	power_ = power;
}
int Character::price() {
	return price_;
}
void Character::set_price(int price) {
	price_ = price;
}

int Character::pets_count() { return pets_count_; }
void Character::set_pets_count(int pets_count) { pets_count_ = pets_count; }
int Character::uncommon_pets_count() { return uncommon_pets_count_; }
void Character::set_uncommon_pets_count(int uncommon_pets_count) { uncommon_pets_count_ = uncommon_pets_count; }
int Character::rare_pets_count() { return rare_pets_count_; }
void Character::set_rare_pets_count(int rare_pets_count) { rare_pets_count_ = rare_pets_count; }
int Character::epic_pets_count() { return epic_pets_count_; }
void Character::set_epic_pets_count(int epic_pets_count) { epic_pets_count_ = epic_pets_count; }
int Character::legendary_pets_count() { return legendary_pets_count_; }
void Character::set_legendary_pets_count(int legendary_pets_count) { legendary_pets_count_ = legendary_pets_count; }
bool Character::have_resurrector_darknyan() { return have_resurrector_darknyan_; }
void Character::set_have_resurrector_darknyan(bool have_resurrector_darknyan) { have_resurrector_darknyan_ = have_resurrector_darknyan; }
const char* Character::draknyan_icon_path() { return draknyan_icon_path_; }

int Character::inven_count() { return inven_count_; }
void Character::set_inven_count(int inven_count) { inven_count_ = inven_count; }
int Character::legendary_core_count() { return legendary_core_count_; }
void Character::set_legendary_core_count(int legendary_core_count) { legendary_core_count_ = legendary_core_count; }
int Character::legendary_book_count() { return legendary_book_count_; }
void Character::set_legendary_book_count(int legendary_book_count) { legendary_book_count_ = legendary_book_count; }

int Character::meterial_secret_01() { return meterial_secret_01_; }
void Character::set_meterial_secret_01(int meterial_secret_01) { meterial_secret_01_ = meterial_secret_01; }
int Character::meterial_secret_02() { return meterial_secret_02_; }
void Character::set_meterial_secret_02(int meterial_secret_02) { meterial_secret_02_ = meterial_secret_02; }
int Character::meterial_secret_03() { return meterial_secret_03_; }
void Character::set_meterial_secret_03(int meterial_secret_03) { meterial_secret_03_ = meterial_secret_03; }
int Character::meterial_secret_04() { return meterial_secret_04_; }
void Character::set_meterial_secret_04(int meterial_secret_04) { meterial_secret_04_ = meterial_secret_04; }

int Character::consitution_level() {
	return consitution_level_;
}
void Character::set_consitution_level(int consitution_level) {
	consitution_level_ = consitution_level;
}

std::string Character::codex_character_total() { return codex_character_total_; }
void Character::set_codex_character_total(std::string codex_character_total) { codex_character_total_ = codex_character_total; }
std::string Character::codex_character_completed() { return codex_character_completed_; }
void Character::set_codex_character_completed(std::string codex_character_completed) { codex_character_completed_ = codex_character_completed; }
std::string Character::codex_character_inprogress() { return codex_character_inprogress_; }
void Character::set_codex_character_inprogress(std::string codex_character_inprogress) { codex_character_inprogress_ = codex_character_inprogress; }
std::string Character::codex_reputation_total() { return codex_reputation_total_; }
void Character::set_codex_reputation_total(std::string codex_reputation_total) { codex_reputation_total_ = codex_reputation_total; }
std::string Character::codex_reputation_completed() { return codex_reputation_completed_; }
void Character::set_codex_reputation_completed(std::string codex_reputation_completed) { codex_reputation_completed_ = codex_reputation_completed; }
std::string Character::codex_reputation_inprogress() { return codex_reputation_inprogress_; }
void Character::set_codex_reputation_inprogress(std::string codex_reputation_inprogress) { codex_reputation_inprogress_ = codex_reputation_inprogress; }
std::string Character::codex_server_total() { return codex_server_total_; }
void Character::set_codex_server_total(std::string codex_server_total) { codex_server_total_ = codex_server_total; }
std::string Character::codex_server_completed() { return codex_server_completed_; }
void Character::set_codex_server_completed(std::string codex_server_completed) { codex_server_completed_ = codex_server_completed; }
std::string Character::codex_server_inprogress() { return codex_server_inprogress_; }
void Character::set_codex_server_inprogress(std::string codex_server_inprogress) { codex_server_inprogress_ = codex_server_inprogress; }
