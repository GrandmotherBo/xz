modded class DayZPlayerImplement
{
	int inrFonts;
	int Dmg = 0;
	int Cgh = 0;
	int Vom = 0;
	int Bleed = 0;

	bool DamageServer;
    int EffectDamageOnceInTimeServer;
    float HowDamageServer;

    bool CoughServer;
    int EffectCoughOnceInTimeServer;

    bool VomitServer;
    int EffectVomitOnceInTimeServer;

    bool BleedingServer;
    int EffectBleedingOnceInTimeServer;
    int HowManyBleedingServer;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsServer())
		{
			RadhandleServerRPCs(sender, rpc_type, ctx);
		}
	}

	
	void RadhandleServerRPCs(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		PlayerBase player = PlayerBase.Cast(this);

		if (rpc_type==RADRPCc.RPC_SET_INNER_RAD)
		{
				
				Param1<int> amount = new Param1<int>(-1);
				ctx.Read(amount);		
				int p = amount.param1;
				player.SetInrRad(p);
		}
		if (rpc_type == RADRPCc.RPC_SET_CONSUME_FILTER_RAD)
		{
			Param1<float> ConsumeQ = new Param1<float>(-1);
			ctx.Read(ConsumeQ);
			float consumers = ConsumeQ.param1;
			MaskBase mask = MaskBase.Cast(player.GetInventory().FindAttachment(InventorySlots.MASK));
			if (mask != null && mask.HasValidFilter())
			{
				bool consuming_filter = mask.ConsumeQuantity(consumers, player);
				//Print("consuming_filter" + consumers);
			}
		}
		if (rpc_type==RADRPCc.RPC_PLAYER_HAS_RAD)
		{
			
			inrFonts = player.GetInrRad();
			
			
			for (int a = 0; a < g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect.Count(); a++)
        	{	
        		if (inrFonts >= g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].InRadMin && inrFonts <= g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].InRadMax )
        		 {
        		 	DamageServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].Damage;
    				EffectDamageOnceInTimeServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].EffectDamageOnceInTime ;
    				HowDamageServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].HowDamage;

    				CoughServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].Cough;
    				EffectCoughOnceInTimeServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].EffectCoughOnceInTime ;

    				VomitServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].Vomit;
    				EffectVomitOnceInTimeServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].EffectVomitOnceInTime ;

    				BleedingServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].Bleeding;
    				EffectBleedingOnceInTimeServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].EffectBleedingOnceInTime ;
    				HowManyBleedingServer = g_EffectAndDamageManager.m_DmgAnEffect.RadDamageAndEffect[a].HowManyBleeding;

        		 	if (DamageServer == true)
        		 	{
        		 		if (!HowDamageServer <=0  && !EffectDamageOnceInTimeServer <=0)
        		 		{
        		 			if(Dmg % EffectDamageOnceInTimeServer==0)
							{	
							DamagePlayerRad(HowDamageServer);
							}
							Dmg++;
        		 		}
        		 		
        		 	}
        		 	if (CoughServer == true)
        		 	{
        		 		if (!EffectCoughOnceInTimeServer <=0)
        		 		{
	        		 		if(Cgh % EffectCoughOnceInTimeServer==0)
							{	
								SymptomBase symptom_cgh = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
								if (symptom_cgh)
								{
									symptom_cgh.SetDuration(2);
								}
							}
							Cgh++;
						}
        		 	}
        		 	if (VomitServer == true)
        		 	{
        		 		if (EffectVomitOnceInTimeServer <=0)
        		 		{

	        		 		if(Vom % EffectVomitOnceInTimeServer==0)
							{	
								SymptomBase symptom_vom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
								if (symptom_vom)
								{
									symptom_vom.SetDuration(2);
								}
								
							}
							Vom++;
						}
        		 	}
        		 	if (BleedingServer == true)
        		 	{
        		 		if (!HowManyBleedingServer <=0  && !EffectBleedingOnceInTimeServer <=0)
        		 		{

	        		 		if(Bleed % EffectBleedingOnceInTimeServer==0)
							{	
								if (HowManyBleedingServer == 1)
								{
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine");
								}
								if (HowManyBleedingServer == 2)
								{
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine");
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine1");
								}
								if (HowManyBleedingServer == 3)
								{
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine");
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine1");
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine2");
								}
								if (HowManyBleedingServer == 4)
								{
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine");
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine1");
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine2");
									player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine3");
								}
								
							}
							Bleed++;
						}
        		 	}			
        		 }
        	}
		}
    }


    
    void DamagePlayerRad(float dmg)
    {
        PlayerBase player = PlayerBase.Cast(this);
        float playerHealth = player.GetHealth("GlobalHealth", "Health");
        float totalDmg = dmg;
        player.SetHealth("GlobalHealth", "Health", playerHealth - totalDmg);
    }
}