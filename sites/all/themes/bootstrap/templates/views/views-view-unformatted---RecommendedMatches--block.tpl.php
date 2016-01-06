<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$profiles = $view->style_plugin->rendered_fields;
drupal_add_css('sites/all/themes/bootstrap/css/matching-profile.css', array('group' => CSS_THEME, 'type' => 'external'));
?>
<div class="list-content">
<ul class="list-group">
	<li  class="list-group-item header title">
	    Recommended Matches 
	    <div class="heart-divider">
			<span class="grey-line"></span>
			<i class="fa fa-heart pink-heart"></i>
			<i class="fa fa-heart grey-heart"></i>
			<span class="grey-line"></span>
		</div>
	</li>
	<div class="test">
		<?php foreach ($profiles as $profile) { ?>
		  	<li  class="list-group-item text-left <?php echo count($profiles) >= 4 ? 'col-sm-6 col-md-3 col-lg-3' : 'col-sm-6 col-md-6 col-lg-6'; ?>">
		  	<?php if ($profile['field_profile_img']) print $profile['field_profile_img'];    			
		      	else { ?>      			
		      	<a href="<?php echo base_path(); ?>profile-main/<?php echo $profile['uid']; ?>" class="name">
			      	<img  typeof="foaf:Image" class="img-responsive" width="80" height="80" src="sites/all/themes/bootstrap/img/<?php print strtolower($profile['field_gender']); ?>.png" > <?php
				} ?>
		      	</a>
		      	<?php print $profile['field_first_name']; ?>
		      	<div class="subtitle-small ext-box glyphicon glyphicon-envelope "><div class="int-box"><?php print $profile['mail']; ?></div></div>
		      	<div class="subtitle-small ext-box glyphicon glyphicon-registration-mark"><div class="int-box"><?php print $profile['field_religion']; ?></div></div>
				<div class="subtitle-small ext-box glyphicon glyphicon-search "><div class="int-box"><?php print $profile['field_looking_for']; ?></div></div>
		      	<div class="subtitle-small ext-box glyphicon glyphicon-home "><div class="int-box"><?php print $profile['field_living_location']; ?></div></div>
		      	<div class="subtitle-small ext-box glyphicon glyphicon-education "><div class="int-box"><?php print $profile['field_education']; ?></div></div>
				<div class="subtitle-small ext-box <?php echo strtolower($profile['field_gender']) == 'male' ? 'fa fa-male': 'fa fa-female';?> "><div class="int-box"><?php print $profile['field_gender']; ?></div></div>
		        <div class="subtitle-small ext-box fa fa-sort-numeric-desc "><div class="int-box"><?php print $profile['field_height']; ?></div></div>
		        
		        <!--label class="pull-right">
		            <a  class="btn btn-info  btn-xs glyphicon glyphicon glyphicon-comment"  title="Send message"></a>
		        </label-->
		        <div class="break"></div>
		  	</li>
		<?php } ?>
		</div>
		<!--li  class="list-group-item">
		    <a class="btn btn-block btn-primary" id="loadMore">
		        <i class="glyphicon glyphicon-refresh"></i>
		        Load more...
		    </a>
		</li-->
</ul>	
</div>