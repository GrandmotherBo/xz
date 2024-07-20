class RadResistanceManagerHelm 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameHelm				= "Helm";

    ref ResistHelm 				m_ResistHelm;

    void RadResistanceManagerHelm()
    {
        m_ResistHelm = new ResistHelm();

    }

    static RadResistanceManagerHelm LoadData()
    {   
        RadResistanceManagerHelm RadiationsResistanceDataHelm = new RadResistanceManagerHelm(); 

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}


        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameHelm + ".json"))
        {
            JsonFileLoader<RadResistanceManagerHelm>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameHelm + ".json", RadiationsResistanceDataHelm);
        }


        else
        {
			RadiationsResistanceDataHelm = CreateDefaultRadiationsResistanceDataHelm();
        }
		
        return RadiationsResistanceDataHelm;
    }

    protected static RadResistanceManagerHelm CreateDefaultRadiationsResistanceDataHelm()
	{
		RadResistanceManagerHelm RadiationsResistanceDataHelm = new RadResistanceManagerHelm();
		
		SaveRadiationsResistanceDataHelm(RadiationsResistanceDataHelm);
		return RadiationsResistanceDataHelm;
	}
	
	static void SaveRadiationsResistanceDataHelm(RadResistanceManagerHelm RadiationsResistanceDataHelm)
	{
		if(!RadiationsResistanceDataHelm)
		{return;}
		
		JsonFileLoader<RadResistanceManagerHelm>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameHelm + ".json", RadiationsResistanceDataHelm);
	}
	void CreateAndLoadLog()
	{
            string Post = "====================================Resist Helm =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistHelm.ArrayResistHelm.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistHelm.ArrayResistHelm.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistHelm [Name Helm:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}

            
	}
    void SendRadiationsResistanceDataHelm(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_HELM, new Param1<ref ResistHelm>(m_ResistHelm), true, player.GetIdentity());
    }
}

ref RadResistanceManagerHelm g_RadResistanceManagerHelm;