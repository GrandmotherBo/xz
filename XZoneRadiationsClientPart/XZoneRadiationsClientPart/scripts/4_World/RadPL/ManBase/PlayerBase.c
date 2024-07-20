modded class PlayerBase
{
    private int                         innerRad;
    private int                         OuterRad;
    private int                         radUses;
    string                              UID;
    string                              UIDname;
    string                              inrRadDB;
    PlayerBase                          player;

    const  string          String_Folder_DataBase_RadiationsXzone                =   "$profile:XZoneRadiations//DataBasePlayersInRad//";
    


    void PlayerBase()
    {
        innerRad                = 0;
        OuterRad                = 0;
        radUses                 = 0;
    }

    override void OnConnect()
    {
        super.OnConnect();
        UID = GetIdentity().GetPlainId();
        UIDname = GetIdentity().GetName();
        string radUsesData;
        SetNewPlayerData();
        int inrRadInt = inrRadDB.ToInt();
        RadUsesOnConnect(radUsesData.ToInt());
        string  v_NewPlayerFileConnect =   string.Format( "%1%2.txt", String_Folder_DataBase_RadiationsXzone, UID );
        //ReadRadDB(v_NewPlayerFileConnect);
        
        GetGame().RPCSingleParam(this, RADRPCc.RPC_SEND_RAD_LOAD, new Param1<int>(inrRadInt), true, this.GetIdentity());
    }

    override void OnDisconnect()
    {
        string radData = GetInrRad().ToString();
        string  v_NewPlayerFileForma =   string.Format( "%1%2.txt", String_Folder_DataBase_RadiationsXzone, UID );
        SaveValue(v_NewPlayerFileForma,radData);
        super.OnDisconnect();
    }
    

    void SetNewPlayerData()
    {
        UID = GetIdentity().GetPlainId();
        
        string FullNamesFile = UID + UIDname;
        string contactSteamIdFile   = "0";
        string  v_NewPlayerFile =   string.Format( "%1%2.txt", String_Folder_DataBase_RadiationsXzone, UID );     
        
        if ( !FileExist( v_NewPlayerFile ) )
        {
            SaveValue( v_NewPlayerFile, contactSteamIdFile );
        }
        else(FileExist(v_NewPlayerFile ) )
        {
            RadLoads();
        }


    }
    static void SaveValue( string v_FileName, string v_Value )
    {
        FileHandle  v_FileHandle;
        Print("SaveValue"+v_FileName+" | "+v_Value);
        v_FileHandle    =   OpenFile( v_FileName, FileMode.WRITE );
        if ( v_FileHandle == 0 )
        {
            return;         
        }
        FPrintln( v_FileHandle, v_Value );
        CloseFile( v_FileHandle );
    }
    void RadLoads()
    {
        string  v_NewPlayerFileRadLoads =   string.Format( "%1%2.txt", String_Folder_DataBase_RadiationsXzone, UID ); 
        FileHandle file_handle = OpenFile(v_NewPlayerFileRadLoads, FileMode.READ);
        string line_content;
        while ( FGets( file_handle, line_content ) > 0 )
        {
         Print(line_content); 
        }
        CloseFile(file_handle);
        int inrRadIntRadLoads = line_content.ToInt();
        GetGame().RPCSingleParam(this, RADRPCc.RPC_SEND_RAD_LOAD, new Param1<int>(inrRadIntRadLoads), true, this.GetIdentity());
         SetInrRad(inrRadIntRadLoads);
    }



    
    void RadUsesOnConnect(int r)
    {
        int count = r;
        while (count != 0)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RemoveRadCouldown, r*300*1000, false);
            count--;
        }
    }

    override void EEKilled( Object killer )
    {
        super.EEKilled(killer);
        string KilledSaveRad = "0";
        string  v_NewPlayerFileFormaDie =   string.Format( "%1%2.txt", String_Folder_DataBase_RadiationsXzone, UID );
        SaveValue(v_NewPlayerFileFormaDie,KilledSaveRad);
    }
    void SetInrRad(int r) // type heal rad or outer rad 0-heal;1-outer
    {
        if(r<0)
        {
            this.innerRad = this.innerRad + r;
            if(this.innerRad<0)
                this.innerRad = 0;
        }
        if(r>0)
        {
            this.innerRad = this.innerRad + r;
        }
    }
    int GetInrRad()
    {
        return this.innerRad;
    }
    ItemBase GetGasMask()
    {
        return GetItemOnSlot("MASK");
    }
    ItemBase GetBackpacks()
    {
        return GetItemOnSlot("BACK");
    }
    ItemBase GetHelm()
    {
        return GetItemOnSlot("HEADGEAR");
    }
    ItemBase GetVest()
    {
        return GetItemOnSlot("VEST");
    }
    ItemBase GetBody()
    {
        return GetItemOnSlot("BODY");
    }
    ItemBase GetFeet()
    {
        return GetItemOnSlot("FEET");
    }
    ItemBase GetGloves()
    {
        return GetItemOnSlot("GLOVES");
    }
    ItemBase GetLegs()
    {
        return GetItemOnSlot("LEGS");
    }
    void SetOtrRad(int or)
    {
        this.OuterRad = or;
    }
    int GetOtrRad()
    {
        return this.OuterRad;
    }
    void UseRad()
    {
        radUses++;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RemoveRadCouldown, 300*1000, false);
    }
    int GetRadUses()
    {
        return radUses;
    }
    void RemoveRadCouldown()
    {
        radUses--;
    }
    void UseAntirads(PlayerBase PlAntirad, string ClassNam) 
    {

    }

}
