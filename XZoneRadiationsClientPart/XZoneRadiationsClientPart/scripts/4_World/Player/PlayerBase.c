modded class PlayerBase
{


    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
        if (GetGame().IsClient())
        {g_RadiationsManager.OnRPC(sender, rpc_type, ctx);}
    }

}