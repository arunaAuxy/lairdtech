<?php
/**
 * @file
 * user_profile.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function user_profile_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_profile:profile-main
  $menu_links['user-menu_profile:profile-main'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'profile-main',
    'router_path' => 'profile-main',
    'link_title' => 'Profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_profile:profile-main',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Profile');


  return $menu_links;
}
