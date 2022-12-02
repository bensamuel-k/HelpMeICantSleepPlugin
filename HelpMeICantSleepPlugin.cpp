#include "pch.h"
#include "HelpMeICantSleepPlugin.h"


BAKKESMOD_PLUGIN(HelpMeICantSleepPlugin, "write a plugin description here", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void HelpMeICantSleepPlugin::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->registerNotifier("set_item_codes", [this](std::vector<std::string> args) { onSetItemCodes(args); },
		"Applies hard-coded loadout", PERMISSION_MENU);
}

void HelpMeICantSleepPlugin::onSetItemCodes(std::vector<std::string> args)
{
	cvarManager->executeCommand("cl_itemmod_enabled 1");

	std::string itemCodes[5] = { 
		"xALKBVwABILtBwA=", // Item Code 1: changes decal to: Octane BDS Home 2
		"xAJzBVwABEKVBgA=", // Item Code 2: changes decal to: Octane Endpoint Home
		"xAKEBVwABIKiBgA=", // Item Code 3: changes decal to: Octane G2 Home
		"xAJeBVwABAL5BwA=", // Item Code 4: changes decal to: Octane Furia Home 2
		"xAJFBVwABMItCAA="  // Item Code 5: changes decal to: Octane Karmine Corp Home 2
	};
	// Expected behaviour: 
	//   Kinda like a slideshow of decals; 
	//   Apply Item Code 1 -> sleep for 2 seconds -> Apply Item Code 2 -> sleep for 2 seconds -> ... -> Apply Item Code 5 -> sleep for 2 seconds
	// Actual behaviour:
	//   Sleep for 5*2=10 seconds -> Apply all 5 Item Codes very quickly
	for (auto code : itemCodes) {
		cvarManager->executeCommand("cl_itemmod_code \"" + code + "\"");
		LOG(code);
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
