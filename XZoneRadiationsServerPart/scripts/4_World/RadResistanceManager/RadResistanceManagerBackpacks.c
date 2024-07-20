class RadResistanceManagerBackpacks 
{
	
    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameBackpacks			= "Backpacks";

	const private static string m_FolderRadZones			= "XZoneRadiationsZonesArray";
	const private static string m_FileNameRadZones			= "Radiations";

    ref ResistBackpacks 		m_ResistBackpacks;

    void RadResistanceManagerBackpacks()
    {
        m_ResistBackpacks = new ResistBackpacks();

    }

    static RadResistanceManagerBackpacks LoadData()
    {   
        RadResistanceManagerBackpacks RadiationsResistanceDataBackpacks = new RadResistanceManagerBackpacks();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}


        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameBackpacks + ".json"))
        {
            JsonFileLoader<RadResistanceManagerBackpacks>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameBackpacks + ".json", RadiationsResistanceDataBackpacks);
        }


        else
        {
			RadiationsResistanceDataBackpacks = CreateDefaultRadiationsResistanceDataBackpacks();
        }
		
        return RadiationsResistanceDataBackpacks;
    }

    protected static RadResistanceManagerBackpacks CreateDefaultRadiationsResistanceDataBackpacks()
	{
		RadResistanceManagerBackpacks RadiationsResistanceDataBackpacks = new RadResistanceManagerBackpacks();
		
		SaveRadiationsResistanceDataBackpacks(RadiationsResistanceDataBackpacks);
		return RadiationsResistanceDataBackpacks;
	}
	
	static void SaveRadiationsResistanceDataBackpacks(RadResistanceManagerBackpacks RadiationsResistanceDataBackpacks)
	{
		if(!RadiationsResistanceDataBackpacks)
		{return;}
		
		JsonFileLoader<RadResistanceManagerBackpacks>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameBackpacks + ".json", RadiationsResistanceDataBackpacks);
	}

	void CreateAndLoadLog()
	{
            string Post = "====================================Resist Backpacks =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistBackpacks.ArrayResistBackpacks.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistBackpacks.ArrayResistBackpacks.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistBackpacks [Name Backpacks:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
            
	}
    void SendRadiationsResistanceDataBackpacks(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_BAKPACK, new Param1<ref ResistBackpacks>(m_ResistBackpacks), true, player.GetIdentity());
    }
}

ref RadResistanceManagerBackpacks g_RadResistanceManagerBackpacks;