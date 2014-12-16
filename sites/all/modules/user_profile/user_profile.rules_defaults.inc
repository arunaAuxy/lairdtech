<?php
/**
 * @file
 * user_profile.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_profile_default_rules_configuration() {
  $items = array();
  $items['rules_login'] = entity_import('rules_config', '{ "rules_login" : {
      "LABEL" : "login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "user" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "watchdog" : [] },
      "DO" : [
        { "drupal_message" : { "message" : "[site:name] welcome", "repeat" : 0 } }
      ]
    }
  }');
  return $items;
}
