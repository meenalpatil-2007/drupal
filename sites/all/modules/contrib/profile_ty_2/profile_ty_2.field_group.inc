<?php
/**
 * @file
 * profile_ty_2.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function profile_ty_2_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partner_preference|profile2|main|form';
  $field_group->group_name = 'group_partner_preference';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Partner Preference',
    'weight' => '2',
    'children' => array(
      0 => 'field_partner_preference',
      1 => 'field_partner_height',
      2 => 'field_partner_age',
      3 => 'field_partner_education',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Partner Preference',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_partner_preference|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|profile2|main|form';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_about_me',
      3 => 'field_birth_date',
      4 => 'field_birth_place',
      5 => 'field_profile_img',
      6 => 'field_gender',
      7 => 'field_looking_for',
      8 => 'field_religion',
      9 => 'field_marital_status',
      10 => 'field_living_location',
      11 => 'field_mobile_number',
      12 => 'field_hobbies',
      13 => 'field_height',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personal|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_professional|profile2|main|form';
  $field_group->group_name = 'group_professional';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Professional Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_education',
      1 => 'field_employment_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-professional field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_professional|profile2|main|form'] = $field_group;

  return $export;
}
