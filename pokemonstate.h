#ifndef POKEMONSTATE_H
#define POKEMONSTATE_H
#include<set>
#include<vector>
#include<string>
#include "pokemondata.h"
namespace Pokemon{
class PokemonState
{
public:
    PokemonState();
    std::set<PokemonType> types;
    // void AddType(PokemonType);
    // void RemoveType(PokemonType);
    void ChangeType(PokemonType);
    std::vector<std::string> PrintTypes();
    std::vector<std::string> GetResistance();
private:
    PokemonData database;
};
}
#endif // POKEMONSTATE_H
