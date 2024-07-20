class RadResistanceManagerFeet 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameFeet				= "Feet";

    ref ResistFeet 				m_ResistFeet;

    void RadResistanceManagerFeet()
    {
        m_ResistFeet = new ResistFeet();

    }

    static RadResistanceManagerFeet LoadData()
    {   
        RadResistanceManagerFeet RadiationsResistanceDataFeet = new RadResistanceManagerFeet();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}


        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameFeet + ".json"))
        {
           JsonFileLoader<RadResistanceManagerFeet>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameFeet + ".json", RadiationsResistanceDataFeet);
        }


        else
        {
			RadiationsResistanceDataFeet = CreateDefaultRadiationsResistanceDataFeet(); 
        }
		
        return RadiationsResistanceDataFeet;
    }

    protected static RadResistanceManagerFeet CreateDefaultRadiationsResistanceDataFeet()
	{
		RadResistanceManagerFeet RadiationsResistanceDataFeet = new RadResistanceManagerFeet();
		
		SaveRadiationsResistanceDataFeet(RadiationsResistanceDataFeet);
		return RadiationsResistanceDataFeet;
	}
	
	static void SaveRadiationsResistanceDataFeet(RadResistanceManagerFeet RadiationsResistanceDataFeet)
	{
		if(!RadiationsResistanceDataFeet)
		{return;}
		
		JsonFileLoader<RadResistanceManagerFeet>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameFeet + ".json", RadiationsResistanceDataFeet);
	}
	void CreateAndLoadLog()
	{
            string Post = "====================================Resist Feet =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistFeet.ArrayResistFeet.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistFeet.ArrayResistFeet.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistFeet [Name Feet:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
	}
    void SendRadiationsResistanceDataFeet(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_FEET, new Param1<ref ResistFeet>(m_ResistFeet), true, player.GetIdentity());
    }
}

ref RadResistanceManagerFeet g_RadResistanceManagerFeet;