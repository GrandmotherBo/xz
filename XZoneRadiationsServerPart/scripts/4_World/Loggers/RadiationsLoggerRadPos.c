class RadPosLogger 
{
    private FileHandle          m_LogFile;
    private string              m_DefaultPath = "$profile:";
    private string              m_FolderPath = "RadiationsXZoneLogs";
    private string              m_FolderSoPath = "RadiationsXZoneLogsRadPos";
    private string              m_Currentname;

    void RadPosLogger()
    {
        CheckDirectory();
        m_Currentname = CreateName();
        m_LogFile = OpenFile(m_DefaultPath + m_FolderPath + "\\" + m_FolderSoPath + "\\" + m_Currentname, FileMode.WRITE); 
        FPrintln(m_LogFile, "====================================RadPos Radiations Logs=====================================");
        CloseFile(m_LogFile);
    }

    string CreateName()
    {
        string result;
        int year, month, day, hour, minute;
        GetGame().GetYearMonthDay(year, month, day);
        GetGame().GetHourMinuteSecond(hour, minute, null);
        result = string.Format("RadPosRadiations(%1_%2_%3_%4_%5).log",year, month, day, hour, minute);
        return result;
    }

    void CheckDirectory()
    {
        if (!FileExist(m_DefaultPath + m_FolderPath  + "/" + m_FolderSoPath + "/"))
        {
			MakeDirectory(m_DefaultPath + m_FolderPath  + "/" + m_FolderSoPath + "/");
		}
    }

    void WriteLog(string val)
    {
        m_LogFile = OpenFile(m_DefaultPath + m_FolderPath + "\\" + m_FolderSoPath + "\\" + m_Currentname, FileMode.APPEND);
        FPrintln(m_LogFile, val);
        CloseFile(m_LogFile);
    }

    string GetCurrentTime()
    {
        string result;
        int hour, minute, sec;
        GetGame().GetHourMinuteSecond(hour, minute, sec);
        result = string.Format("%1:%2:%3",hour, minute, sec);
        return result;
    }
}
ref RadPosLogger g_RadPosLogger;