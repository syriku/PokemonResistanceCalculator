#include "pokemondamage.h"
#include <iostream>

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
    hp(PokemonStat{100, 100, 31, 0, 1.0, true, 341})
    ,def(PokemonStat{100, 100, 31, 0, 1.0, false, 236})
    ,level(100)
    ,attack(246)
    ,power(90)
    ,factor(1.5)
{
}

int Pokemon::PokemonDamage::Damage()
{
    float temp1 = (2 * float(level) + 10)/250;
    float temp2 = temp1 * float(attack) / float(def.value) * float(power) + 2;
    int maxDamage = temp2 * factor;
    // debug
    std::cout<< maxDamage << std::endl;
    return maxDamage;
}
