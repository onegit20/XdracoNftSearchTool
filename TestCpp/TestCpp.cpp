#include <iostream>
#include <tchar.h>
#include <vector>
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main()
{
    /*
    cout << "中文" << endl;
    //请求算法设计
    int total_count = 13;
    int pages = total_count % 20 == 0 ? total_count / 20 : total_count / 20 + 1;

    cout << "Pages: " << pages << endl;

    for (int p = 1; p <= pages; ++p) {
        if (p < pages) {
            for (int i = (p - 1) * 20; i < p * 20; ++i) {
                cout << i << endl;
            }
        }
        else {
            for (int i = (p - 1) * 20; i < (total_count % 20 == 0 ? p * 20 : ( p - 1 ) * 20 + total_count % 20); ++i) {
                cout << i << endl;
            }
        }
    }*/

    /*
    //system("chcp 65001");
    json j = json::parse(R"(
    {
        "code": 200,
        "data": {
            "firstID": 738523,
            "totalCount": 1986,
            "more": 0,
            "lists": [
                {
                    "rowID": 1981,
                    "seq": 717842,
                    "transportID": 108434,
                    "nftID": "14287",
                    "sealedDT": 1645267723,
                    "characterName": "Maralz420",
                    "class": 2,
                    "lv": 111,
                    "powerScore": 158188,
                    "price": 100,
                    "MirageScore": 0,
                    "MiraX": 0,
                    "Reinforce": 0,
                    "stat": [
                        {
                            "statName": "HP",
                            "statValue": 82992
                        },
                        {
                            "statName": "MP",
                            "statValue": 10947
                        },
                        {
                            "statName": "PHYS ATK",
                            "statValue": 1204
                        },
                        {
                            "statName": "Spell ATK",
                            "statValue": 5169
                        },
                        {
                            "statName": "PHYS DEF",
                            "statValue": 3060
                        },
                        {
                            "statName": "Spell DEF",
                            "statValue": 3099
                        }
                    ]
                },
                {
                    "rowID": 1983,
                    "seq": 717782,
                    "transportID": 61976,
                    "nftID": "39004",
                    "sealedDT": 1653226074,
                    "characterName": "IamYoursToo",
                    "class": 1,
                    "lv": 80,
                    "powerScore": 118780,
                    "price": 280,
                    "MirageScore": 0,
                    "MiraX": 0,
                    "Reinforce": 0,
                    "stat": [
                        {
                            "statName": "HP",
                            "statValue": 61147
                        },
                        {
                            "statName": "MP",
                            "statValue": 7285
                        },
                        {
                            "statName": "PHYS ATK",
                            "statValue": 3810
                        },
                        {
                            "statName": "Spell ATK",
                            "statValue": 916
                        },
                        {
                            "statName": "PHYS DEF",
                            "statValue": 2230
                        },
                        {
                            "statName": "Spell DEF",
                            "statValue": 2275
                        }
                    ]
                }
            ]
        }
    }
    )");

    json j2 = json::parse(R"(
    {
        "code": 200,
        "data": {
            "firstID": 738540,
            "totalCount": 1990,
            "more": 0,
            "lists": [ ]
        }
    }
    )");

    cout << j["data"]["lists"] << endl;
    cout << j["data"]["lists"].size() << endl;

    cout << j2["data"]["lists"] << endl;
    cout << j2["data"]["lists"].size() << endl;
    */

    //int e = 1;
    //while (1) {


    //    vector<int> a;

    //    for (int i = 1; i < 3; ++i) {
    //        a.push_back(i);
    //    }

    //    for (auto x : a)
    //        cout << x << endl;
    //    if (e == 3)
    //        break;

    //    e++;

    //}

cout << true << endl;

    return 0;

}


