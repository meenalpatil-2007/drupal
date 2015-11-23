<?php

/**
 * @file
 * Default theme implementation for profiles.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) profile type label.
 * - $url: The URL to view the current profile.
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - profile-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php  if (!$page): ?>
    <h2<?php print $title_attributes; ?>>
        <a href="<?php print $url; ?>"><?php print $title; ?></a>
    </h2>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php	    ?>
	
	<div id="userprofile-form">
<div class="row">

<?php  //print kpr($form);  
/*
print render($form['form_id']); 
print render($form['form_build_id']); 
print render ($form['form_token']);

print render($form['field_image']);
print render($form['title']);

print render ($form['actions']);
*/
?>
<div class="col-sm-12 col-md-12 col-lg-12">
	<div class="panel panel-default">
		<div class="panel-heading">Profile Details</div>
			<div class="panel-body">
			<div class="col-sm-6 col-md-6 col-lg-6">
				<div id="img_box" class="img-responsive">
				<img src="http://drupal.dev/sites/default/files/<?php echo $content['field_profile_img'][0]["#item"]["filename"]; ?>" class="img-responsive" width="150px"
					<?php //print render($content['field_profile_img']); //var_dump($content['field_profile_img'][0]["#item"]["filename"]);exit;?>							
				</div>
			</div>
			<div class="col-sm-6 col-md-6 col-lg-6">			
				<h3><?php print render($content['field_first_name'][0]['#markup']);?>&nbsp;<?php print render($content['field_last_name'][0]['#markup']);//echo $user_name = $GLOBALS['user']->name; ?></h3>	
				<b><?php print render($content['field_gender']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_gender'][0]['#markup']); ?></br>
				<b><?php print render($content['field_looking_for']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_looking_for'][0]['#markup']); ?>
			</div>
			</div>
	</div>
	<div class="panel panel-default">
	<div class="panel-heading">Personal Details</div>
		<div class="panel-body">
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_about_me']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_about_me'][0]['#markup']); ?><br/>
			<b><?php print render($content['field_birth_date']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_birth_date'][0]['#markup']); ?><br/>
			<b><?php print render($content['field_hobbies']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_hobbies'][0]['#markup']); ?>
		</div>
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_religion']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_religion'][0]['#markup']); ?></br>
			<b><?php print render($content['field_marital_status']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_marital_status'][0]['#markup']); ?></br>
			<b><?php print render($content['field_birth_place']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_birth_place'][0]['#markup']); ?></br>
			<b><?php print render($content['field_height']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_height'][0]['#markup']); ?>
		</div>
		</div>

	</div>
	<div class="panel panel-default">
	<div class="panel-heading">Professional Details</div>
		<div class="panel-body">
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_education']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_education'][0]['#markup']); ?>
		</div>
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_employment_type']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_employment_type'][0]['#markup']); ?>
		</div>
		</div>

	</div>
	<div class="panel panel-default">
	<div class="panel-heading">Contact Details</div>
		<div class="panel-body">
		<!--div class="col-sm-6 col-md-6 col-lg-6">
			<?php //echo "<pre>"; print_r($content); ?>
			<b><?php //print render($content->field_living_location['und'][0]['value']);?></b>&nbsp;:&nbsp;<?php //print render($content->field_living_location['und'][0]['value']); ?>
		</div-->
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_mobile_number']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_mobile_number'][0]['#markup']); ?>
		</div>
		</div>

	</div>
	<div class="panel panel-default">
	<div class="panel-heading">Partner Preference</div>
		<div class="panel-body">
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_partner_preference']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_partner_preference'][0]['#markup']); ?>
		</div>
		<div class="col-sm-6 col-md-6 col-lg-6">
			<b><?php print render($content['field_partner_height']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_partner_height'][0]['#markup']); ?></br>
			<b><?php print render($content['field_partner_age']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_partner_age'][0]['#markup']); ?></br>
			<b><?php print render($content['field_partner_education']['#title']);?></b>&nbsp;:&nbsp;<?php print render($content['field_partner_education'][0]['#markup']); ?>
		</div>
		</div>

	</div>
</div>
</div>
</div>
	
  </div>
</div>
