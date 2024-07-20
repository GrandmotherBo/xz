class RadiationsManager
{
    //const float RADIATIONS_XZONE_FILTER_QUANTITY_PER_SEC = 0.3;
    float GF;
    ref Radiations              m_Radiations;
    static ref RadZones m_RadZonesObject;
    ref array<ref RadZones> m_RadZonesArray;


    ref ResistGas_Mask              m_ResistGas_Mask;
    static ref ResistArrayGas_Mask m_ResistArrayGas_MaskObject;
    ref array<ref ResistArrayGas_Mask> m_ResistArrayGas_Mask;


    ref ResistBackpacks              m_ResistBackpacks;
    static ref ResistArrayBackpacks m_ResistArrayBackpacksObject;
    ref array<ref ResistArrayBackpacks> m_ResistArrayBackpacks;

    ref ResistHelm              m_ResistHelm;
    static ref ResistArrayHelm m_ResistArrayHelmObject;
    ref array<ref ResistArrayHelm> m_ResistArrayHelm;

    ref ResistVest              m_ResistVest;
    static ref ResistArrayVest m_ResistArrayVestObject;
    ref array<ref ResistArrayVest> m_ResistArrayVest;

    ref ResistBody              m_ResistBody;
    static ref ResistArrayBody m_ResistArrayBodyObject;
    ref array<ref ResistArrayBody> m_ResistArrayBody;

    ref ResistFeet              m_ResistFeet;
    static ref ResistArrayFeet m_ResistArrayFeetObject;
    ref array<ref ResistArrayFeet> m_ResistArrayFeet;

    ref ResistGloves              m_ResistGloves;
    static ref ResistArrayGloves m_ResistArrayGlovesObject;
    ref array<ref ResistArrayGloves> m_ResistArrayGloves;

    ref ResistLegs              m_ResistLegs;
    static ref ResistArrayLegs m_ResistArrayLegsObject;
    ref array<ref ResistArrayLegs> m_ResistArrayLegs;

    static ref FullResistArray m_ResistArrayFullItemsClassObject;
    ref array<ref FullResistArray> m_ResistArrayFullItemsClass;





    void RadiationsManager()
    {
        m_Radiations = new Radiations();
        m_ResistGas_Mask = new ResistGas_Mask();
        m_ResistBackpacks = new ResistBackpacks();
        m_ResistHelm = new ResistHelm();
        m_ResistVest = new ResistVest();
        m_ResistBody = new ResistBody();
        m_ResistFeet = new ResistFeet();
        m_ResistGloves = new ResistGloves();
        m_ResistLegs = new ResistLegs();
        m_ResistArrayFullItemsClass = new array<ref FullResistArray>;
    }

    void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
            case XZONERADc.SERVER_SEND_MAIN_DATA:
                handleApplyMainData(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_GAS_MASK:
                handleApplyMainDataResist_gas_mask(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_BAKPACK:
                handleApplyMainDataResist_bakpack(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_HELM:
                handleApplyMainDataResist_helm(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_VEST:
                handleApplyMainDataResist_vest(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_BODY:
                handleApplyMainDataResist_body(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_FEET:
                handleApplyMainDataResist_feet(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_GLOVES:
                handleApplyMainDataResist_gloves(ctx);
            break;
            case XZONERADc.SERVER_SEND_MAIN_DATA_RESIST_LEGS:
                handleApplyMainDataResist_legs(ctx);
            break;
        }
    }

    void handleApplyMainDataResist_gas_mask(ParamsReadContext ctx)
    {
        Param2<float,ref ResistGas_Mask> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistGas_Mask = rpb.param2;
        GF = m_ResistGas_Mask.GasMaskConsumeFilter;
        FunctionsAddRadResistArray_gas_mask();

    }

    void handleApplyMainDataResist_bakpack(ParamsReadContext ctx)
    {
        Param1<ref ResistBackpacks> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistBackpacks = rpb.param1;
        FunctionsAddRadResistArray_bakpack();

    }
    void handleApplyMainDataResist_helm(ParamsReadContext ctx)
    {
        Param1<ref ResistHelm> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistHelm = rpb.param1;
        FunctionsAddRadResistArray_helm();

    }
    void handleApplyMainDataResist_vest(ParamsReadContext ctx)
    {
        Param1<ref ResistVest> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistVest = rpb.param1;
        FunctionsAddRadResistArray_vest();

    }
    void handleApplyMainDataResist_body(ParamsReadContext ctx)
    {
        Param1<ref ResistBody> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistBody = rpb.param1;
        FunctionsAddRadResistArray_body();

    }
    void handleApplyMainDataResist_feet(ParamsReadContext ctx)
    {
        Param1<ref ResistFeet> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistFeet = rpb.param1;
        FunctionsAddRadResistArray_feet();

    }
    void handleApplyMainDataResist_gloves(ParamsReadContext ctx)
    {
        Param1<ref ResistGloves> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistGloves = rpb.param1;
        FunctionsAddRadResistArray_gloves();

    }
    void handleApplyMainDataResist_legs(ParamsReadContext ctx)
    {
        Param1<ref ResistLegs> rpb;
        if (!ctx.Read(rpb)) return;
        m_ResistLegs = rpb.param1;
        FunctionsAddRadResistArray_legs();

    }
    void handleApplyMainData(ParamsReadContext ctx)
    {
        Param1<ref Radiations> rpb;
        if (!ctx.Read(rpb)) return;
        m_Radiations = rpb.param1;
        FunctionsAddRadZonesArray();

    }

    void  FunctionsAddRadResistArray_gas_mask()
    {
        m_ResistArrayGas_Mask = new array<ref ResistArrayGas_Mask>;
        TStringArray ResistBodGas_Mask = new TStringArray;
        for (int i = 0; i < m_ResistGas_Mask.ArrayResistGas_Mask.Count(); i++)
        { 
            ResistBodGas_Mask.Insert(m_ResistGas_Mask.ArrayResistGas_Mask.Get(i));
            string ResPos = ResistBodGas_Mask.Get(i);
            int nameCount = m_ResistGas_Mask.ArrayResistGas_Mask.Count();
            TStringArray ResistBodGas_Mask2 = new TStringArray;
            ResPos.Split("|",ResistBodGas_Mask2);
            string Classnames = ResistBodGas_Mask2.Get(0);
            string Power = ResistBodGas_Mask2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistGas_Mask(Classnames, Power.ToInt() );
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }


    void  FunctionsAddRadResistArray_bakpack()
    {
        m_ResistArrayBackpacks = new array<ref ResistArrayBackpacks>;
        TStringArray ResistBodBackpacks = new TStringArray;
        for (int i = 0; i < m_ResistBackpacks.ArrayResistBackpacks.Count(); i++)
        { 
            ResistBodBackpacks.Insert(m_ResistBackpacks.ArrayResistBackpacks.Get(i));
            string ResPos = ResistBodBackpacks.Get(i);
            int nameCount = m_ResistBackpacks.ArrayResistBackpacks.Count();
            TStringArray ResistBodBackpacks2 = new TStringArray;
            ResPos.Split("|",ResistBodBackpacks2);
            string Classnames = ResistBodBackpacks2.Get(0);
            string Power = ResistBodBackpacks2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistBackpacks(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }

    void  FunctionsAddRadResistArray_helm()
    {
        m_ResistArrayHelm = new array<ref ResistArrayHelm>;
        TStringArray ResistBodHelm = new TStringArray;
        for (int i = 0; i < m_ResistHelm.ArrayResistHelm.Count(); i++)
        { 
            ResistBodHelm.Insert(m_ResistHelm.ArrayResistHelm.Get(i));
            string ResPos = ResistBodHelm.Get(i);
            int nameCount = m_ResistHelm.ArrayResistHelm.Count();
            TStringArray ResistBodHelm2 = new TStringArray;
            ResPos.Split("|",ResistBodHelm2);
            string Classnames = ResistBodHelm2.Get(0);
            string Power = ResistBodHelm2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistHelm(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }

    void  FunctionsAddRadResistArray_vest()
    {
        m_ResistArrayVest = new array<ref ResistArrayVest>;
        TStringArray ResistBodVest = new TStringArray;
        for (int i = 0; i < m_ResistVest.ArrayResistVest.Count(); i++)
        { 
            ResistBodVest.Insert(m_ResistVest.ArrayResistVest.Get(i));
            string ResPos = ResistBodVest.Get(i);
            int nameCount = m_ResistVest.ArrayResistVest.Count();
            TStringArray ResistBodVest2 = new TStringArray;
            ResPos.Split("|",ResistBodVest2);
            string Classnames = ResistBodVest2.Get(0);
            string Power = ResistBodVest2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistVest(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }

    void  FunctionsAddRadResistArray_body()
    {
        m_ResistArrayBody = new array<ref ResistArrayBody>;
        TStringArray ResistBod = new TStringArray;
        for (int i = 0; i < m_ResistBody.ArrayResistBody.Count(); i++)
        { 
            ResistBod.Insert(m_ResistBody.ArrayResistBody.Get(i));
            string ResPos = ResistBod.Get(i);
            int nameCount = m_ResistBody.ArrayResistBody.Count();
            TStringArray ResistBod2 = new TStringArray;
            ResPos.Split("|",ResistBod2);
            string Classnames = ResistBod2.Get(0);
            string Power = ResistBod2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistBody(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }

    void  FunctionsAddRadResistArray_feet()
    {
        m_ResistArrayFeet = new array<ref ResistArrayFeet>;
        TStringArray ResistBodFeet = new TStringArray;
        for (int i = 0; i < m_ResistFeet.ArrayResistFeet.Count(); i++)
        { 
            ResistBodFeet.Insert(m_ResistFeet.ArrayResistFeet.Get(i));
            string ResPos = ResistBodFeet.Get(i);
            int nameCount = m_ResistFeet.ArrayResistFeet.Count();
            TStringArray ResistBodFeet2 = new TStringArray;
            ResPos.Split("|",ResistBodFeet2);
            string Classnames = ResistBodFeet2.Get(0);
            string Power = ResistBodFeet2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistFeet(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }

    void  FunctionsAddRadResistArray_gloves()
    {
        m_ResistArrayGloves = new array<ref ResistArrayGloves>;
        TStringArray ResistBodGloves = new TStringArray;
        for (int i = 0; i < m_ResistGloves.ArrayResistGloves.Count(); i++)
        { 
            ResistBodGloves.Insert(m_ResistGloves.ArrayResistGloves.Get(i));
            string ResPos = ResistBodGloves.Get(i);
            int nameCount = m_ResistGloves.ArrayResistGloves.Count();
            TStringArray ResistBodGloves2 = new TStringArray;
            ResPos.Split("|",ResistBodGloves2);
            string Classnames = ResistBodGloves2.Get(0);
            string Power = ResistBodGloves2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistGloves(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }

    void  FunctionsAddRadResistArray_legs()
    {
        m_ResistArrayLegs = new array<ref ResistArrayLegs>;
        TStringArray ResistBodLegs = new TStringArray;
        for (int i = 0; i < m_ResistLegs.ArrayResistLegs.Count(); i++)
        { 
            ResistBodLegs.Insert(m_ResistLegs.ArrayResistLegs.Get(i));
            string ResPos = ResistBodLegs.Get(i);
            int nameCount = m_ResistLegs.ArrayResistLegs.Count();
            TStringArray ResistBodLegs2 = new TStringArray;
            ResPos.Split("|",ResistBodLegs2);
            string Classnames = ResistBodLegs2.Get(0);
            string Power = ResistBodLegs2.Get(1);
            //Print("Classnames | "+Classnames);
            //Print("Power | "+Power);
            AddRadResistLegs(Classnames, Power.ToInt());
            AddRadResistFullArray(Classnames, Power.ToInt());   
        }
    }


    void AddRadResistFullArray(string m_classnames,int m_ResistFullItemsClass)
    {
        m_ResistArrayFullItemsClassObject = new ref FullResistArray();
        m_ResistArrayFullItemsClassObject.ClassnamesClothItems = m_classnames;
        m_ResistArrayFullItemsClassObject.XZoneResistClothItems = m_ResistFullItemsClass;
        m_ResistArrayFullItemsClass.Insert(m_ResistArrayFullItemsClassObject);
        //Print("AddRadResistGas_Mask1 |"+m_ResistArrayGas_MaskObject.ClassnamesGas_Mask);
        //Print("AddRadResistGas_Mask2 | "+m_ResistArrayGas_MaskObject.XZoneResistGas_Mask);
    }

    void AddRadResistGas_Mask(string m_classnames,int m_ResistGas_Mask)
    {
        m_ResistArrayGas_MaskObject = new ref ResistArrayGas_Mask();
        m_ResistArrayGas_MaskObject.ClassnamesGas_Mask = m_classnames;
        m_ResistArrayGas_MaskObject.XZoneResistGas_Mask = m_ResistGas_Mask;
        //m_ResistArrayGas_MaskObject.GasMaskFilter = GasFilter;
        m_ResistArrayGas_Mask.Insert(m_ResistArrayGas_MaskObject);
        //Print("AddRadResistGas_Mask1 |"+m_ResistArrayGas_MaskObject.ClassnamesGas_Mask);
        //Print("AddRadResistGas_Mask2 | "+m_ResistArrayGas_MaskObject.XZoneResistGas_Mask);
    }

    void AddRadResistBackpacks(string m_classnames,int m_ResistBackpacks)
    {
        m_ResistArrayBackpacksObject = new ref ResistArrayBackpacks();
        m_ResistArrayBackpacksObject.ClassnamesBackpacks = m_classnames;
        m_ResistArrayBackpacksObject.XZoneResistBackpacks = m_ResistBackpacks;
        m_ResistArrayBackpacks.Insert(m_ResistArrayBackpacksObject);
        //Print("AddRadResistBackpacks1 |"+m_ResistArrayBackpacksObject.ClassnamesBackpacks);
        //Print("AddRadResistBackpacks2 | "+m_ResistArrayBackpacksObject.XZoneResistBackpacks);
    }

    void AddRadResistHelm(string m_classnames,int m_ResistHelm)
    {
        m_ResistArrayHelmObject = new ref ResistArrayHelm();
        m_ResistArrayHelmObject.ClassnamesHelm = m_classnames;
        m_ResistArrayHelmObject.XZoneResistHelm = m_ResistHelm;
        m_ResistArrayHelm.Insert(m_ResistArrayHelmObject);
        //Print("AddRadResistHelm1 |"+m_ResistArrayHelmObject.ClassnamesHelm);
        //Print("AddRadResistHelm2 | "+m_ResistArrayHelmObject.XZoneResistHelm);
    }

    void AddRadResistVest(string m_classnames,int m_ResistVest)
    {
        m_ResistArrayVestObject = new ref ResistArrayVest();
        m_ResistArrayVestObject.ClassnamesVest = m_classnames;
        m_ResistArrayVestObject.XZoneResistVest = m_ResistVest;
        m_ResistArrayVest.Insert(m_ResistArrayVestObject);
        //Print("AddRadResistVest1 |"+m_ResistArrayVestObject.ClassnamesVest);
        //Print("AddRadResistVest2 | "+m_ResistArrayVestObject.XZoneResistVest);
    }

    void AddRadResistBody(string m_classnames,int m_ResistBody)
    {
        m_ResistArrayBodyObject = new ref ResistArrayBody();
        m_ResistArrayBodyObject.ClassnamesBody = m_classnames;
        m_ResistArrayBodyObject.XZoneResistBody = m_ResistBody;
        m_ResistArrayBody.Insert(m_ResistArrayBodyObject);
        //Print("AddRadResistBody1 |"+m_ResistArrayBodyObject.ClassnamesBody);
        //Print("AddRadResistBody2 | "+m_ResistArrayBodyObject.XZoneResistBody);
    }

    void AddRadResistFeet(string m_classnames,int m_ResistFeet)
    {
        m_ResistArrayFeetObject = new ref ResistArrayFeet();
        m_ResistArrayFeetObject.ClassnamesFeet = m_classnames;
        m_ResistArrayFeetObject.XZoneResistFeet = m_ResistFeet;
        m_ResistArrayFeet.Insert(m_ResistArrayFeetObject);
        //Print("AddRadResistFeet1 |"+m_ResistArrayFeetObject.ClassnamesFeet);
        //Print("AddRadResistFeet2 | "+m_ResistArrayFeetObject.XZoneResistFeet);
    }

    void AddRadResistGloves(string m_classnames,int m_ResistGloves)
    {
        m_ResistArrayGlovesObject = new ref ResistArrayGloves();
        m_ResistArrayGlovesObject.ClassnamesGloves = m_classnames;
        m_ResistArrayGlovesObject.XZoneResistGloves = m_ResistGloves;
        m_ResistArrayGloves.Insert(m_ResistArrayGlovesObject);
        //Print("AddRadResistGloves1 |"+m_ResistArrayGlovesObject.ClassnamesGloves);
        //Print("AddRadResistGloves2 | "+m_ResistArrayGlovesObject.XZoneResistGloves);
    }

    void AddRadResistLegs(string m_classnames,int m_ResistLegs)
    {
        m_ResistArrayLegsObject = new ref ResistArrayLegs();
        m_ResistArrayLegsObject.ClassnamesLegs = m_classnames;
        m_ResistArrayLegsObject.XZoneResistLegs = m_ResistLegs;
        m_ResistArrayLegs.Insert(m_ResistArrayLegsObject);
        //Print("AddRadResistLegs1 |"+m_ResistArrayLegsObject.ClassnamesLegs);
        //Print("AddRadResistLegs2 | "+m_ResistArrayLegsObject.XZoneResistLegs);
    }
    void  FunctionsAddRadZonesArray()
    {
        m_RadZonesArray = new array<ref RadZones>;
        TStringArray loc = new TStringArray;
        for (int i = 0; i < m_Radiations.Positions.Count(); i++)
        { 
            loc.Insert(m_Radiations.Positions.Get(i));
            string pos = loc.Get(i);
            int nameCount = m_Radiations.Positions.Count();
            TStringArray loc2 = new TStringArray;
            pos.Split("|",loc2);
            string Positions = loc2.Get(0);
            string Radius = loc2.Get(1);
            string Power = loc2.Get(2);
            string Locations = loc2.Get(3);
            AddRadZone(Positions.ToVector(),Radius.ToInt(),Power.ToInt());  
        }
    }
    void AddRadZone(vector m_pos,int radius,int radAmount)
    {
        m_RadZonesObject = new ref RadZones();
        m_RadZonesObject.rad_pos = m_pos;
        m_RadZonesObject.radius = radius;
        m_RadZonesObject.radAmount  = radAmount;
        m_RadZonesArray.Insert(m_RadZonesObject);
    }
    void TickSchedulerRad(float timeslice)
    {
        PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );

        if (!player)
            return;
        int currentTime = GetGame().GetTime() * 0.001;
        static int nTime = 0;
        if (currentTime >= nTime+1)
        {
            GetGame().RPCSingleParam(player, RADRPCc.RPC_PLAYER_HAS_RAD, new Param1<bool>(true), true);
            CheckTriggerRadiations();
            nTime = currentTime;
        }
    }
    void CheckTriggerRadiations()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            vector positionPlayer = player.GetPosition();
            int radZoneCount = m_RadZonesArray.Count();
            bool flag = true;

            for (int j=0;j<radZoneCount;j++)
            {
                positionPlayer[1] = 0;
                m_RadZonesArray[j].rad_pos[1] = 0;
                float p_distCentre = vector.Distance(positionPlayer,m_RadZonesArray[j].rad_pos);
                if (p_distCentre <= m_RadZonesArray[j].radius)
                {

                    int rad = m_RadZonesArray[j].radAmount;
                    float onePercent = 100 / m_RadZonesArray[j].radius;
                    int tempDist = m_RadZonesArray[j].radius - p_distCentre;
                    float resultPercent = onePercent * tempDist;
                    int resultRad = rad * (resultPercent * 0.01);
                    player.SetOtrRad(resultRad);
                    GetResistPlayer(resultRad);
                    flag = false;
                    
                }
                if (flag) 
                {
                    player.SetOtrRad(0);
                }
            }
        }
    }
    void GetResistPlayer(int ChcRad)
    {
        PlayerBase playerRadBase = PlayerBase.Cast(GetGame().GetPlayer());
        MaskBase mask = MaskBase.Cast(playerRadBase.GetInventory().FindAttachment(InventorySlots.MASK));
        ItemBase Gas_MaskResist = playerRadBase.GetGasMask();
        ItemBase BackpacksResist = playerRadBase.GetBackpacks();
        ItemBase HelmResist = playerRadBase.GetHelm();
        ItemBase VestResist = playerRadBase.GetVest();
        ItemBase BodyResist = playerRadBase.GetBody();
        ItemBase FeetResist = playerRadBase.GetFeet();
        ItemBase GlovesResist = playerRadBase.GetGloves();
        ItemBase LegsResist = playerRadBase.GetLegs();
        int Sorce = ChcRad;
        int ResistBodyArraysGo;

        if (Gas_MaskResist)
        {
            float consume_quantity = GF;
            Print("TRUE GAS_MASKRESIST consume_quantity | "+consume_quantity);
            string Gas_MaskNameResist = mask.GetType();
            int radResistCountGas_Mask = m_ResistArrayGas_Mask.Count();
            int ResistGas_MaskArraysGoGas_Mask;
            for (int a=0;a<radResistCountGas_Mask;a++)
            {
                if (m_ResistArrayGas_Mask[a].ClassnamesGas_Mask == Gas_MaskNameResist)
                {
                    if (mask.HasValidFilter())
                    {
                        GetGame().RPCSingleParam(playerRadBase, RADRPCc.RPC_SET_CONSUME_FILTER_RAD, new Param1<float>(consume_quantity), true);
                        //Print("TRUE GAS_MASKRESIST");
                        //Print("consuming_filter"+consume_quantity);
                        ResistGas_MaskArraysGoGas_Mask = m_ResistArrayGas_Mask[a].XZoneResistGas_Mask;
                        Sorce = Sorce - ResistGas_MaskArraysGoGas_Mask;
                    }
                        
                }
            }
        }

        if (BackpacksResist)
        {
            string BackpacksNameResist = BackpacksResist.GetType();
            int radResistCountBackpacks = m_ResistArrayBackpacks.Count();
            int ResistBackpacksArraysGoBackpacks;
            for (int o=0;o<radResistCountBackpacks;o++)
            {
                if (m_ResistArrayBackpacks[o].ClassnamesBackpacks == BackpacksNameResist)
                {
                    //Print("TRUE BackpacksResist ");
                    //Print("TRUE BackpacksResist2 | "+m_ResistArrayBackpacks[o].XZoneResistBackpacks);
                    ResistBackpacksArraysGoBackpacks = m_ResistArrayBackpacks[o].XZoneResistBackpacks;

                    Sorce = Sorce - ResistBackpacksArraysGoBackpacks;
                }
            }
        }
        if (HelmResist)
        {
            string HelmNameResist = HelmResist.GetType();
            int radResistCountHelm = m_ResistArrayHelm.Count();
            int ResistHelmArraysGoHelm;
            for (int d=0;d<radResistCountHelm;d++)
            {
                if (m_ResistArrayHelm[d].ClassnamesHelm == HelmNameResist)
                {
                    //Print("TRUE HelmResist ");
                    //Print("TRUE HelmResist2 | "+m_ResistArrayHelm[d].XZoneResistHelm);
                    ResistHelmArraysGoHelm = m_ResistArrayHelm[d].XZoneResistHelm;

                    Sorce = Sorce - ResistHelmArraysGoHelm;
                }
            }    
        }
        if (VestResist)
        {
            string VestNameResist = VestResist.GetType();
            int radResistCountVest = m_ResistArrayVest.Count();
            int ResistVestArraysGoVest;
            for (int c=0;c<radResistCountVest;c++)
            {
                if (m_ResistArrayVest[c].ClassnamesVest == VestNameResist)
                {
                    //Print("TRUE VestResist ");
                    //Print("TRUE VestResist2 | "+m_ResistArrayVest[c].XZoneResistVest);
                    ResistVestArraysGoVest = m_ResistArrayVest[c].XZoneResistVest;

                    Sorce = Sorce - ResistVestArraysGoVest;
                }
            }    
        }
        if (BodyResist)
        {
            string BodyNameResist = BodyResist.GetType();
            int radResistCountBody = m_ResistArrayBody.Count();
            int ResistBodyArraysGoBody;
            for (int e=0;e<radResistCountBody;e++)
            {
                if (m_ResistArrayBody[e].ClassnamesBody == BodyNameResist)
                {
                    //Print("TRUE BodyResist ");
                    //Print("TRUE BodyResist2 | "+m_ResistArrayBody[e].XZoneResistBody);
                    ResistBodyArraysGoBody = m_ResistArrayBody[e].XZoneResistBody;

                    Sorce = Sorce - ResistBodyArraysGoBody;
                }
            }    
        }
        if (FeetResist)
        {
            string FeetNameResist = FeetResist.GetType();
            int radResistCountFeet = m_ResistArrayFeet.Count();
            int ResistFeetArraysGoFeet;
            for (int f=0;f<radResistCountFeet;f++)
            {
                if (m_ResistArrayFeet[f].ClassnamesFeet == FeetNameResist)
                {
                    //Print("TRUE FeetResist ");
                    //Print("TRUE FeetResist2 | "+m_ResistArrayFeet[f].XZoneResistFeet);
                    ResistFeetArraysGoFeet = m_ResistArrayFeet[f].XZoneResistFeet;

                    Sorce = Sorce - ResistFeetArraysGoFeet;
                }
            }    
        }
        if (GlovesResist)
        {
            string GlovesNameResist = GlovesResist.GetType();
            int radResistCountGloves = m_ResistArrayGloves.Count();
            int ResistGlovesArraysGoGloves;
            for (int g=0;g<radResistCountGloves;g++)
            {
                if (m_ResistArrayGloves[g].ClassnamesGloves == GlovesNameResist)
                {
                    //Print("TRUE GlovesResist ");
                    //Print("TRUE GlovesResist2 | "+m_ResistArrayGloves[g].XZoneResistGloves);
                    ResistGlovesArraysGoGloves = m_ResistArrayGloves[g].XZoneResistGloves;

                    Sorce = Sorce - ResistGlovesArraysGoGloves;
                }
            }    
        }
        if (LegsResist)
        {
            string LegsNameResist = LegsResist.GetType();
            int radResistCountLegs = m_ResistArrayLegs.Count();
            int ResistLegsArraysGoLegs;
            for (int z=0;z<radResistCountLegs;z++)
            {
                if (m_ResistArrayLegs[z].ClassnamesLegs == LegsNameResist)
                {
                    //Print("TRUE LegsResist ");
                    //Print("TRUE LegsResist2 | "+m_ResistArrayLegs[z].XZoneResistLegs);
                    ResistLegsArraysGoLegs = m_ResistArrayLegs[z].XZoneResistLegs;

                    Sorce = Sorce - ResistLegsArraysGoLegs;
                }
            }    
        }
        if (Sorce <= 0)
        {
            //Print("GetResistPlayer Sorce <= 0 |||| "+ Sorce);
            playerRadBase.SetInrRad(0);
            GetGame().RPCSingleParam(playerRadBase, RADRPCc.RPC_SET_INNER_RAD, new Param1<int>(0), true);
        }
        else
        {
            //Print("GetResistPlayer else Sorce > 0 |||| "+ Sorce);
            playerRadBase.SetInrRad(Sorce);
            GetGame().RPCSingleParam(playerRadBase, RADRPCc.RPC_SET_INNER_RAD, new Param1<int>(Sorce), true);
        }
        
        
    }
}
ref RadiationsManager g_RadiationsManager;