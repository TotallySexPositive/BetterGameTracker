#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/bakkesmodsdk.h"
#include "bakkesmod/wrappers/gamewrapper.h"
#include "bakkesmod/wrappers/GameEvent/ServerWrapper.h"

#include "ResultObject.h"

#include <map>
#include <string>
#include <memory>

class BetterGameTracker : BakkesMod::Plugin::BakkesModPlugin
{
public:
	void onLoad();
	void onUnload();

private:
	ServerWrapper* m_serverWrapper;
	GameWrapper* m_gameWrapper;
	//Game type to Result Object
	std::map<std::string, std::shared_ptr<ResultObject>> m_results;
};