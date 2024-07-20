////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 8.90
//https://mikero.bytex.digital/Downloads
//'now' is Thu Jun 15 20:25:39 2023 : 'file' last modified on Sun Dec 12 20:02:16 2021
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class XZoneRadiationsServerPart
	{
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class XZoneRadiationsServerPart
	{
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"XZoneRadiationsServerPart/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"XZoneRadiationsServerPart/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"XZoneRadiationsServerPart/scripts/5_Mission"};
			};
		};
	};
};
