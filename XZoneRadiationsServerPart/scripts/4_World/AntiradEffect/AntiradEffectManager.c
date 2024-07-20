class AntiradEffectManager
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderAntiradEffect			= "AntiradFolder";
	const private static string m_FileNameAntiradEffect			= "AntiradSettings";

    ref AntiradEffect m_AntiradEffect;

    void AntiradEffectManager()
    {
        m_AntiradEffect = new AntiradEffect();

    }

    static AntiradEffectManager LoadData()
    {   
        AntiradEffectManager EffectAndDamageData = new AntiradEffectManager();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderAntiradEffect + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderAntiradEffect + "/");
		}

        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderAntiradEffect + "/" + m_FileNameAntiradEffect + ".json"))
        {
            JsonFileLoader<AntiradEffectManager>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderAntiradEffect + "/" + m_FileNameAntiradEffect + ".json", EffectAndDamageData);
        }
        else
        {
			EffectAndDamageData = CreateDefaultEffectAndDamageData();
        }
		
        return EffectAndDamageData;
    }

    protected static AntiradEffectManager CreateDefaultEffectAndDamageData()
	{
		AntiradEffectManager EffectAndDamageData = new AntiradEffectManager();
		
		SaveEffectAndDamageData(EffectAndDamageData);
		return EffectAndDamageData;
	}
	
	static void SaveEffectAndDamageData(AntiradEffectManager EffectAndDamageData)
	{
		if(!EffectAndDamageData)
		{return;}
		
		JsonFileLoader<AntiradEffectManager>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderAntiradEffect + "/" + m_FileNameAntiradEffect + ".json", EffectAndDamageData);
	}

    void SendEffectAndDamageData(PlayerBase player, PlayerIdentity identity)
    {
        //player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA, new Param1<ref Radiations>(m_Radiations), true, player.GetIdentity());
    }
}

ref AntiradEffectManager g_AntiradEffectManager;
