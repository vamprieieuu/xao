// XAO ASCII — PiPL resource.
//
// AE_PiPL_Version must match PF_VERSION in the build.  Both come from
// XAO_Ascii.h / the generated XAO_Version.h so they cannot drift.

#include "AEConfig.h"
#include "AE_EffectVers.h"

#ifndef AE_OS_WIN
    #include "AE_General.r"
#endif

resource 'PiPL' (16000) {
    {
        Kind {
            AEEffect
        },
        Name {
            "XAO ASCII"
        },
        Category {
            "XAO"
        },

#ifdef AE_OS_WIN
    #if defined(AE_PIPL_USE_MAC_CODE)
        CodeWin64X86 { "EffectMain" },
        CodeMacIntel64 { "EffectMain" },
    #else
        CodeWin64X86 { "EffectMain" },
    #endif
#else
        CodeMacIntel64 { "EffectMain" },
#endif

        AE_PiPL_Version {
            2
        },

        AE_Effect_Spec_Version {
            PF_SpecVersion
        },
        AE_Effect_Version {
            65536       // 1.0.0.0 — keep in sync with XAO_VERSION_*
        },
        AE_Effect_Info_Flags {
            0
        },
        AE_Effect_Global_OutFlags {
            0x02000020  // PF_OutFlag_DEEP_COLOR_AWARE | PF_OutFlag_SEND_UPDATE_PARAMS_UI
        },
        AE_Effect_Global_OutFlags_2 {
            0x00010000  // PF_OutFlag2_SUPPORTS_THREADED_RENDERING
        },
        AE_Effect_Match_Name {
            "XAO ASCII"
        },
        AE_Reserved_Info {
            0
        }
    }
};
