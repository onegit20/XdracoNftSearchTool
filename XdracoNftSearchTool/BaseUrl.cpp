#include "pch.h"
#include "BaseUrl.h"

BaseUrl::BaseUrl() :baseurl_lists_("https://webapi.mir4global.com/nft/lists"),
					baseurl_holystuff_("https://webapi.mir4global.com/nft/character/holystuff"),
					baseurl_summary_("https://webapi.mir4global.com/nft/character/summary"),
					baseurl_stats_("https://webapi.mir4global.com/nft/character/stats"),
					baseurl_skills_("https://webapi.mir4global.com/nft/character/skills"),
					baseurl_spirit_("https://webapi.mir4global.com/nft/character/spirit"),
					baseurl_magicstone_("https://webapi.mir4global.com/nft/character/magicstone"),
					baseurl_training_("https://webapi.mir4global.com/nft/character/training"),
					baseurl_building_("https://webapi.mir4global.com/nft/character/building"),
					baseurl_mysticalpiece_("https://webapi.mir4global.com/nft/character/mysticalpiece"),
					baseurl_assets_("https://webapi.mir4global.com/nft/character/assets"),
					baseurl_codex_("https://webapi.mir4global.com/nft/character/codex"),
					baseurl_inven_("https://webapi.mir4global.com/nft/character/inven"),
					baseurl_tradehistory_("https://webapi.mir4global.com/nft/character/tradehistory"),
					baseurl_nft_trade_("https://www.xdraco.com/nft/trade/") {}

std::string BaseUrl::baseurl_lists() { return baseurl_lists_; }
std::string BaseUrl::baseurl_holystuff() { return baseurl_holystuff_; }
std::string BaseUrl::baseurl_summary() { return baseurl_summary_; }
std::string BaseUrl::baseurl_stats() { return baseurl_stats_; }
std::string BaseUrl::baseurl_skills() { return baseurl_skills_; }
std::string BaseUrl::baseurl_spirit() { return baseurl_spirit_; }
std::string BaseUrl::baseurl_magicstone() { return baseurl_magicstone_; }
std::string BaseUrl::baseurl_training() { return baseurl_training_; }
std::string BaseUrl::baseurl_building() { return baseurl_building_; }
std::string BaseUrl::baseurl_mysticalpiece() { return baseurl_mysticalpiece_; }
std::string BaseUrl::baseurl_assets() { return baseurl_assets_; }
std::string BaseUrl::baseurl_codex() { return baseurl_codex_; }
std::string BaseUrl::baseurl_inven() { return baseurl_inven_; }
std::string BaseUrl::baseurl_tradehistory() { return baseurl_tradehistory_; }
std::string BaseUrl::baseurl_nft_trade() { return baseurl_nft_trade_; }
