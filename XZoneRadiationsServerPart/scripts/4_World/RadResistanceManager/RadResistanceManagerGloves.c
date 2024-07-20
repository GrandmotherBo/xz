class RadResistanceManagerGloves 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameGloves			= "Gloves";

    ref ResistGloves 			m_ResistGloves;

    void RadResistanceManagerGloves()
    {
        m_ResistGloves = new ResistGloves(); 

    }

    static RadResistanceManagerGloves LoadData()
    {   
        RadResistanceManagerGloves RadiationsResistanceDataGloves = new RadResistanceManagerGloves();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}


        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameGloves + ".json"))
        {
            JsonFileLoader<RadResistanceManagerGloves>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameGloves + ".json", RadiationsResistanceDataGloves);
        }


        else
        {
			RadiationsResistanceDataGloves = CreateDefaultRadiationsResistanceDataGloves();
        }
		
        return RadiationsResistanceDataGloves;
    }

    protected static RadResistanceManagerGloves CreateDefaultRadiationsResistanceDataGloves()
	{
		RadResistanceManagerGloves RadiationsResistanceDataGloves = new RadResistanceManagerGloves();
		
		SaveRadiationsResistanceDataGloves(RadiationsResistanceDataGloves);
		return RadiationsResistanceDataGloves;
	}
	
	static void SaveRadiationsResistanceDataGloves(RadResistanceManagerGloves RadiationsResistanceDataGloves)
	{
		if(!RadiationsResistanceDataGloves)
		{return;}
		
		JsonFileLoader<RadResistanceManagerGloves>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameGloves + ".json", RadiationsResistanceDataGloves);
	}
	void CreateAndLoadLog()
	{
            string Post = "====================================Resist Gloves =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistGloves.ArrayResistGloves.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistGloves.ArrayResistGloves.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistGloves [Name Gloves:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
            
	}
    void SendRadiationsResistanceDataGloves(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_GLOVES, new Param1<ref ResistGloves>(m_ResistGloves), true, player.GetIdentity());
    }
}

ref RadResistanceManagerGloves g_RadResistanceManagerGloves;