<?php
/**
 * @file
 * Service module resource callbacks for the m2serve services views list.
 */

/**
 * Return list of views on drupal instance. 
 * 
 * Callback for retrieving views_list resources.
 * @return array
 *   An array of views
 */
function m2serve_services_views_list_resource() {
  // Get all views.
  $views = views_get_all_views();

  // Iterate through each view and check if they have services display in them.
  // If service display not present then add services display for them.
  foreach ($views as $viewkey => &$view) {
    if ($view->disabled != 1) {
      // Iterate through each display of view.
      // and check if they have services display in set or not.
      foreach ($view->display as $key => &$display) {
        // Count the number of views having display as 'services'
        // Increase view display count.
        // $view_display_count++;
        // Check if 'services' display is set for view or not.
        if ($display->display_plugin != 'services') {
          unset($views[$viewkey]->display[$key]);
        }
      }
    }
    else {
      unset($views[$viewkey]);
    }
  }
  return $views;
}
