#include "HaEntityHumidity.h"
#include "ArduinoJson.h"
#include <HaUtilities.h>

#define COMPONENT "sensor"
#define OBJECT_ID "humidity"

HaEntityHumidity::HaEntityHumidity(HaBridge &ha_bridge, std::string name, std::string child_object_id,
                                   bool force_update)
    : _name(homeassistantentities::trim(name)), _force_update(force_update), _ha_bridge(ha_bridge),
      _child_object_id(child_object_id) {}

void HaEntityHumidity::publishConfiguration() {
  DynamicJsonDocument doc(512);

  if (!_name.empty()) {
    doc["name"] = _name;
  } else {
    doc["name"] = (char *)NULL;
  }
  doc["device_class"] = "humidity";
  doc["unit_of_measurement"] = "%";
  doc["force_update"] = _force_update;
  doc["state_topic"] = _ha_bridge.getTopic(HaBridge::TopicType::State, COMPONENT, OBJECT_ID, _child_object_id);
  _ha_bridge.publishConfiguration(COMPONENT, OBJECT_ID, _child_object_id, doc);
}

void HaEntityHumidity::republishState() {
  if (_humidity) {
    publishHumidity(*_humidity);
  }
}

void HaEntityHumidity::publishHumidity(double humidity) {
  _ha_bridge.publishMessage(_ha_bridge.getTopic(HaBridge::TopicType::State, COMPONENT, OBJECT_ID, _child_object_id),
                            std::to_string(humidity));
  _humidity = humidity;
}
