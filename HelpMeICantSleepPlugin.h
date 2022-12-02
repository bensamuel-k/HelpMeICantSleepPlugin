#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


class HelpMeICantSleepPlugin: public BakkesMod::Plugin::BakkesModPlugin
{
	void onLoad() override;

public:
	void onSetItemCodes(std::vector<std::string> args);

};
