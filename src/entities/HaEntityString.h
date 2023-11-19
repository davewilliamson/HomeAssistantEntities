#ifndef __HA_ENTITY_STRING_H__
#define __HA_ENTITY_STRING_H__

#include "ArduinoJson.h"
#include <Arduino.h>
#include <HaBridge.h>
#include <HaEntity.h>

/**
 * @brief Represent a raw String sensor with a state topic on which you post your string.
 * Also see [HaEntityJson] which is very similar. TODO(johboh): merge?
 */
class HaEntityString : public HaEntity {
public:
  /**
   * @brief Construct a new Ha Entity String object
   *
   * @param name this is the human readable name that will be used for the entity in Home Assistant. If a device is set
   * when creating the [HaBridge], the friendly named displayed in the UI will be the device name plus this name.
   * Example: if device name is "Bathroom" and entity name "string", friendly name will be "Bathroom string". If no
   * device, friendly name will be just "string". If a device is set, this name can be left empty if this entity is the
   * one main entity (or only) entity of this device. See
   * https://developers.home-assistant.io/docs/core/entity/#entity-naming for more
   * information.
   * @param child_object_id optional child identifier for this entity in case there are several sensors of the same
   * entity type for the same node ID. Example: If you have a lock for the node ID "door", the home asisstant
   * configuration path will be "homeassistant/binary_sensor/door/lock/config". This works if you only have one lock on
   * your door, but if you have two locks, you want to add a child object ID to them. By setting the child_object_id to
   * say "upper", the configuration will be "homeassistant/binary_sensor/door/lock/upper/config". This also apply for
   * all state/command topics and so on. Leave as empty string for no child object ID. Valid characters
   * are [a-zA-Z0-9_-] (machine readable, not human readable)
   * @param force_update In Home Assistant, trigger events even if the sensor's state hasn't changed. Useful if you want
   * to have meaningful value graphs in history or want to create an automation that triggers on every incoming state
   * message (not only when the sensor’s new state is different to the current one).
   */
  HaEntityString(HaBridge &ha_bridge, String name, String child_object_id = "", bool force_update = false);

public:
  void publishConfiguration() override;
  void republishState() override;

  /**
   * @brief Publish the String.
   *
   * @param json_doc the String to publish.
   */
  void publishMessage(String &message);

private:
  String _name;
  bool _force_update;
  HaBridge &_ha_bridge;
  String _child_object_id;

private:
  std::optional<String> _message;
};

#endif // __HA_ENTITY_STRING_H__