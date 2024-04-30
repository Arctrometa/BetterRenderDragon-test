#pragma once
#include <string>
#include <atomic>

class Options {
public:
	static bool showImGui;

	static bool performanceEnabled;

	static bool windowSettingsEnabled;

	static bool vanilla2DeferredAvailable;
	static bool vanilla2DeferredEnabled;
	static bool deferredRenderingEnabled;
	static bool newVideoSettingsAvailable;
	static bool forceEnableDeferredTechnicalPreview;
	static bool disableRendererContextD3D12RTX;

	static bool materialBinLoaderEnabled;
	static bool redirectShaders;
	static bool reloadShadersAvailable;
	static std::atomic_bool reloadShaders;

	static bool customUniformsEnabled;

	static int uiKey;
	static int reloadShadersKey;

	static void initVsync(){
        	auto vsyncsetting = Client::settings.getSettingByName<bool>("vsync");
        	auto vsyncOption = Options::getOption("vsync");

        	if(vsyncOption == nullptr) return;

        	if (vsyncsetting->value && vsyncOption->getvalue())
          	  vsyncOption->setvalue(true);
        	else if (!vsyncsetting->value && !vsyncOption->getvalue())
            	vsyncOption->setvalue(true);
    	}
	public:
    static void initialize(const uintptr_t optionsEntryPtr){
        optionsBaseEntry = (uintptr_t **) optionsEntryPtr;
        initialized = true;
        initVsync();
    };
	static std::atomic_bool dirty;

	static bool init();
	static bool load();
	static bool save();

private:
	static std::string optionsDir;
	static std::string optionsFile;
};
