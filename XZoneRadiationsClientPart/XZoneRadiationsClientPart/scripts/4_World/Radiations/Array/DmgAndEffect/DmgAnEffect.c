class DmgAnEffect
{
    ref array<ref DmgAnEffectChange> RadDamageAndEffect = { new DmgAnEffectChange };
}
class DmgAnEffectChange
{
    int InRadMin;
    int InRadMax;
    bool Damage = true;
    int EffectDamageOnceInTime;
    float HowDamage;

    bool Cough = true;
    int EffectCoughOnceInTime;

    bool Vomit = true;
    int EffectVomitOnceInTime;

    bool Bleeding = true;
    int EffectBleedingOnceInTime;
    int HowManyBleeding;
}

