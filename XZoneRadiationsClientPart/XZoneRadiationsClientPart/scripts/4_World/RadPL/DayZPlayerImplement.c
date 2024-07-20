modded class DayZPlayerImplement
{


	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (!GetGame().IsServer())
			RadhandleClientRPCs(sender, rpc_type, ctx);
	}
	
	void RadhandleClientRPCs(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		switch(rpc_type)
		{
			case RADRPCc.RPC_SEND_USE_ANTIRAD:
				handleUseAntirad(sender,rpc_type,ctx);
			break;
			case RADRPCc.RPC_SEND_RAD_LOAD:
				handleInrRadLoad(sender,rpc_type,ctx);
			break;
												
		}
	}
	
	
	// 

//==================================CLIENTSIDE=====================================================
	void handleUseAntirad(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		ref Param1<int> rpb = new Param1<int>(-1);
		ctx.Read(rpb);
		PlayerBase player = PlayerBase.Cast(this);
		player.SetInrRad(rpb.param1);
	}
	void handleInrRadLoad(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		ref Param1<int> rpb = new Param1<int>(-1);
		ctx.Read(rpb);
		PlayerBase player = PlayerBase.Cast(this);
		player.SetInrRad(rpb.param1);
	}
    void DamagePlayer()
    {
      
    }
	
}