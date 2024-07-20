class RadResistanceManagerBody 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameBody				= "Body";

    ref ResistBody 				m_ResistBody;

    void RadResistanceManagerBody()
    {
        m_ResistBody = new ResistBody();
    }

    static RadResistanceManagerBody LoadData()
    {   
        RadResistanceManagerBody RadiationsResistanceDataBody = new RadResistanceManagerBody();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}


        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameBody + ".json"))
        {
            JsonFileLoader<RadResistanceManagerBody>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameBody + ".json", RadiationsResistanceDataBody);
        }
        else
        {
			RadiationsResistanceDataBody = CreateDefaultRadiationsResistanceDataBody();
        }
		
        return RadiationsResistanceDataBody;
    }

    protected static RadResistanceManagerBody CreateDefaultRadiationsResistanceDataBody()
	{ 
		RadResistanceManagerBody RadiationsResistanceDataBody = new RadResistanceManagerBody();
		
		SaveRadiationsResistanceDataBody(RadiationsResistanceDataBody);
		return RadiationsResistanceDataBody;
	}
	
	static void SaveRadiationsResistanceDataBody(RadResistanceManagerBody RadiationsResistanceDataBody)
	{
		if(!RadiationsResistanceDataBody)
		{return;}
		
		JsonFileLoader<RadResistanceManagerBody>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameBody + ".json", RadiationsResistanceDataBody);
	}
		void CreateAndLoadLog()
	{
            string Post = "====================================Resist Body =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistBody.ArrayResistBody.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistBody.ArrayResistBody.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistBody [Name Body:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
            
	}
    void SendRadiationsResistanceDataBody(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_BODY, new Param1<ref ResistBody>(m_ResistBody), true, player.GetIdentity());
    }
}

ref RadResistanceManagerBody g_RadResistanceManagerBody;