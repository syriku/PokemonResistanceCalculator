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
}