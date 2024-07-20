modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        g_RadiationsPosManager = new RadiationsPosManager();
        g_ResistLogger = new ResistLogger();
        g_RadPosLogger = new RadPosLogger();
        g_RadiationsPosManager = RadiationsPosManager.LoadData();

        
        g_RadResistanceManagerBackpacks     =   new RadResistanceManagerBackpacks();
        g_RadResistanceManagerBody          =   new RadResistanceManagerBody();
        g_RadResistanceManagerFeet          =   new RadResistanceManagerFeet();
        g_RadResistanceManagerGas_Mask      =   new RadResistanceManagerGas_Mask();
        g_RadResistanceManagerGloves        =   new RadResistanceManagerGloves ();
        g_RadResistanceManagerHelm          =   new RadResistanceManagerHelm();
        g_RadResistanceManagerLegs          =   new RadResistanceManagerLegs();
        g_RadResistanceManagerVest          =   new RadResistanceManagerVest();

        


        g_RadResistanceManagerBackpacks     =   g_RadResistanceManagerBackpacks.LoadData();
        g_RadResistanceManagerBody          =   g_RadResistanceManagerBody.LoadData();
        g_RadResistanceManagerFeet          =   g_RadResistanceManagerFeet.LoadData();
        g_RadResistanceManagerGas_Mask      =   g_RadResistanceManagerGas_Mask.LoadData();
        g_RadResistanceManagerGloves        =   g_RadResistanceManagerGloves.LoadData();
        g_RadResistanceManagerHelm          =   g_RadResistanceManagerHelm.LoadData();
        g_RadResistanceManagerLegs          =   g_RadResistanceManagerLegs.LoadData();
        g_RadResistanceManagerVest          =   g_RadResistanceManagerVest.LoadData();


        g_EffectAndDamageManager            =   new EffectAndDamageManager();
        g_EffectAndDamageManager            =   g_EffectAndDamageManager.LoadData();

        g_AntiradEffectManager              =   new AntiradEffectManager();
        g_AntiradEffectManager              =   g_AntiradEffectManager.LoadData();

        g_RadiationsPosManager.CreateAndLoadLog();

        g_RadResistanceManagerBackpacks.CreateAndLoadLog();
        g_RadResistanceManagerBody.CreateAndLoadLog();
        g_RadResistanceManagerFeet.CreateAndLoadLog();
        g_RadResistanceManagerGas_Mask.CreateAndLoadLog();
        g_RadResistanceManagerGloves.CreateAndLoadLog();
        g_RadResistanceManagerHelm.CreateAndLoadLog();
        g_RadResistanceManagerLegs.CreateAndLoadLog();
        g_RadResistanceManagerVest.CreateAndLoadLog();

        
    }

    void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        g_RadiationsPosManager.SendRadiationsPosData(player, identity);
        
        g_RadResistanceManagerBackpacks.SendRadiationsResistanceDataBackpacks(player, identity);

        g_RadResistanceManagerBody.SendRadiationsResistanceDataBody(player, identity);

        g_RadResistanceManagerFeet.SendRadiationsResistanceDataFeet(player, identity);


        g_RadResistanceManagerGas_Mask.SendRadiationsResistanceDataGas_Mask(player, identity);

        g_RadResistanceManagerGloves.SendRadiationsResistanceDataGloves(player, identity);

        g_RadResistanceManagerHelm.SendRadiationsResistanceDataHelm(player, identity);

        g_RadResistanceManagerLegs.SendRadiationsResistanceDataLegs(player, identity);

        g_RadResistanceManagerVest.SendRadiationsResistanceDataVest(player, identity);

    }

    
}