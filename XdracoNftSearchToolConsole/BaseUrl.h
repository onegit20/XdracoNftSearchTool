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
	std::string baseurl_lists_;  //�����ӿ�
	std::string baseurl_holystuff_;  //ʥ��
	std::string baseurl_summary_;  //��ɫ��Ҫ
	std::string baseurl_stats_;  //����ֵ
	std::string baseurl_skills_;  //����
	std::string baseurl_spirit_;  //����
	std::string baseurl_magicstone_;  //ħʯ
	std::string baseurl_training_;  //����
	std::string baseurl_building_;  //ΰҵ
	std::string baseurl_mysticalpiece_;  //����
	std::string baseurl_assets_;  //����
	std::string baseurl_codex_;  //����
	std::string baseurl_inven_;  //����(�������������ȡ��)
	std::string baseurl_tradehistory_;  //������ʷ
	std::string baseurl_nft_trade_;  //��ɫ��������
};
