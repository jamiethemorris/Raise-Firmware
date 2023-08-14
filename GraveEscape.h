#pragma once

#include <Kaleidoscope.h>

namespace kaleidoscope {
namespace plugin {

class GraveEscape : public kaleidoscope::Plugin {
public:
  kaleidoscope::EventHandlerResult onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t keyState);

private:
  bool shiftActive();
  bool guiActive();
};

}
}

extern kaleidoscope::plugin::GraveEscape GraveEscape;

// Override flags - default back to normal behavior if these are held
#define GRAVE_ESC_ALT_OVERRIDE
#define GRAVE_ESC_CTRL_OVERRIDE
