class RadResistanceManagerVest 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameVest				= "Vest";

    ref ResistVest 				m_ResistVest;

    void RadResistanceManagerVest()
    {
        m_ResistVest = new ResistVest();

    }

    static RadResistanceManagerVest LoadData()
    {   
        RadResistanceManagerVest RadiationsResistanceDataVest = new RadResistanceManagerVest(); 

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}

        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameVest + ".json"))
        {
            JsonFileLoader<RadResistanceManagerVest>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameVest + ".json", RadiationsResistanceDataVest);
        }



        else
        {
			RadiationsResistanceDataVest = CreateDefaultRadiationsResistanceDataVest();
        }
		
        return RadiationsResistanceDataVest;
    }

    protected static RadResistanceManagerVest CreateDefaultRadiationsResistanceDataVest()
	{
		RadResistanceManagerVest RadiationsResistanceDataVest = new RadResistanceManagerVest();
		
		SaveRadiationsResistanceDataVest(RadiationsResistanceDataVest);
		return RadiationsResistanceDataVest;
	}
	
	static void SaveRadiationsResistanceDataVest(RadResistanceManagerVest RadiationsResistanceDataVest)
	{
		if(!RadiationsResistanceDataVest)
		{return;}
		
		JsonFileLoader<RadResistanceManagerVest>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameVest + ".json", RadiationsResistanceDataVest);
	}
	void CreateAndLoadLog()
	{
            string Post = "====================================Resist Vest =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistVest.ArrayResistVest.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistVest.ArrayResistVest.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistVest [Name Vest:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
            
            
            
	}
    void SendRadiationsResistanceDataVest(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_VEST, new Param1<ref ResistVest>(m_ResistVest), true, player.GetIdentity());
    }
}

ref RadResistanceManagerVest g_RadResistanceManagerVest;