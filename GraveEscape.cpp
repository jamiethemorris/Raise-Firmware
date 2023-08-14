#include "GraveEscape.h"

namespace kaleidoscope 
{
    namespace plugin 
    {
        kaleidoscope::EventHandlerResult GraveEscape::onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t keyState) 
        {
            if (mapped_key != Key_Escape || keyToggledOff(keyState)) 
            {
                return kaleidoscope::EventHandlerResult::OK;
            }

            #ifdef GRAVE_ESC_ALT_OVERRIDE
            if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightAlt)) 
            {
                return kaleidoscope::EventHandlerResult::OK;
            }
            #endif

            #ifdef GRAVE_ESC_CTRL_OVERRIDE
            if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftControl) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightControl)) 
            {
                return kaleidoscope::EventHandlerResult::OK;
            }
            #endif

            if (shiftActive()) 
            {
                mapped_key = LSHIFT(Key_Backtick); // Shifted backtick (tilde)
            } 
            else if (guiActive()) 
            {
                mapped_key = Key_Backtick; // Unshifted backtick
            }

            return kaleidoscope::EventHandlerResult::OK;
        }

        bool GraveEscape::shiftActive() 
        {
            return Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift);
        }

        bool GraveEscape::guiActive() 
        {
            return Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftGui) || Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightGui);
        }

    }
}

kaleidoscope::plugin::GraveEscape GraveEscape;