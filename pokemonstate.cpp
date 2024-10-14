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
}