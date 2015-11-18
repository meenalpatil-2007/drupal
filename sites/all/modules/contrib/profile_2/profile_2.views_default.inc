<?php
/**
 * @file
 * profile_2.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function profile_2_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'main_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'main profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'my page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'main' => 'main',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Field: Profile: about me */
  $handler->display->display_options['fields']['field_about_me']['id'] = 'field_about_me';
  $handler->display->display_options['fields']['field_about_me']['table'] = 'field_data_field_about_me';
  $handler->display->display_options['fields']['field_about_me']['field'] = 'field_about_me';
  /* Field: Profile: birth date */
  $handler->display->display_options['fields']['field_birth_date']['id'] = 'field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['table'] = 'field_data_field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['field'] = 'field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Profile: birth place */
  $handler->display->display_options['fields']['field_birth_place']['id'] = 'field_birth_place';
  $handler->display->display_options['fields']['field_birth_place']['table'] = 'field_data_field_birth_place';
  $handler->display->display_options['fields']['field_birth_place']['field'] = 'field_birth_place';
  /* Field: Profile: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'profile';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Profile: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Profile: education */
  $handler->display->display_options['fields']['field_education']['id'] = 'field_education';
  $handler->display->display_options['fields']['field_education']['table'] = 'field_data_field_education';
  $handler->display->display_options['fields']['field_education']['field'] = 'field_education';
  /* Field: Profile: employment type */
  $handler->display->display_options['fields']['field_employment_type']['id'] = 'field_employment_type';
  $handler->display->display_options['fields']['field_employment_type']['table'] = 'field_data_field_employment_type';
  $handler->display->display_options['fields']['field_employment_type']['field'] = 'field_employment_type';
  /* Field: Profile: first name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Profile: gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  /* Field: Profile: hobbies */
  $handler->display->display_options['fields']['field_hobbies']['id'] = 'field_hobbies';
  $handler->display->display_options['fields']['field_hobbies']['table'] = 'field_data_field_hobbies';
  $handler->display->display_options['fields']['field_hobbies']['field'] = 'field_hobbies';
  $handler->display->display_options['fields']['field_hobbies']['type'] = 'list_default';
  /* Field: Profile: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'profile';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  /* Field: Profile: last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: Profile: living location */
  $handler->display->display_options['fields']['field_living_location']['id'] = 'field_living_location';
  $handler->display->display_options['fields']['field_living_location']['table'] = 'field_data_field_living_location';
  $handler->display->display_options['fields']['field_living_location']['field'] = 'field_living_location';
  /* Field: Profile: looking for */
  $handler->display->display_options['fields']['field_looking_for']['id'] = 'field_looking_for';
  $handler->display->display_options['fields']['field_looking_for']['table'] = 'field_data_field_looking_for';
  $handler->display->display_options['fields']['field_looking_for']['field'] = 'field_looking_for';
  /* Field: Profile: marital status */
  $handler->display->display_options['fields']['field_marital_status']['id'] = 'field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['table'] = 'field_data_field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['field'] = 'field_marital_status';
  /* Field: Profile: mobile number */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  /* Field: Profile: partner age */
  $handler->display->display_options['fields']['field_partner_age']['id'] = 'field_partner_age';
  $handler->display->display_options['fields']['field_partner_age']['table'] = 'field_data_field_partner_age';
  $handler->display->display_options['fields']['field_partner_age']['field'] = 'field_partner_age';
  /* Field: Profile: partner education */
  $handler->display->display_options['fields']['field_partner_education']['id'] = 'field_partner_education';
  $handler->display->display_options['fields']['field_partner_education']['table'] = 'field_data_field_partner_education';
  $handler->display->display_options['fields']['field_partner_education']['field'] = 'field_partner_education';
  /* Field: Profile: partner height */
  $handler->display->display_options['fields']['field_partner_height']['id'] = 'field_partner_height';
  $handler->display->display_options['fields']['field_partner_height']['table'] = 'field_data_field_partner_height';
  $handler->display->display_options['fields']['field_partner_height']['field'] = 'field_partner_height';
  /* Field: Profile: partner preference */
  $handler->display->display_options['fields']['field_partner_preference']['id'] = 'field_partner_preference';
  $handler->display->display_options['fields']['field_partner_preference']['table'] = 'field_data_field_partner_preference';
  $handler->display->display_options['fields']['field_partner_preference']['field'] = 'field_partner_preference';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid_1']['id'] = 'pid_1';
  $handler->display->display_options['fields']['pid_1']['table'] = 'profile';
  $handler->display->display_options['fields']['pid_1']['field'] = 'pid';
  /* Field: Profile: profile img */
  $handler->display->display_options['fields']['field_profile_img']['id'] = 'field_profile_img';
  $handler->display->display_options['fields']['field_profile_img']['table'] = 'field_data_field_profile_img';
  $handler->display->display_options['fields']['field_profile_img']['field'] = 'field_profile_img';
  $handler->display->display_options['fields']['field_profile_img']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_img']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Profile: religion */
  $handler->display->display_options['fields']['field_religion']['id'] = 'field_religion';
  $handler->display->display_options['fields']['field_religion']['table'] = 'field_data_field_religion';
  $handler->display->display_options['fields']['field_religion']['field'] = 'field_religion';
  /* Field: Profile: Rendered Profile */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'account';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Profile: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'profile';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['path'] = 'main-profile';
  $export['main_profile'] = $view;

  $view = new view();
  $view->name = 'user_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'User Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'main' => 'main',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Field: Profile: about me */
  $handler->display->display_options['fields']['field_about_me']['id'] = 'field_about_me';
  $handler->display->display_options['fields']['field_about_me']['table'] = 'field_data_field_about_me';
  $handler->display->display_options['fields']['field_about_me']['field'] = 'field_about_me';
  /* Field: Profile: birth date */
  $handler->display->display_options['fields']['field_birth_date']['id'] = 'field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['table'] = 'field_data_field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['field'] = 'field_birth_date';
  $handler->display->display_options['fields']['field_birth_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Profile: birth place */
  $handler->display->display_options['fields']['field_birth_place']['id'] = 'field_birth_place';
  $handler->display->display_options['fields']['field_birth_place']['table'] = 'field_data_field_birth_place';
  $handler->display->display_options['fields']['field_birth_place']['field'] = 'field_birth_place';
  /* Field: Profile: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'profile';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Profile: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'profile';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Profile: education */
  $handler->display->display_options['fields']['field_education']['id'] = 'field_education';
  $handler->display->display_options['fields']['field_education']['table'] = 'field_data_field_education';
  $handler->display->display_options['fields']['field_education']['field'] = 'field_education';
  /* Field: Profile: employment type */
  $handler->display->display_options['fields']['field_employment_type']['id'] = 'field_employment_type';
  $handler->display->display_options['fields']['field_employment_type']['table'] = 'field_data_field_employment_type';
  $handler->display->display_options['fields']['field_employment_type']['field'] = 'field_employment_type';
  /* Field: Profile: first name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Profile: gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  /* Field: Profile: height */
  $handler->display->display_options['fields']['field_height']['id'] = 'field_height';
  $handler->display->display_options['fields']['field_height']['table'] = 'field_data_field_height';
  $handler->display->display_options['fields']['field_height']['field'] = 'field_height';
  /* Field: Profile: hobbies */
  $handler->display->display_options['fields']['field_hobbies']['id'] = 'field_hobbies';
  $handler->display->display_options['fields']['field_hobbies']['table'] = 'field_data_field_hobbies';
  $handler->display->display_options['fields']['field_hobbies']['field'] = 'field_hobbies';
  $handler->display->display_options['fields']['field_hobbies']['type'] = 'list_default';
  /* Field: Profile: last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: Profile: living location */
  $handler->display->display_options['fields']['field_living_location']['id'] = 'field_living_location';
  $handler->display->display_options['fields']['field_living_location']['table'] = 'field_data_field_living_location';
  $handler->display->display_options['fields']['field_living_location']['field'] = 'field_living_location';
  /* Field: Profile: looking for */
  $handler->display->display_options['fields']['field_looking_for']['id'] = 'field_looking_for';
  $handler->display->display_options['fields']['field_looking_for']['table'] = 'field_data_field_looking_for';
  $handler->display->display_options['fields']['field_looking_for']['field'] = 'field_looking_for';
  /* Field: Profile: marital status */
  $handler->display->display_options['fields']['field_marital_status']['id'] = 'field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['table'] = 'field_data_field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['field'] = 'field_marital_status';
  /* Field: Profile: mobile number */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_mobile_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: partner age */
  $handler->display->display_options['fields']['field_partner_age']['id'] = 'field_partner_age';
  $handler->display->display_options['fields']['field_partner_age']['table'] = 'field_data_field_partner_age';
  $handler->display->display_options['fields']['field_partner_age']['field'] = 'field_partner_age';
  /* Field: Profile: partner education */
  $handler->display->display_options['fields']['field_partner_education']['id'] = 'field_partner_education';
  $handler->display->display_options['fields']['field_partner_education']['table'] = 'field_data_field_partner_education';
  $handler->display->display_options['fields']['field_partner_education']['field'] = 'field_partner_education';
  /* Field: Profile: partner height */
  $handler->display->display_options['fields']['field_partner_height']['id'] = 'field_partner_height';
  $handler->display->display_options['fields']['field_partner_height']['table'] = 'field_data_field_partner_height';
  $handler->display->display_options['fields']['field_partner_height']['field'] = 'field_partner_height';
  /* Field: Profile: partner preference */
  $handler->display->display_options['fields']['field_partner_preference']['id'] = 'field_partner_preference';
  $handler->display->display_options['fields']['field_partner_preference']['table'] = 'field_data_field_partner_preference';
  $handler->display->display_options['fields']['field_partner_preference']['field'] = 'field_partner_preference';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid_1']['id'] = 'pid_1';
  $handler->display->display_options['fields']['pid_1']['table'] = 'profile';
  $handler->display->display_options['fields']['pid_1']['field'] = 'pid';
  /* Field: Profile: profile img */
  $handler->display->display_options['fields']['field_profile_img']['id'] = 'field_profile_img';
  $handler->display->display_options['fields']['field_profile_img']['table'] = 'field_data_field_profile_img';
  $handler->display->display_options['fields']['field_profile_img']['field'] = 'field_profile_img';
  $handler->display->display_options['fields']['field_profile_img']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_img']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Profile: religion */
  $handler->display->display_options['fields']['field_religion']['id'] = 'field_religion';
  $handler->display->display_options['fields']['field_religion']['table'] = 'field_data_field_religion';
  $handler->display->display_options['fields']['field_religion']['field'] = 'field_religion';
  /* Field: Profile: User uid */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'profile';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  $handler->display->display_options['path'] = 'user-profile';
  $export['user_profile'] = $view;

  return $export;
}
