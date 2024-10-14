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
    return r1;
}
std::string PokemonData::GetType(PokemonType t)
{
    return TypeNames.at(t);
}
}