class RadResistanceManagerGas_Mask 
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadResistance		= "XZoneRadiationsResistance";
	const private static string m_FileNameGas_Mask			= "Gas_Mask";

    ref ResistGas_Mask 			m_ResistGas_Mask;
    

    void RadResistanceManagerGas_Mask()
    {
        m_ResistGas_Mask = new ResistGas_Mask();

    }

    static RadResistanceManagerGas_Mask LoadData()
    {   
        RadResistanceManagerGas_Mask RadiationsResistanceDataGas_Mask = new RadResistanceManagerGas_Mask();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/");
		}

        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameGas_Mask + ".json"))
        {
            JsonFileLoader<RadResistanceManagerGas_Mask>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameGas_Mask + ".json", RadiationsResistanceDataGas_Mask);
        }

        else
        {
			RadiationsResistanceDataGas_Mask = CreateDefaultRadiationsResistanceDataGas_Mask();
        }
		
        return RadiationsResistanceDataGas_Mask;
    }

    protected static RadResistanceManagerGas_Mask CreateDefaultRadiationsResistanceDataGas_Mask()
	{
		RadResistanceManagerGas_Mask RadiationsResistanceDataGas_Mask = new RadResistanceManagerGas_Mask();
		
		SaveRadiationsResistanceDataGas_Mask(RadiationsResistanceDataGas_Mask);
		return RadiationsResistanceDataGas_Mask;
	}
	
	static void SaveRadiationsResistanceDataGas_Mask(RadResistanceManagerGas_Mask RadiationsResistanceDataGas_Mask) 
	{
		if(!RadiationsResistanceDataGas_Mask)
		{return;}
		
		JsonFileLoader<RadResistanceManagerGas_Mask>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadResistance + "/" + m_FileNameGas_Mask + ".json", RadiationsResistanceDataGas_Mask);
	}
	void CreateAndLoadLog()
	{
            string Post = "====================================Resist GasMask =====================================";
            g_ResistLogger.WriteLog(Post);
        	TStringArray ResistBodResistClothes = new TStringArray;
        	for (int i = 0; i < m_ResistGas_Mask.ArrayResistGas_Mask.Count(); i++)
        	{ 
            ResistBodResistClothes.Insert(m_ResistGas_Mask.ArrayResistGas_Mask.Get(i));
            string ResPos = ResistBodResistClothes.Get(i);
            TStringArray ResistBodResistClothes2 = new TStringArray;
            ResPos.Split("|",ResistBodResistClothes2);
            string ClassnamesClothes = ResistBodResistClothes2.Get(0);
            string ResistClothes = ResistBodResistClothes2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadResistGas_Mask [Name GasMask:%1, Resist:%2]",ClassnamesClothes,ResistClothes);
            g_ResistLogger.WriteLog(titleLog);   
        	}
            
	}
    void SendRadiationsResistanceDataGas_Mask(PlayerBase player, PlayerIdentity identity)
    {
    	float m_Gas_Filter = m_ResistGas_Mask.GasMaskConsumeFilter;
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_GAS_MASK, new Param2<float, ref ResistGas_Mask>(m_Gas_Filter, m_ResistGas_Mask), true, player.GetIdentity());
    }
}

ref RadResistanceManagerGas_Mask g_RadResistanceManagerGas_Mask;