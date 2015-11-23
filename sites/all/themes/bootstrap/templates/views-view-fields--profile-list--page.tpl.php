<?php //dpm($fields); ?>

<?php foreach ($fields as $id => $field): ?>
	<?php if (!empty($field->separator)): ?>
		<?php print $field->separator; ?>
	<?php endif; ?>

	<?php print $field->wrapper_prefix; ?>
	<?php print $field->label_html; ?>
	<?php print $field->content; ?>
	<?php print $field->wrapper_suffix; ?>


<?php endforeach; ?>
<br/><hr>

<?php
/*border-style: dashed;
border-width: 2px;*/