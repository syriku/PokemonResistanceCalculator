#include "pokemondata.h"
namespace Pokemon{
PokemonData::PokemonData() {}

TYPE_CHART_UNIT PokemonData::GetChart(PokemonType t)
{
    return (TypeChart).at(t);
}

TYPE_CHART_UNIT PokemonData::CrossChart(PokemonType t1, PokemonType t2)
{
    TYPE_CHART_UNIT r1 = GetChart(t1), r2 = GetChart(t2);
    //todo
    TYPE_CHART_UNIT resistance = {{}, {}, {}, {}, {}}; // x4, x2, x1/2, x1/4, 0
    // useless
    for(auto j: r1[2])
    {
        resistance[4].insert(j);
    }
    for(auto i: r2[2])
    {
        resistance[4].insert(i);
    }
    // from r1
    // weakness
    for(auto j: r1[0])
    {
        if(resistance[4].find(j) == resistance[4].end())
            resistance[1].insert(j);
    }
    // resistance
    for(auto j: r1[1])
    {
        if(resistance[4].find(j) == resistance[4].end())
            resistance[2].insert(j);
    }
    //from r2
    // weakness
    for(auto i: r2[0])
    {
        if(resistance[4].find(i) == resistance[4].end())
            if(resistance[1].find(i) == resistance[1].end()) // 对主属性不是弱点
            {
                if(resistance[2].find(i) == resistance[2].end())
                    // 新2倍弱点
                    resistance[1].insert(i);
                else
                    //弱点抗性抵消
                    resistance[2].erase(i);
            }
            else // 原本就是弱点
            {
                // 4倍弱点
                resistance[0].insert(i);
                resistance[1].erase(i);
            }
    }
    for(auto i: r2[1])
    {
        if(resistance[4].find(i) == resistance[4].end())
            if(resistance[2].find(i) == resistance[2].end()) // 对主属性不是抗性
            {
                if(resistance[1].find(i) == resistance[1].end())
                    // 新1/2倍抗性
                    resistance[2].insert(i);
                else
                    //弱点抗性抵消
                    resistance[1].erase(i);
            }
            else // 原本就是抗性
            {
                // 1/4倍抗性
                resistance[3].insert(i);
                resistance[2].erase(i);
            }
    }
    return resistance;
}
std::string PokemonData::GetType(PokemonType t)
{
    return TypeNames.at(t);
}
}