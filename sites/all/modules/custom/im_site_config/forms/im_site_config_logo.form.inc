<?php
 /*
  * @file
  * Form for the second logo
  */

 /**
  * Image form().
  */

 function im_site_config_logo_form($form, &$form_state){
  $form['image'] = array(
    '#title' => t('Image Logo'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    );
  $form['image']['im_image_logo'] = array(
    '#title' => t('Image:'),
    '#type' => 'managed_file',
    '#description' => t('Upload the image for the second logo'),
    '#default_value' => variable_get('im_image_logo', ''),
    '#upload_location' => 'public://uploads',
    );
  $form['image']['im_image_style'] = array(
    '#title' => t('Image Style'),
    '#type' => 'select',
    '#options' => im_get_image_styles(),
    '#default_value' => variable_get('im_image_style', 2),
    '#access' => user_access('administer site configuration'),
    '#description' => t('Select the image style for the second logo.'),
    );
  $form['image']['im_image_link'] = array(
    '#title' => t('Link for the second logo.'),
    '#type' => 'textfield',
    '#format' => 'full_html',
    '#description' => T('Here, you can write the link for the second logo.'),
    '#default_value' => variable_get('im_image_link'),
    );


  // Submit
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
    );  
  return $form;
}

function im_site_config_logo_form_submit($form, &$form_state){
  $image = variable_get('im_image_logo', '');
  // Image processing for the second logo.
  if ($form_state['values']['im_image_logo'] == 0){
    if ($image !== 0){
      $file = file_load($image);
      file_delete($file, TRUE);
    }
  }
  else {
    $file = file_load($form_state['values']['im_image_logo']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'im_site_config', 'module', $file->fid);
  }
  variable_set('im_image_logo', $form_state['values']['im_image_logo']);
  variable_set('im_image_style', $form_state['values']['im_image_style']);
  variable_set('im_image_link', $form_state['values']['im_image_link']);

  drupal_set_message(t('Changes saved'));
}

