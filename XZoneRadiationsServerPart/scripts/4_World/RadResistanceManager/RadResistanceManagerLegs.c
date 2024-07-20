class RadResistanceManagerLegs 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameLegs				= "Legs";

    ref ResistLegs 				m_ResistLegs;

    void RadResistanceManagerLegs()
    {
        m_ResistLegs = new ResistLegs();

    }

    static RadResistanceManagerLegs LoadData()
    {   
        RadResistanceManagerLegs RadiationsResistanceDataLegs = new RadResistanceManagerLegs(); 

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}


        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameLegs + ".json"))
        {
           JsonFileLoader<RadResistanceManagerLegs>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameLegs + ".json", RadiationsResistanceDataLegs);
        }

        else
        {
			RadiationsResistanceDataLegs = CreateDefaultRadiationsResistanceDataLegs();
        }
		
        return RadiationsResistanceDataLegs;
    }

    protected static RadResistanceManagerLegs CreateDefaultRadiationsResistanceDataLegs()
	{
		RadResistanceManagerLegs RadiationsResistanceDataLegs = new RadResistanceManagerLegs();
		
		SaveRadiationsResistanceDataLegs(RadiationsResistanceDataLegs);
		return RadiationsResistanceDataLegs;
	}
	
	static void SaveRadiationsResistanceDataLegs(RadResistanceManagerLegs RadiationsResistanceDataLegs)
	{
		if(!RadiationsResistanceDataLegs)
		{return;}
		
		JsonFileLoader<RadResistanceManagerLegs>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameLegs + ".json", RadiationsResistanceDataLegs);
	}
	void CreateAndLoadLog()
	{
            string Post = "====================================Resist Legs =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistLegs.ArrayResistLegs.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistLegs.ArrayResistLegs.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistLegs [Name Legs:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
            
            
	}
    void SendRadiationsResistanceDataLegs(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_LEGS, new Param1<ref ResistLegs>(m_ResistLegs), true, player.GetIdentity());
    }
}

ref RadResistanceManagerLegs g_RadResistanceManagerLegs;