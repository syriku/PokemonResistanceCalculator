#ifndef POKEMONSTATE_H
#define POKEMONSTATE_H
#include<set>
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
};
}
#endif // POKEMONSTATE_H
