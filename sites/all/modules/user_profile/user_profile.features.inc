<?php
/**
 * @file
 * user_profile.features.inc
 */

/**
 * Implements hook_views_api().
 */
function user_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function user_profile_image_default_styles() {
  $styles = array();

  // Exported image style: profile_image.
  $styles['profile_image'] = array(
    'name' => 'profile_image',
    'label' => 'profile Image',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 160,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function user_profile_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : {
      "registration" : false,
      "use_page" : 1,
      "step_step" : "",
      "step_exclude" : { "field_name" : 0, "field_date_of_birth" : 0 }
    },
    "rdf_mapping" : []
  }');
  $items['timeline'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "timeline",
    "label" : "Timeline",
    "weight" : "0",
    "data" : {
      "registration" : false,
      "use_page" : 1,
      "step_step" : "",
      "step_exclude" : []
    },
    "rdf_mapping" : []
  }');
  $items['view_as_visitors'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "view_as_visitors",
    "label" : "View As Visitors",
    "weight" : "0",
    "data" : { "registration" : false, "use_page" : 1, "step_step" : "" },
    "rdf_mapping" : []
  }');
  return $items;
}
