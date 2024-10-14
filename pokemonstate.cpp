#include "pokemonstate.h"
namespace Pokemon{
PokemonState::PokemonState() {}
void PokemonState::ChangeType(PokemonType arg)
{
    if(types.find(arg) != types.end())
    {
        types.erase(arg);
    }
    else 
    {
        types.insert(arg);
    }
}
std::vector<std::string> PokemonState::PrintTypes()
{
    std::vector<std::string> str;
    for(const auto& i: types)
    {
        str.push_back(database.GetType(i));
    }
    return str;
}
std::vector<std::string> PokemonState::GetResistance()
{
    if(types.size() == 0) return {"","",""};
    std::vector<std::string> resistance_str;

    TYPE_CHART_UNIT resistance;
    std::vector<PokemonType> type_vec;
    for(auto i: types)
    {
        type_vec.push_back(i);
    }
    if(type_vec.size()==1)
    {

        auto r1 = database.GetChart(type_vec[0]);
        resistance = {{},r1[0], r1[1], {}, r1[2]};
        // return ans;
    }
    else
    {
        resistance = database.CrossChart(type_vec[0], type_vec[1]);
    }

    std::string weakness = "";
    for(auto i: resistance[0])
    {
        //4倍弱点
        weakness += database.GetType(i);
        weakness += "（4倍）";
        weakness += ", ";
    }
    for(auto i: resistance[1])
    {
        //2倍弱点
        weakness += database.GetType(i);
        // weakness += "（4倍）";
        weakness += ", ";
    }
    if(weakness.size() != 0)
    {
        weakness.pop_back();
        weakness.pop_back();
    }

    std::string resis = "";
    for(auto i: resistance[3])
    {
        //4倍抗性
        resis += database.GetType(i);
        resis += "（4倍）";
        resis += ", ";
    }
    for(auto i: resistance[2])
    {
        //2倍抗性
        resis += database.GetType(i);
        // weakness += "（4倍）";
        resis += ", ";
    }
    if(resis.size() != 0)
    {
        resis.pop_back();
        resis.pop_back();
    }

    std::string useless = "";
    for(auto i: resistance[4])
    {
        useless += database.GetType(i);
        useless += ", ";
    }
    if(useless.size() != 0)
    {
        useless.pop_back();
        useless.pop_back();
    }
    resistance_str.push_back(weakness);
    resistance_str.push_back(resis);
    resistance_str.push_back(useless);
    return resistance_str;
}
}
