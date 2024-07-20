class RadiationsPosManager
{

    const private static string m_ProfilePath			    = "$profile:";
	const private static string m_FolderNameRadiationsXzone	= "XZoneRadiations";
	const private static string m_FolderRadZones			= "XZoneRadiationsZonesArray";
	const private static string m_FileNameRadZones			= "Radiations";

    ref Radiations m_Radiations;

    void RadiationsPosManager()
    {
        m_Radiations = new Radiations();

    }

    static RadiationsPosManager LoadData()
    {   
        RadiationsPosManager RadiationsPosData = new RadiationsPosManager();

        if (!FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadZones + "/"))
        {
			MakeDirectory(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadZones + "/");
		}

        if (FileExist(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadZones + "/" + m_FileNameRadZones + ".json"))
        {
            JsonFileLoader<RadiationsPosManager>.JsonLoadFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadZones + "/" + m_FileNameRadZones + ".json", RadiationsPosData);
        }
        else
        {
			RadiationsPosData = CreateDefaultRadiationsPosData();
        }
		
        return RadiationsPosData;
    }

    protected static RadiationsPosManager CreateDefaultRadiationsPosData()
	{
		RadiationsPosManager RadiationsPosData = new RadiationsPosManager();
		
		SaveRadiationsPosData(RadiationsPosData);
		return RadiationsPosData;
	}
	
	static void SaveRadiationsPosData(RadiationsPosManager RadiationsPosData)
	{
		if(!RadiationsPosData)
		{return;}
		
		JsonFileLoader<RadiationsPosManager>.JsonSaveFile(m_ProfilePath + m_FolderNameRadiationsXzone + "/" + m_FolderRadZones + "/" + m_FileNameRadZones + ".json", RadiationsPosData);
	}
	void CreateAndLoadLog()
	{
        	TStringArray RadiationsPositionsLog = new TStringArray;
        	for (int i = 0; i < m_Radiations.Positions.Count(); i++)
        	{ 
            RadiationsPositionsLog.Insert(m_Radiations.Positions.Get(i));
            string ResPos = RadiationsPositionsLog.Get(i);
            TStringArray RadiationsPositionsLog2 = new TStringArray;
            ResPos.Split("|",RadiationsPositionsLog2);
            string Positions = RadiationsPositionsLog2.Get(0);
            string Radius = RadiationsPositionsLog2.Get(1);
            string Power = RadiationsPositionsLog2.Get(2);
            string Locations = RadiationsPositionsLog2.Get(3);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            string titleLog = string.Format("[Load]RadZonesPos [Positions:%1, Radius:%2, Power:%3, Locations:%4]",Positions,Radius,Power,Locations);
            g_RadPosLogger.WriteLog(titleLog);   
        	}
            
	}
    void SendRadiationsPosData(PlayerBase player, PlayerIdentity identity)
    {
        player.RPCSingleParam(XZONERADc.SERVER_SEND_MAIN_DATA, new Param1<ref Radiations>(m_Radiations), true, player.GetIdentity());
    }
}

ref RadiationsPosManager g_RadiationsPosManager;
