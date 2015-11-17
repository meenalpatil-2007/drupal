<?php
/**
 * @file
 * Defines classes used by the MASt module.
 */

/**
 * Defines a reference field implementation.
 */
class M2serveConnectorMastFieldCollectionField extends mastFieldStandard {
  /**
   * Function buildmastfield.
   */
  public function buildMastField() {
    $this->initializeMastField();
    $this->mast_field["fields_collection"] = array();
    $mast_structure = mastFactory::createEntityStructure("field_collection_item", $this->field_info['field_name']);
    $this->mast_field["fields_collection"] = $mast_structure->getAllFields();
  }
}

/**
 * Defines a reference field implementation.
 */
class M2serveConnectorMastEntityReferenceField extends mastFieldStandard {
  /**
   * Function buildmastfield.
   */
  public function buildMastField() {
    $this->initializeMastField();
  }
}

/**
 * Adds fields in the field collection  item's instance.
 */
class M2serveConnectorMastEntityStructureCollectionNode extends  mastEntityStructureNode {
  /**
   * Function addFields().
   */
  protected function addFields() {
    $fields = mast_field_info_fields();
    $instances = mast_field_info_instances('field_collection_item', $this->bundle);
    if (!$this->authorOverridePermitted('field_collection_item', $this->bundle)) {
      unset($instances['author']);
    }
    foreach ($instances as $instance_info) {
      $field_info = $fields[$instance_info['field_name']];
      $this->addField($field_info, $instance_info);
    }
  }
}

/**
 * Adds fields in the field node item's instance.
 */
class M2serveConnectorMastNodeReferenceField extends mastFieldStandard {
  /**
   * Function buildMastField().
   */
  public function buildMastField() {
    $this->initializeMastField();
    $this->mast_field['options'] = array();
    $this->mast_field['options']['match'] = $this->resourcePath('autocomplete');
    $this->mast_field['options']['scroll'] = $this->resourcePath('options');
    // The only flag we have for a "free tagging" field is the widget.
    if (isset($this->instance_info['default_value'])) {
      $this->mast_field['default'] = new stdClass();
      foreach ($this->instance_info['default_value'] as $data) {
        $this->mast_field['default']->key = $data['nid'];
        if (!isset($data['name'])) {
          $data['name'] = db_query("SELECT title from {node} WHERE nid = :nid", array(':nid' => $data['nid']))->fetchField();
        }
        $this->mast_field['default']->value = $data['name'];
      }
    }
  }
  /**
   * Function autoComplete().
   */
  public function autoComplete($match, $count) {
    $this->autoCompleteValidateParams($match, $count);
    // $term_matches = array();
    // Make sure the field exists and is a taxonomy field.
    if ($this->field_info['type'] !== 'node_reference') {
      return services_error(t('Node field @field_name not found.', array('@field_name' => $this->instance_info['field_name'])), 404);
    }
    // The user enters a comma-separated list of tags.
    // We only autocomplete the last tag.
    // $tag_last = drupal_strtolower(array_pop($match));
    // $field = $this->field_info;
    // $instance = $this->field_instance;
    $options = array(
      'string' => '',
      'match' => $match,
      'limit' => 10,
    );
    $references = node_reference_potential_references($this->field_info, $options);

    $matches = array();
    foreach ($references as $id => $row) {
      // Markup is fine in autocompletion results (might happen when rendered
      // through Views) but we want to remove hyperlinks.
      $suggestion = preg_replace('/<a href="([^<]*)">([^<]*)<\/a>/', '$2', $row['rendered']);
      // Add a class wrapper for a few required CSS overrides.
      $matches[] = array("nid" => $id , "title" => $suggestion);
    }
    return $matches;
  }
}
