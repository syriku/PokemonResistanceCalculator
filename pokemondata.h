#ifndef POKEMONDATA_H
#define POKEMONDATA_H
#include<map>
#include<string>
#include<vector>
#include<set>
#include<Qt>
#define TYPE_CHART_UNIT std::vector<std::set<PokemonType>>
namespace Pokemon{
enum PokemonType {
    Steel,       // 0, 用于表示无属性或特殊情况
    Normal,     // 1
    Fire,       // 2
    Water,      // 3
    Electric,   // 4
    Grass,      // 5
    Ice,        // 6
    Fighting,   // 7
    Poison,     // 8
    Ground,     // 9
    Flying,     // 10
    Psychic,    // 11
    Bug,        // 12
    Rock,       // 13
    Ghost,      // 14
    Dragon,     // 15
    Dark,       // 16
    Fairy       // 17
};


class PokemonData
{
private:
    // 手动创建映射
    const std::map<PokemonType, std::string> TypeNames = {  
        {Steel,       "钢"},  
        {Normal,     "一般"},  
        {Fire,       "火"},  
        {Water,      "水"},  
        {Electric,   "电"},  
        {Grass,      "草"},  
        {Ice,        "冰"},  
        {Fighting,   "格斗"},  
        {Poison,     "毒"},  
        {Ground,     "地面"},  
        {Flying,     "飞行"},  
        {Psychic,    "超能力"},  
        {Bug,        "虫"},  
        {Rock,       "岩石"},  
        {Ghost,      "幽灵"},  
        {Dragon,     "龙"},  
        {Dark,       "恶"},  
        {Fairy,      "妖精"}  
    };
    // {被攻击属性： {弱点，抵抗，无效}
    const std::map<PokemonType, std::vector<std::set<PokemonType>>> TypeChart = {
        {Steel, {{Fighting, Ground, Fire}, {Normal, Flying, Rock, Bug, Steel, Grass, Psychic, Ice, Dragon, Fairy}, {Poison}}},
        {Normal, {{Fighting}, {}, {Ghost}}},
        {Fire, {{Ground, Rock, Water}, {Bug, Steel, Fire, Grass, Ice, Fairy}, {}}},
        {Water, {{Grass, Electric}, {Steel, Fire, Water, Ice}, {}}},
        {Electric, {{Ground}, {Flying, Steel, Electric}, {}}},
        {Grass, {{Flying, Poison, Bug, Fire, Ice}, {Ground, Water, Grass, Electric}, {}}},
        {Ice, {{Fighting, Rock, Steel, Fire}, {Ice}, {}}},
        {Fighting, {{Flying, Psychic, Fairy}, {Dark, Rock, Bug}, {}}},
        {Poison, {{Ground, Psychic}, {Fighting, Poison, Grass, Fairy}, {}}},
        {Ground, {{Water, Grass, Ice}, {Poison, Rock}, {Electric}}},
        {Flying, {{Rock, Ice, Electric}, {Fighting, Bug, Grass}, {Ground}}},
        {Psychic, {{Bug, Ghost, Dark}, {Fighting, Psychic}, {}}},
        {Bug, {{Flying, Rock, Fire}, {Fighting, Ground, Grass}, {}}},
        {Rock, {{Fighting, Steel, Water, Grass}, {Normal, Flying, Poison, Fire}, {}}},
        {Ghost, {{Ghost, Dark}, {Poison, Bug}, {Normal, Fighting}}},
        {Dragon, {{Ice, Dragon, Fairy}, {Water, Fire, Grass, Electric}, {}}},
        {Dark, {{Fighting, Bug, Fairy}, {Ghost, Dark}, {Psychic}}},
        {Fairy, {{Poison, Steel}, {Fighting, Bug, Dark}, {Dragon}}}
};
public:
    PokemonData();
    TYPE_CHART_UNIT GetChart(PokemonType);
    TYPE_CHART_UNIT CrossChart(PokemonType, PokemonType);
    std::string GetType(PokemonType);
};
}
#endif // POKEMONDATA_H
