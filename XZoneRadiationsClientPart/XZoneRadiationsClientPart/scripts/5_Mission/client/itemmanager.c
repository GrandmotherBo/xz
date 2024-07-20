modded class ItemManager
{
	void ItemManager( Widget root )
	{
		m_Instance					= this;
		m_RootWidget				= root;
		m_DefautOpenStates			= new map<string, bool>;
		m_DefautHeaderOpenStates	= new map<string, bool>;
		m_SlotInfoShown				= false;
		
		#ifdef PLATFORM_CONSOLE
			m_TooltipWidget			= GetGame().GetWorkspace().CreateWidgets("gui/layouts/inventory_new/day_z_inventory_new_tooltip_xbox.layout", root );
			m_TooltipSlotWidget		= GetGame().GetWorkspace().CreateWidgets("gui/layouts/inventory_new/day_z_inventory_new_tooltip_slot_xbox.layout", root );
		#else
			m_TooltipWidget			= GetGame().GetWorkspace().CreateWidgets("XZoneRadiationsClientPart/data/tooltip_menu.layout", root );
			m_TooltipSlotWidget		= GetGame().GetWorkspace().CreateWidgets("gui/layouts/inventory_new/day_z_inventory_new_tooltip_slot.layout", root );
		#endif
		m_TooltipWidget.Show( false );
		m_TooltipSlotWidget.Show( false );
	}

	void ~ItemManager()
    {
    }



	override void ShowTooltip()
	{	
		Widget m_BottomPanelRage   = Widget.Cast( m_TooltipWidget.FindAnyWidget("BottomPanelRage") );
		if(m_HoveredItem.IsInherited(Clothing_Base))
		{
			
			string BackpacksNameResist = m_HoveredItem.GetType();
            int radResistCountFullResistArray = g_RadiationsManager.m_ResistArrayFullItemsClass.Count();
            int ResistsArraysGoFull;
            for (int o=0;o<radResistCountFullResistArray;o++)
            {
                if (g_RadiationsManager.m_ResistArrayFullItemsClass[o].ClassnamesClothItems == BackpacksNameResist)
                {
                	string NamesItemsClass = m_HoveredItem.GetType();
                	NamesItemsClass = BackpacksNameResist;
                    ResistsArraysGoFull = g_RadiationsManager.m_ResistArrayFullItemsClass[o].XZoneResistClothItems;
                }
            }

            m_BottomPanelRage.Show(true);
			TextWidget m_TextRage = TextWidget.Cast( m_TooltipWidget.FindAnyWidget("RageText") );
			m_TextRage.SetText("#ResistRadiations "+ResistsArraysGoFull.ToString());	
		}
		else
		{
			m_BottomPanelRage.Show(false);
		}
		Widget m_GridWidget = Widget.Cast( m_TooltipWidget.FindAnyWidget("GridSpacerWidget1") );
		m_GridWidget.Update();
		super.ShowTooltip();
	}
}