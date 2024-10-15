#ifndef POKEMONDAMAGE_H
#define POKEMONDAMAGE_H

#define MINUS 0.9
#define PLUS 1.1
#define UNCHANGED 1.0

namespace Pokemon{
    struct PokemonStat
    {
        /* data */
        int level; // 计算数值的时候还要用，所以里面也放一个
        int speciesStrength;
        int IV;
        int points;
        float nature;
        bool hp;
        int value;
        void CalculateStat();
    };


    class PokemonDamage
    {
    public:
        PokemonDamage();
        int level;
        PokemonStat hp;
        PokemonStat def;
        int attack;
        int power;
        float factor;
        int Damage();
    };
}
#endif // POKEMONDAMAGE_H
