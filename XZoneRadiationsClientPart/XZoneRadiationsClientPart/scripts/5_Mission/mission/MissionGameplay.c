modded class MissionGameplay
{
	ref Radiations              m_Radiations;

    override void OnInit()
    {
        super.OnInit();
        g_RadiationsManager                 =   new RadiationsManager();

    }
    override void TickScheduler(float timeslice)
    {
        super.TickScheduler(timeslice);
        g_RadiationsManager.TickSchedulerRad(timeslice);
    }

}