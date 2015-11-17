<?php
/**
 * @file
 * Service module resource callbacks for the m2serve. *
 */

/**
 * Callback for services_list() within m2serve_connector_services_resources().
 *
 * To list all services available.
 */
function _m2serve_connector_resource_services_list() {
  // Initialize.
  $ops = array('actions', 'relationships', 'targeted_actions', 'operations');
  $url_site = $GLOBALS['base_url'];
  $result = array();

  $endpoint = 'm2serve';
  // Get all resources of m2serve web service.
  $resources = services_get_resources($endpoint);

  foreach ($resources as $resource_name => $res) {
    // Handle extended operations.
    foreach ($ops as $op) {
      if (isset($res[$op])) {
        foreach ($res[$op] as $name => $def) {
          $url = $url_site . '/' . $endpoint . '/' . $resource_name;
          if (!in_array($name, array("delete", "retrieve"))) {
            $url .= '/' . $name;
          }
          if ($resource_name) {
            if (isset($def['args'])) {
              foreach ($def['args'] as $key => $value) {
                if (isset($value["source"]["path"])) {
                  $url .= '/{' . $value['name'] . '}';
                }
              }
            }
            $result[$resource_name][$name] = array(
              'url' => $url,
              'args' => $def['args'],
              'request_type' => m2serve_connector_get_request_type($name),
              'enabled' => isset($res["endpoint"][$op][$name]["enabled"]) ? 1 : 0,
            );
          }
        }
      }
    }
  }
  return $result;
}

/**
 * Callback for profile2_list() within m2serve_connector_services_resources().
 */
function _m2serve_connector_resource_profile2_list($type_name = NULL) {
  $return = array();
  $profile2_types = profile2_get_types($type_name);

  foreach ($profile2_types as $key => $profile2_type) {
    // Get all field related to this profile type.
    $fields = field_info_instances('profile2', $key);
    $return[$key] = $fields;
  }
  return $return;
}

/**
 * Check the access permission to a given resource.
 *
 * @param string $op
 *   The operation that's going to be performed.
 *
 * @return bool
 *   TRUE if the user is allowed to load the given view.
 *
 * @todo Delete the whole body of the function and use commerce_entity_access().
 */
function _m2serve_connector_resource_access($op) {
  // Global user variable
  // global $user;
  // $access = FALSE;
  // @todo Instead of passing direct value TRUE, call user_access functions
  // switch ($op) {
  // case 'view':
  // $access = user_access('');
  // break;
  // case 'create':
  // $access = user_access('');
  // break;
  // case 'update':
  // $access = user_access('');
  // break;
  // case 'delete':
  // $access = user_access('');
  // break;
  // }
  // Remove when access function is finished, just for testing.
  $access = TRUE;

  return $access;
}


/**
 * Callback for content_type_list().
 *
 * Within m2serve_connector_services_resources().
 * To list all content types with there fields and response structure.
 */
function _m2serve_connector_resource_content_type_list() {
  module_load_include('inc', 'mast', 'mast.services.inc');
  $content_type_list = _mast_fields_index();
  // $node_id_array = array();
  foreach ($content_type_list['node'] as $key => $value) {
    $content_type_list['node'][$key]['sample_response'] = m2serve_connector_generate_content_add_node($key);
  }
  // Add code to delete the nodes as well.
  // node_delete_multiple($node_id_array).
  return $content_type_list;
}

/**
 * Create one node. Used by both batch and non-batch code branches.
 *
 * @param array $node_type
 *   array of options obtained from devel_generate_content_form.
 */
function m2serve_connector_generate_content_add_node($node_type) {
  global $user;
  $node = new stdClass();
  $node->nid = NULL;

  // Insert new data:
  $node->type = $node_type;
  node_object_prepare($node);
  $node->uid = $user->uid;
  // To get the type of the node
  // $type = node_type_get_type($node);
  $node->title = 'Random';

  // Adding unpublished node.
  $node->status = 0;

  // Adding un-promoted node.
  $node->promote = 0;

  $results = '';
  module_load_include('inc', 'devel', 'devel_generate/devel_generate');
  devel_generate_set_language($results, $node);

  // A flag to let hook_nodeapi() implementations know that is a generated node.
  // $node->devel_generate = $results;.
  // Populate all core fields on behalf of field.module.
  module_load_include('inc', 'devel', 'devel_generate/devel_generate.fields');
  devel_generate_fields($node, 'node', $node->type);

  // See devel_generate_nodeapi() for actions that happen before and after save.
  node_save($node);

  return _m2serve_connector_node_resource_retrieve($node->nid);
}

/**
 * Callback for m2serve node load.
 *
 * If fetches the reference fields values as well and passes it along with node.
 */
function _m2serve_connector_node_resource_retrieve($nid) {
  $node = _node_resource_retrieve($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  foreach ($node as $node_field => $node_field_value) {
    $field_info = field_info_field($node_field);
    $field_type = $field_info["type"];
    switch ($field_type) {
      case "taxonomy_term_reference":
        if ($node->{$node_field}[$node->language] != NULL) {
          $i = 0;
          foreach ($node->{$node_field}[$node->language] as $taxonomy_value) {
            $taxonomy_wrapper = entity_metadata_wrapper('taxonomy_term', $taxonomy_value["tid"]);
            $node->{$node_field}[$node->language][$i]["name"] = $taxonomy_wrapper->value()->name;
            $i++;
          }
        }
        break;

      case "node_reference":
        if ($node->{$node_field}[$node->language] != NULL) {
          $i = 0;
          foreach ($node->{$node_field}[$node->language] as $node_value) {
            $node_wrapper = node_load($node_value['nid']);
            $node->{$node_field}[$node->language][$i]["name"] = $node_wrapper->title;
            $i++;
          }
        }
        break;

      case "user_reference":
        if ($node->{$node_field}[$node->language] != NULL) {
          $i = 0;
          foreach ($node->{$node_field}[$node->language] as $user_value) {
            $user_wrapper = entity_metadata_wrapper('user', $user_value["uid"]);
            $node->{$node_field}[$node->language][$i]["name"] = $user_wrapper->value()->name;
            $i++;
          }
        }
        break;

      case "entityreference":
        if ($node->{$node_field}[$node->language] != NULL) {
          $i = 0;
          foreach ($node->{$node_field}[$node->language] as $entity_value) {
            if ($field_info["settings"]["target_type"] == "node") {
              $entity_wrapper = entity_metadata_wrapper($field_info["settings"]["target_type"], $entity_value["target_id"]);
              $node->{$node_field}[$node->language][$i]["name"] = $entity_wrapper->value()->title;
            }
            elseif ($field_info["settings"]["target_type"] == "user") {
              $entity_wrapper = entity_metadata_wrapper($field_info["settings"]["target_type"], $entity_value["target_id"]);
              $node->{$node_field}[$node->language][$i]["name"] = $entity_wrapper->value()->name;
            }
            elseif ($field_info["settings"]["target_type"] == "comment") {
              $entity_wrapper = entity_metadata_wrapper($field_info["settings"]["target_type"], $entity_value["target_id"]);
              $node->{$node_field}[$node->language][$i]["name"] = $entity_wrapper->value()->subject;
            }
            else {
              $node->{$node_field}[$node->language][$i]["name"] = $entity_value["target_id"];
            }

            $i++;
          }
        }
        break;

      case "list_float":
      case "list_integer":
      case "list_text":
        if ($node->{$node_field}[$node->language] != NULL) {
          foreach ($node->{$node_field}[$node->language] as $key => $value) {
            if ($node->{$node_field}[$node->language][$key]) {
              $node->{$node_field}[$node->language][$key]['value_title'] = $field_info['settings']['allowed_values'][$node->{$node_field}[$node->language][$key]['value']];
            }
          }
        }
        break;

      case "image":
        if ($node->{$node_field}[$node->language] != NULL) {
          foreach ($node->{$node_field}[$node->language] as $key => $file) {
            if ($file['uri']) {
              $node->{$node_field}[$node->language][$key]['url'] = file_create_url($file['uri']);
            }
            else {
              $node->{$node_field}[$node->language][$key]['url'] = '';
            }
          }
        }
        break;

      case 'field_collection':
        if ($node->{$node_field} && $node->{$node_field}[$node->language]) {
          foreach ($node->{$node_field}[$node->language] as $field_collection_key => $field_collection_value) {
            $field_collection_item = field_collection_item_load($field_collection_value['value']);
            $mast_structure = mastFactory::createEntityStructure("field_collection_item", $node_field);
            foreach ($mast_structure->getAllFields() as $item_field_name => $item_value) {
              $node->{$node_field}[$node->language][$field_collection_key][$item_field_name] = $field_collection_item->{$item_field_name};
            }
          }
        }
        break;

      default:
        break;
    }
  }
  return $node;
}
