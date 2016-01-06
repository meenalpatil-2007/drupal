<?php
    
    drupal_add_css(base_path(). 'sites/all/themes/bootstrap/css/animate.css', array('group' => CSS_THEME, 'type' => 'external'));
    drupal_add_css(base_path(). 'sites/all/themes/bootstrap/css/signin.css', array('group' => CSS_THEME, 'type' => 'external'));

    $elements = drupal_get_form('user_login_block');

    /**
      do all your rendering stuff here
      drupal_render seems to add html to the elements array
      and instead of printing what is returned from drupal_render
      you can use the added html in ['#children'] elements of the arrays
      to build the form in the order you want.
    **/
    $rendered = drupal_render($elements);

    // to see what you have to work with
    //print "<pre>ELEMENTS: " . print_r($elements) . "</pre>";die;
    ?>
    <div class="col-md-12 text-center">
      <h1 class="title-big wow fadeIn"><i class="fa fa-sign-in"></i></h1>
      <h2 class="subtitle">Sign-in to access your account</h2>
      <form action="<?php  echo $elements['#action'] ?>" 
            method="<?php  echo $elements['#method'] ?>" 
            id    ="<?php  echo $elements['#id'] ?>" 
            role  ="form"
            class ="form-signin"
            accept-charset="UTF-8">                
   
        <div class="wow fadeInDown">
          <label for="inputUsername" class="sr-only"><?php echo $elements['name']['#title'] ?></label>
          <input class="form-control" placeholder="<?php echo $elements['name']['#title'] ?>" required="required" autofocus="autofocus" id="inputUsername" name="name" type="text">
        </div>

        <div class="wow fadeInDown" data-wow-delay=".7s">
          <label for="inputPassword" class="sr-only"><?php echo $elements['pass']['#title'] ?></label>
          <input class="form-control" placeholder="<?php echo $elements['pass']['#title'] ?>" required="required" id="inputPassword" name="pass" type="password" value="">
        </div>

        <button class="btn btn-lg btn-primary btn-block wow fadeInUp"  data-wow-delay="1s" id="signin" type="submit"><?php echo $elements['actions']['submit']['#value'] ?></button> 
      <?php echo $elements['form_build_id']['#children']; ?>
      <?php echo $elements['form_id']['#children'];?>
      <?php 
        $tmp = explode("<ul><li>", $elements['links']['#children']);
        $tmp1 = explode("</li>", $tmp[1]);
        //print '<div class="links wow fadeInUp btn btn-lg btn-primary btn-block" data-wow-delay="1.5s">'.  $tmp1[0].'</div>';
        print '<div class="links wow fadeInUp btn btn-lg btn-primary btn-block" data-wow-delay="1.5s">'.  $tmp1[1].'</div>';

        //echo '<div class="btn btn-lg btn-primary">'.$tmp[0].'</div>';
      ?>
    </form>
  </div>

<?php
  drupal_add_js('sites/all/themes/bootstrap/js/wow.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js('sites/all/themes/bootstrap/js/main.js', array('type' => 'file', 'scope' => 'footer'));
?>