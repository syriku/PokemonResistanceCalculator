#include "pokemondamage.h"


void Pokemon::PokemonStat::CalculateStat()
{
    int temp = int(speciesStrength*2 + IV + float(points)/4.);
    if(hp)
    {
        // float temp = (speciesStrength*2 + IV + float(points) / 4.);
        // value = int(temp*float(level)/100)+level+10;
        value = temp * level / 100 + 10 + level;
        return;
    }
    value = temp * level / 100 + 5;
    value *= nature;

}

Pokemon::PokemonDamage::PokemonDamage():
    hp(PokemonStat{100, 100, 31, 0, 1.0, true, 0})
    ,def(PokemonStat{100, 100, 31, 0, 1.0, false, 0})
    ,level(100)
    ,attack(246)
    ,power(90)
    ,factor(1.0)
{
}
