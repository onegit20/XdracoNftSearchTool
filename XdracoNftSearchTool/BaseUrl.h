#pragma once
#include <iostream>

class BaseUrl
{
public:
	BaseUrl();
	std::string baseurl_lists();
	std::string baseurl_holystuff();
	std::string baseurl_summary();
	std::string baseurl_stats();
	std::string baseurl_skills();
	std::string baseurl_spirit();
	std::string baseurl_magicstone();
	std::string baseurl_training();
	std::string baseurl_building();
	std::string baseurl_mysticalpiece();
	std::string baseurl_assets();
	std::string baseurl_codex();
	std::string baseurl_inven();
	std::string baseurl_tradehistory();
	std::string baseurl_nft_trade();
private:
	std::string baseurl_lists_;  //基础接口
	std::string baseurl_holystuff_;  //圣物
	std::string baseurl_summary_;  //角色概要
	std::string baseurl_stats_;  //能力值
	std::string baseurl_skills_;  //技能
	std::string baseurl_spirit_;  //精灵
	std::string baseurl_magicstone_;  //魔石
	std::string baseurl_training_;  //修炼
	std::string baseurl_building_;  //伟业
	std::string baseurl_mysticalpiece_;  //宝牌
	std::string baseurl_assets_;  //物资
	std::string baseurl_codex_;  //宝鉴
	std::string baseurl_inven_;  //背包(龙神器从这里读取的)
	std::string baseurl_tradehistory_;  //交易历史
	std::string baseurl_nft_trade_;  //角色购买链接
};
