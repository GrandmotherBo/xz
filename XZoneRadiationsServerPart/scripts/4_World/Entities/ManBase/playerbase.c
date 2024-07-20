modded class PlayerBase
{
    
    void SetRadIB(float ra){
		this.innerRad += ra;
		if(this.innerRad < 0)
		{
			this.innerRad = 0;
		}
	}
    override void SetInrRad(int r)
	{
        if(r == -450000)
        {
            this.innerRad=0;
        }
        if(r<0)
        {
            this.innerRad = this.innerRad + r;
            if(this.innerRad <= 0)
            {
                this.innerRad = 0;
                return;
            }
            else
            {
                if (GetGame().IsServer())
                {

                }
            }
        }
        if(r>0)
        {
            this.innerRad = this.innerRad + r;
            if (GetGame().IsServer())
            {

            }
        }
    }
    override void UseAntirads(PlayerBase PlAntirad, string ClassNam) 
    {
        int DefAntirad;
        for (int a = 0; a < g_AntiradEffectManager.m_AntiradEffect.AntiradEffectSettings.Count(); a++)
            {
    
                if (ClassNam == g_AntiradEffectManager.m_AntiradEffect.AntiradEffectSettings[a].ClassnamesAntirad )
                {
                    DefAntirad = g_AntiradEffectManager.m_AntiradEffect.AntiradEffectSettings[a].SetRad;
                    SetInrRad(DefAntirad);
                    GetGame().RPCSingleParam(PlAntirad, RADRPCc.RPC_SEND_USE_ANTIRAD, new Param1<int>(DefAntirad), true, PlAntirad.GetIdentity());
                }
            }
        
    }
}