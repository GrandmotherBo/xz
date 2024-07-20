class EffectAndDamageManager
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderDmgAndEff			= "XZoneRadiationsDmgAndEffectArray";
	const private static string m_FileNameDmgAndEff			= "DmgAndEff";

    ref DmgAnEffect m_DmgAnEffect;

    void EffectAndDamageManager()
    {
        m_DmgAnEffect = new DmgAnEffect();

    }

    static EffectAndDamageManager LoadData()
    {   
        EffectAndDamageManager EffectAndDamageData = new EffectAndDamageManager();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderDmgAndEff + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderDmgAndEff + "/");
		}

        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderDmgAndEff + "/" + m_FileNameDmgAndEff + ".json"))
        {
            JsonFileLoader<EffectAndDamageManager>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderDmgAndEff + "/" + m_FileNameDmgAndEff + ".json", EffectAndDamageData);
        }
        else
        {
			EffectAndDamageData = CreateDefaultEffectAndDamageData();
        }
		
        return EffectAndDamageData;
    }

    protected static EffectAndDamageManager CreateDefaultEffectAndDamageData()
	{
		EffectAndDamageManager EffectAndDamageData = new EffectAndDamageManager();
		
		SaveEffectAndDamageData(EffectAndDamageData);
		return EffectAndDamageData;
	}
	
	static void SaveEffectAndDamageData(EffectAndDamageManager EffectAndDamageData)
	{
		if(!EffectAndDamageData)
		{return;}
		
		JsonFileLoader<EffectAndDamageManager>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderDmgAndEff + "/" + m_FileNameDmgAndEff + ".json", EffectAndDamageData);
	}

    void SendEffectAndDamageData(PlayerBase player, PlayerIdentity identity)
    {
        //player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA, new Param1<ref Radiations>(m_Radiations), true, player.GetIdentity());
    }
}

ref EffectAndDamageManager g_EffectAndDamageManager;
