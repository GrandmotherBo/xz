////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.10
//https://mikero.bytex.digital/Downloads
//'now' is Sat Jul 20 15:12:28 2024 : 'file' last modified on Sat Dec 11 16:31:05 2021
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class XZoneRadiationsClientPart
	{
		requiredAddons[] = {"Radiation"};
	};
};
class CfgMods
{
	class XZoneRadiationsClientPart
	{
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"XZoneRadiationsClientPart/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"XZoneRadiationsClientPart/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"XZoneRadiationsClientPart/scripts/5_Mission"};
			};
		};
	};
};
